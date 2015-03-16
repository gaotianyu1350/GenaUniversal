#include "Compare.h"

using namespace std;

extern "C"
{
    class Compare_Float : public Compare
    {
    public:
        Compare_Float()
        {
            eps = 1e-6;
        }
        Compare_Float(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
            : Compare(flag, queueMessage, setting, result)
        {
        }
        void setFile(const string _OutFile, const string _AnsFile)
        {
            AnsFile = _AnsFile;
            OutFile = _OutFile;
        }
        void setEps(double _eps)
        {
            eps = _eps;
        }
        int dcmp(double x)
        {
            return (x > eps) - (x < eps);
        }
        virtual void run()
        {
            ifstream fans(AnsFile.c_str());
            ifstream fout(OutFile.c_str());
            string tmpstr;
            double tmpdb;
            vector<string>vecans, vecout;
            if (fans == 0)
            {
                pushMessage(1, "Can not open answer file");
                return ;
            }
            if (fout == 0)
            {
                pushMessage(1, "Can not open output file");
                return ;
            }
            result->setItem("compare", "Accepted");
            while (getline(fans, tmpstr))
            {
                vecans.push_back(tmpstr);
            }
            while (getline(fout, tmpstr))
            {
                vecout.push_back(tmpstr);
            }
            if (vecans.size() > vecout.size())
            {
                sprintf(str, "Wrong_Answer at %d", int(vecout.size()));
                result->setItem("compare", str);
            }
            else if (vecans.size() < vecout.size())
            {
                sprintf(str, "Wrong_Answer at %d", int(vecans.size()));
                result->setItem("compare", str);
            }
            else
            {
                vecans.clear();
                vecout.clear();
                fans.close();
                fout.close();
                fans.clear();
                fout.clear();
                fout.open(OutFile.c_str());
                fans.open(AnsFile.c_str());
                while (fans >> tmpdb)
                {
                    vecans.push_back(tmpdb);
                }
                while (fout >> tmpdb)
                {
                    vecout.push_back(tmpdb);
                }
                if (vecans.size() == vecout.size())
                {
                    for (int i = 0; i < vecans.size(); i++)
                    {
                        if (dcmp(vecans[i] - vecout[i]))
                        {
                            sprintf(str, "Wrong_Answer at %d", i + 1);
                            result->setItem("compare", str);
                        }
                    }
                }
                else
                {
                    sprintf(str, "Wrong_Answer at %d", int(vecans.size()));
                    result->setItem("compare", str);
                }
            }
            pushMessage(0, "Compare finished");
        }
        virtual void onStop()
        {
            Compare::onStop();
        }
    private:
        double eps;
        char str[10];
    };
    Compare_Float *get(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
    {
        return new Compare_Float(flag, queueMessage, setting, result);
    }
}
