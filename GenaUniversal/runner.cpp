/***************************************************************
 * Name:      runner.h
 * Purpose:   Code for runner class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#include "runner.h"
#include <cstdlib>
#include <stdexcept>
#include "TempFile.h"

runner::runner(const std::string &in, const std::string &out, const std::string &err, unsigned time, unsigned memory)
{
    this->in = in;
    this->out = out;
    this->err = err;
    this->time = time;
    this->memory = memory;
    this->fin = "!";
    this->fout = "!";
}
void runner::setFin(const std::string &fin)
{
    this->fin = fin;
}
void runner::setFout(const std::string &fout)
{
    this->fin = fin;
}
void runner::setCommand(const std::vector<std::string> &cmd)
{
    this->cmd = cmd;
}
void runner::addCommand(const std::string &cmd)
{
    this->cmd.push_back(cmd);
}
void runner::run()
{
    static int cnt = 0;
    if (++cnt > 1)
        throw std::logic_error("runner can just run one time");
    char tmp[100];
    std::string str;
#ifdef WIN32
    str += "runner\\runner_win.exe"
#else
    str += "runner/runner_linux"
#endif
    sprintf(tmp, " %u", cmd.size()), str += tmp;
    for (std::vector<std::string>::iterator i = cmd.begin(); i != cmd.end(); ++i)
        str += " " + *i;
    str += " " + fin;
    str += " " + fout;
    str += " " + in;
    str += " " + out;
    str += " " + err;
    sprintf(tmp, " %u", time), str += tmp;
    sprintf(tmp, " %u", memory), str += tmp;
    std::string stop = TempFile::GetTempFile("", ".stop");
    std::string log = TempFile::GetTempFile("", ".log");
    str += " " + stop;
    str += " " + log;
    system(str.c_str());
}
