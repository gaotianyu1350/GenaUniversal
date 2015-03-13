#include "Point.h"

using namespace std;

extern "C"
{
    class Point_Normal : public Point
    {
    public:
        Point_Normal(const bool *flag, qMs *queueMessage, FileGroup *fg)
            : Point(flag, queueMessage, fg)
        {
        }

        virtual void run()
        {

        }

        virtual void onStop()
        {
            Point::onStop();
        }
    };

    Point_Normal *get(const bool *flag, qMs *queueMessage, FileGroup *fg)
    {
        return new Point_Normal(flag, queueMessage, fg);
    }
}
