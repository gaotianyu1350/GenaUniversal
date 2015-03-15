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
            /*FileGroup *src = fg->getFileGroup("source");
            FileGroup *data = fg->getFileGroup("data");
            map<string, FileGroup*> &sgroup = src->getAllFileGroup();
            map<string, FileGroup*> &dgroup = data->getAllFileGroup();
            int score = 0;
            for (map<string, FileGroup*>::iterator i = dgroup.begin(); i != dgroup.end(); ++i)
            {
                if (isStop())
                {
                    onStop();
                    return;
                }
                FileGroup fgForProblem(i->first);
                Library lib("Problem_Normal.dll");
                typedef Problem *(*GET)(const bool *flag, qMs *queueMessage, const FileGroup *fg);
                GET getProblem = (GET)lib.get("get");
                fgForProblem.addFileGroup("source", sgroup[i->first]);
                fgForProblem.addFileGroup("data", i->second);
                Problem *problem = getProblem(flagStop, queueMessage, &fgForProblem);
                problem->run();
                mapRow &pinfo = problem->getInfo();
                addInfo(i->first, pinfo["score"]);
                score += pinfo["score"].first;
            }
            addInfo("score", infoPair(score, ""));
            char tmp[30];
            sprintf(tmp, "%d", score);
            pushMessage(0, fg->getStrName() + " total score " + tmp);*/
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
