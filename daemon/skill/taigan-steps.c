//阴阳步法 by bss
#include <ansi.h>
#include <combat.h>
inherit SKILL;

string *dodge_msg = ({

        "\n"HIC"$n脚踩奇步，忽左忽右，有如游鱼般绕到了$N的身后，使$N的攻势落空。"NOR"\n",

        "\n"HIC"$n的脚下忽然加快，忽地一闪，竟然从$N的眼前消失，让$N不知所措。"NOR"\n",

        "\n"HIC"$n的身体伏低，双脚离地，身形急转，如一道旋风般从$N身旁窜过，躲过了\n$N的必杀招式。"NOR"\n",

        "\n"HIC"$n单脚站立，身体随风前后左右摆\动，恰好的躲过了$N的招式。"NOR"\n",

        "\n"HIC"$n的身体不断的转圈，在狭小的空间中快速的移动，使$N找不到$n的确实位\n置，招式落空。"NOR"\n",

});



int valid_enable(string usage) {
        return (usage=="dodge")||(usage=="move");

}

int valid_learn(object me)
{
        int level,skill;
        level=me->query("taigan_level",1);
        skill=me->query_skill("taigan-steps",1);
        if(me->query("class")!="taigan"){
                return notify_fail("只有太监能学阴阳步法");
                return 0;
                }
        switch(level){
                case 5:
                        return 1;
                        break;
                case 6:
                        if(skill>80){
                                return notify_fail("你的官品不够，无法学习更高深的武技。\n");
                                return 0;
                                break;
                                }
                        return 1;
                        break;
                case 7:
                        if(skill>60){
                                return notify_fail("你的官品不够，无法学习更高深的武技。\n");
                                return 0;
                                break;
                                }
                        return 1;
                        break;
                case 8:
                        if(skill>40){
                                return notify_fail("你的官品不够，无法学习更高深的武技。\n");
                                return 0;
                                break;
                                }
                        return 1;
                        break;
                case 9:
                        if(skill>20){
                                return notify_fail("你的官品不够，无法学习更高深的武技。\n");
                                return 0;
                                break;
                                }
                        return 1;
                        break;
                default:
                        write("你不是太监，无法学习此项武技。\n");
                        return 0;
                        break;
  }
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if((int)me->query("kee")<5)
                return notify_fail("你的气不够，不能练阴阳步法。\n");
        me->receive_wound("kee",5);
        return 1;
}

