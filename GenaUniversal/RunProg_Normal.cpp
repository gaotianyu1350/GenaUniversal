#include "RunProg.h"

extern "C"
{
    class RunProg_Normal : public RunProg
    {
    public:
        RunProg_Normal(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
            : Compare(flag, queueMessage, setting, result)
        {
        }

        virtual void run()
        {
            if (!setting->hasItem("exe"))
            {
                setResult(RunProg::RUNPROG_RES_NO_EXE);
                return;
            }

            std::string exe = setting->getItem("exe").operator std::string &();
            if (!FileManager::isfile(exe))
            {
                setResult(RunProg::RUNPROG_RES_NO_EXE);
                return;
            }

            Runner *runner = new Runner(flagStop);

            if (setting->hasItem("fin"))
            {
                fin = setting->getItem("fin").operator std::string &();
                runner->setFin(fin);
            }
            if (setting->hasItem("fout"))
            {
                fout = setting->getItem("fout").operator std::string &();
                runner->setFout(fout);
            }
            if (setting->hasItem("in"))
            {
                in = setting->getItem("in").operator std::string &();
                runner->setIn(in);
            }
            out = TempFile::GetTempFile();
            err = TempFile::GetTempFile();
            runner->setOut(out);
            runner->setErr(err);
            setResultFile();
            moveFile_Start();

            runner->run();
            if (runner->getStatus() == Runner::RUNNER_RES_KILL)
                onStop();
            moveFile_End();
            if (runner->getStatus() != Runner::RUNNER_RES_OK)
            {
                setResult(RunProg::RUNPROG_RES_FAIL);
                return;
            }
            setResult(RunProg`::RUNPROG_RES_OK, runner->timeUsed(), runner->memoryUsed(), runner->exitCode());
        }

        virtual void onStop()
        {
            setResult(RunProg::RUNPROG_RES_TER);
            moveFile_End();
            RunProg::onStop();
        }

    private:
        std::string fin, fout, tmpfin, tmpfout;
        std::string in, out, err;

        void moveFile_Start()
        {
            if (!fin.empty() && FileManager::isfile(fin))
            {
                tmpfin = TempFile::GetTempFile();
                FileManager::movefile(fin, tmpfin);
            }
            if (!fout.empty() && FileManager::isfile(fout))
            {
                tmpfout = TempFile::GetTempFile();
                FileManager::movefile(fout, tmpfout):
            }
        }

        void moveFile_End()
        {
            if (!tmpfin.empty() && FileManager::isfile(tmpfin))
            {
                FileManager::rmfile(fin);
                FileManager::movefile(tmpfin, fin);
            }
            if (!tmpfout.empty() && FileManager::isfile(tmpfout))
            {
                FileManager::rmfile(fout);
                FileManager::movefile(tmpfout, fout);
            }
        }

        void setResult(int res, int time = 0, int memory = 0, int exitcode = 0)
        {
            result.setItem("result", res);
            result.setItem("time", time);
            result.setItem("memory", memory);
            result.setItem("exitcode", exitcode);
        }

        void setResultFile()
        {
            result.setItem("in", in);
            result.setItem("err", err);
        }

    };

    RunProg_Normal *get(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
    {
        return new RunProg_Normal(flag, queueMessage, setting, result);
    }
}

