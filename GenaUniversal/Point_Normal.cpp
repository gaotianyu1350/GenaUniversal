#include "Point.h"

using namespace std;

extern "C"
{
    class Point_Normal : public Point
    {
        Point_Normal(const bool *flag, qMs* queueMessage, FileGroup *fg)
            : Point(flag, queueMessage, fg)
        {
        }

        ~Point_Normal()
        {
        }

        void run()
        {
            // Compile

            // Run

            // Compare

        }
    };
}
