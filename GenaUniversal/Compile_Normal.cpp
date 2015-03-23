#include "Compile.h"
#include "RunCmd.h"

extern "C"
{
    class Compile_Normal : public Compile
    {
    public:
        Compile_Normal(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
            : Compile(flag, queueMessage, setting, result)
        {
        }

        virtual void run()
        {
            if (!setting->hasItem("code"))
            {
                setResult(Compile::COMPILE_RES_NO_CODE, "Hasn't set the code. ");
                return;
            }

            std::string code = setting->getItem("code").operator std::string &();
            if (!FileManager::isfile(code))
            {
                setResult(Compile::COMPILE_RES_NO_CODE, "There is no code. ");
                return;
            }

            std::string ext = FileManager::getext(code);
            for (std::string::iterator p = ext.begin(); p != ext.end(); p++)
                if ('A' <= *p && *p <= 'Z')
                    *p = *p - 'A' + 'a';

            if (!setting->hasItem("compilesetting"))
            {
                setResult(Compile::COMPILE_RES_NO_COMPILER, "There is no compiler for the code. ");
                return;
            }
            Setting *cmpSet = setting->getItem("compilesetting");
            if (!cmpSet->hasItem(ext))
            {
                setResult(Compile::COMPILE_RES_NO_COMPILER, "There is no compiler for the code. ");
                return;
            }

            std::string spSource("${src}");
            std::string spExe("${exe}");
            std::string strCmd = cmpSet->getItem(ext);
            std::string exe = TempFile::GetTempFile();
            std::size_t found;

            while ((found = strCmd.find(spSource)) != std::string::npos)
                strCmd.replace(found, spSource.size(), "\"" + code + "\"");
            while ((found = strCmd.find(spExe)) != std::string::npos)
                strCmd.replace(found, spExe.size(), "\"" + exe + "\"");

            RunCmd *cmdrunner = new RunCmd(flagStop);
            std::string tmp("");
            bool inquote = false;
            for (std::string::iterator p = strCmd.begin(); p != strCmd.end(); p++)
            {
                switch (*p)
                {
                case '\"':
                    inquote = !inquote;
                    break;
                case ' ':
                    if (inquote)
                        tmp += ' ';
                    else
                    {
                        if (tmp.empty())
                            break;
                        cmdrunner->addArg(tmp);
                        tmp = "";
                    }
                    break;
                default:
                    tmp += *p;
                }
            }
            if (!tmp.empty())
                cmdrunner->addArg(tmp);

            cmdrunner->run();

            if (cmdrunner->getStatus() == Runner::RUNNER_RES_KILL)
                onStop();

            cmdrunner->getOutput(tmp);
            if (cmdrunner->getExitCode())
                setResult(Compile::COMPILE_RES_CE, "Compile error. \n" + tmp);
            else
                setResult(Compile::COMPILE_RES_OK, "Compile success. \n" +tmp);
        }

        virtual void onStop()
        {
            setResult(Compile::COMPILE_RES_TER, "Terminate. ");
            Compile::onStop();
        }

    private:
        void setResult(int resultCode, const std::string &detail)
        {
            result->setItem("result", resultCode);
            result->setItem("detail", detail);
        }
    };

    Compile_Normal *get(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
    {
        return new Compile_Normal(flag, queueMessage, setting, result);
    }
}
