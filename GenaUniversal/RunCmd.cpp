#include "RunCmd.h"

RunCmd::RunCmd(const bool *flag)
{
    this->flag = flag;
    runner = new Runner(flag);
}

void RunCmd::setCommand(const std::vector<std::string> &command)
{

}

void RunCmd::addArg(const std::string &arg)
{

}

void RunCmd::run()
{

}

void RunCmd::getOutput(std::string &output)
{

}
