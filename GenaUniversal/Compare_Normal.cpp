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
            /*Setting *data = setting->getItem("data");
            Setting *_player = setting->getItem("player");
            map<string, Setting_data> &players = _player->getAllItems();
            Library lib("Player_Normal.dll");
            typedef Player *(*GET)(const bool*, qMs*, Setting*, Result*);
            GET getPlayer = (GET)lib.get("get");
            for (map<string, Setting_data>::iterator i = players.begin(); i != players.end(); ++i)
            {
                if (isStop())
                {
                    onStop();
                    return;
                }
                ((Setting*)(i->second))->setItem("data", data);
                Result *res = new Result(i->first);
                Player *player = getPlayer(flagStop, queueMessage, i->second, res);
                player->run();
                delete player;
                result->setItem(i->first, res);
            }
            pushMessage(0, "Contest judgement finished");*/
        }
        virtual void onStop()
        {
            Compare::onStop();
        }
    };
    Compare_Normal *get(const bool *flag, qMs *queueMessage, Setting *setting, Result *result)
    {
        return new Compare_Normal(flag, queueMessage, setting, result);
    }
}
