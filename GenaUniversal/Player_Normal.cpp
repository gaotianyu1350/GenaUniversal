#include "Player.h"

using namespace std;

extern "C"
{
    class Player_Normal : public Player
    {
    public:
        Player_Normal(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
            : Player(flag, queueMessage, setting, result)
        {
        }

        virtual void run()
        {
            Setting *source = setting->getItem("source");
            Setting *data = setting->getItem("data");
            map<string, Setting_data> probs = source->getAllItems();
            Result *result_concrete;
            result->setItem("concrete", result_concrete);
            int total = 0;
            for (map<string, Setting_data>::iterator i = probs.begin(); i != probs.end(); ++i)
            {
                if (isStop())
                {
                    onStop();
                    return;
                }
                Library lib(data->getItem("Problem module"));
                typedef Problem *(*GET)(const bool*, qMs*, Setting*, Result*);
                GET getProb = (GET)lib.get("get");
                ((Setting*)(i->second))->setItem("data", data->getItem(i->first));
                Result *res = new Result(i->first);
                Problem *prob = getProb(flagStop, queueMessage, i->second, res);
                prob->run();
                delete prob;
                result_concrete->setItem(i->first, res);
                total += res->getItem("total");
            }
            result->setItem("total", total);
            char tmp[30];
            sprintf(tmp, "%d", total);
            pushMessage(0, setting->getName() + " total score " + tmp);
        }

        virtual void onStop()
        {
            Player::onStop();
        }
    };

    Player_Normal *get(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
    {
        return new Player_Normal(flag, queueMessage, setting, result);
    }
}
