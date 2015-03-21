#ifndef RUNCOMPILE_H
#define RUNCOMPILE_H

#include "Runner.h"
#include "TempFile.h"
#include <string>
#include <iostream>
#include <fstream>

class RunCmd
{
public:
    RunCmd(const bool *flag);
    ~RunCmd();
    void setCommand(const std::vector<std::string> &command);
    void addArg(const std::string &arg);
    void run();
    void getOutput(std::string &output);
    int getExitCode();
    int getStatus();

private:
    const bool *flag;
    Runner *runner;
    std::string strOutFile, strErrFile;
};

#endif // RUNCOMPILE_H
