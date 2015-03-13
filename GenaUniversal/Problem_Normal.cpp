#include "Problem.h"

using namespace std;

extern "C"
{
    class Problem_Normal : public Problem
    {
    public:
        Problem_Normal(const bool *flag, qMs *queueMessage, FileGroup *fg)
            : Problem(flag, queueMessage, fg)
        {
        }

        virtual void run()
        {

        }

        virtual void onStop()
        {
            Problem::onStop();
        }
    };

    Problem_Normal *get(const bool *flag, qMs *queueMessage, FileGroup *fg)
    {
        return new Problem_Normal(flag, queueMessage, fg);
    }
}
