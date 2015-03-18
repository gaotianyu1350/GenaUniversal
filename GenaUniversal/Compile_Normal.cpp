#include "Compile.h"

extern "C"
{
    class Compile_Normal : public Compile
    {
    public:
        Compile_Normal(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
            : Compile(flag, queueMessage, setting, result)
        {
        }

        virtual void run()
        {

        }

        virtual void onStop()
        {
            Compile::onStop();
        }

    private:

    };
}
