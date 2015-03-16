#include "Compare.h"

using namespace std;

extern "C"
{
    class Compare_Normal : public Compare
    {
    public:
        Compare_Normal(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
            : Compare(flag, queueMessage, setting, result)
        {
        }
        virtual void run()
        {
            AnsFile = setting->getItem("AnsFile").operator string();
            OutFile = setting->getItem("OutFile").operator string();
            ifstream fans(AnsFile.c_str());
            ifstream fout(OutFile.c_str());
            string tmpstr;
            int WA = 0;
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
                WA = 1;
            }
            else if (vecans.size() < vecout.size())
            {
                sprintf(str, "Wrong_Answer at %d", int(vecans.size()));
                result->setItem("compare", str);
                WA = 1;
            }
            else
            {
                for (int i = 0 ; i < vecout.size() ; i++)
                {
                    if (vecans[i] != vecout[i])
                    {
                        sprintf(str, "Wrong_Answer at %d", i + 1);
                        result->setItem("compare", str);
                        WA = 1;
                        break;
                    }
                }
            }
            vecans.clear();
            vecout.clear();
            fans.close();
            fout.close();
            fans.clear();
            fout.clear();
            fout.open(OutFile.c_str());
            fans.open(AnsFile.c_str());
            while (fans >> tmpstr)
            {
                vecans.push_back(tmpstr);
            }
            while (fout >> tmpstr)
            {
                vecout.push_back(tmpstr);
            }
            if (vecans == vecout && WA)
            {
                result->setItem("compare", "Presentation_Error");
            }
            pushMessage(0, "Compare finished");
        }
        virtual void onStop()
        {
            Compare::onStop();
        }
    private:
        string AnsFile, OutFile;
        char str[10];
    };
    Compare_Normal *get(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
    {
        return new Compare_Normal(flag, queueMessage, setting, result);
    }
}
