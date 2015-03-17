#ifndef RUNCOMPILE_H
#define RUNCOMPILE_H

#include "Runner.h"
#include <string>
#include <iostream>

class RunCmd
{
public:
    RunCmd(const bool *flag);
    void setCommand(const std::vector<std::string> &command);
    void addArg(const std::string &arg);
    void run();
    void getOutput(std::string &output);

private:
    const bool *flag;
    Runner *runner;
    std::string strOutFile;

    bool isStop();
    void onStop();
};

#endif // RUNCOMPILE_H
