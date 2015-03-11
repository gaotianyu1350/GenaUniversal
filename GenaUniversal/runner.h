/***************************************************************
 * Name:      runner.h
 * Purpose:   Defines runner class
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#ifndef RUNNER_H
#define RUNNER_H

#include <string>
#include <vector>

class runner
{
private:
    std::string in, out, err; /* need in/out/err */
    unsigned time, memory; /* time(ms) memory(kb) */
    std::vector<std::string> cmd;
    std::string fin, fout; /* command use in/out */
public:
    runner(const std::string &in, const std::string &out, const std::string &err, unsigned time, unsigned memory);
    void setFin(const std::string &fin);
    void setFout(const std::string &fout);
    void setCommand(const std::vector<std::string> &cmd);
    void addCommand(const std::string &cmd);
    void run();
    //
};

#endif // RUNNER_H
