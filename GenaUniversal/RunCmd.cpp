#include "RunCmd.h"

RunCmd::RunCmd(const bool *flag)
{
    this->flag = flag;
    runner = new Runner(flag);
}

void RunCmd::setCommand(const std::vector<std::string> &command)
{
    runner->setCommand(command);
}

void RunCmd::addArg(const std::string &arg)
{
    runner->addArg(arg);
}

void RunCmd::run()
{
    strOutFile = TempFile::GetTempFile();
    strErrFile = TempFile::GetTempFile();
    runner->setOut(strOutFile);
    runner->setErr(strErrFile);

    runner->run();
}

void RunCmd::getOutput(std::string &output)
{
    std::ifstream fOut(strOutFile.c_str());
    std::ifstream fErr(strErrFile.c_str());
    std::string resOut, resErr;

    std::getline(fOut, resOut, (char)-1);
    std::getline(fErr, resErr, (char)-1);
    output = resOut + resErr;
}

int RunCmd::getExitCode()
{
    return runner->exitCode();
}

RunCmd::~RunCmd()
{
    delete runner;
}
