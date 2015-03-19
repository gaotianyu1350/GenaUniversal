#include "Compile.h"

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


            RunCmd *cmdrunner = new RunCmd(flagStop);


        }

        virtual void onStop()
        {
            Compile::onStop();
        }

    private:
        void setResult(int resultCode, const std::string &detail)
        {
            result->setItem("result", resultCode);
            result->setItem("detail", detail);
        }
    };
}
