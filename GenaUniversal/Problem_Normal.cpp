#include "Problem.h"

using namespace std;

extern "C"
{
    class Problem_Normal : public Problem
    {
    public:
        Problem_Normal(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
            : Problem(flag, queueMessage, setting, result)
        {
        }

        virtual void run()
        {
            //Compile
        }

        virtual void onStop()
        {
            Problem::onStop();
        }
    };

    Problem_Normal *get(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
    {
        return new Problem_Normal(flag, queueMessage, setting, result);
    }
}
