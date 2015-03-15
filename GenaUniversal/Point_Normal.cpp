#include "Point.h"

using namespace std;

extern "C"
{
    class Point_Normal : public Point
    {
    public:
        Point_Normal(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
            : Point(flag, queueMessage, setting, result)
        {
        }

        virtual void onStop()
        {
            Point::onStop();
        }

		Point_Normal *get(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
		{
			return new Point_Normal(flag, queueMessage, setting, result);
		}

        virtual void run()
        {
            // Run

            // Compare

        }
    };

}
