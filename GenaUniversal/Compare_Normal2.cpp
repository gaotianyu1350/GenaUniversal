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
            string file1, file2;
            char c;
            while (fans.get(c))
                file1.push_back(c);
            while (fout.get(c))
                file2.push_back(c);
            if(file1!=file2)
                result->setItem("compare", "Wrong_Answer at 0");
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

