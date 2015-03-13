#include "Contest.h"

using namespace std;

extern "C"
{
    class Contest_Normal : public Contest
    {
    public:
        Contest_Normal(const bool *flag, qMs *queueMessage, FileGroup *fg)
            : Contest(flag, queueMessage, fg)
        {
        }
        virtual void run()
        {
            FileGroup *players = fg->getFileGroup("player");
            FileGroup *data = fg->getFileGroup("data");
            map<string, FileGroup*> &pgroup = players->getAllFileGroup();
            map<string, FileGroup*> &dgroup = data->getAllFileGroup();
            addTitle("name");
            addTitle("score");
            for (map<string, FileGroup*>::iterator i = dgroup.begin(); i != dgroup.end(); ++i)
                addTitle(i->first);
            for (map<string, FileGroup*>::iterator i = pgroup.begin(); i != pgroup.end(); ++i)
            {
                FileGroup fgForPlayer(i->first), src("source");
                for (map<string, FileGroup*>::iterator i = dgroup.begin(); i != dgroup.end(); ++i)
                {
                    if (isStop())
                    {
                        onStop();
                        return;
                    }
                    src.addFileGroup(i->first, i->second);
                }
                Library lib("Player_Normal.dll");
                typedef Player *(*GET)(const bool *flag, qMs *queueMessage, const FileGroup *fg);
                GET getPlayer = (GET)lib.get("get");
                fgForPlayer.addFileGroup("source", &src);
                fgForPlayer.addFileGroup("data", data);
                Player *player = getPlayer(flagStop, queueMessage, &fgForPlayer);
                player->run();
                addInfo(player->getInfo());
            }
            pushMessage(0, "Contest judgement finished");
        }
        virtual void onStop()
        {
            Contest::onStop();
        }
    };
    Contest_Normal *get(const bool *flag, qMs *queueMessage, FileGroup *fg)
    {
        return new Contest_Normal(flag, queueMessage, fg);
    }
}
