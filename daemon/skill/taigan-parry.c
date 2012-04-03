//不死印法 by bss
#include <ansi.h>
inherit SKILL;

string *parry_msg =
({

        "\n"HIY"$n体内的阴阳二气快速运转，正正反反，反反正正，将$N攻击的内劲化为己用。"NOR"\n",

        "\n"HIR"面对$N强大的攻势，$n强运不死印法，将$N那强大的内劲硬是传到了身后的地上，使地上留下了一个足足有尺余的脚印。"NOR"\n",

        "\n"MAG"$n双手平推而出，阴阳劲气一吐，再身前形成一道气墙，将$N猛烈的攻势抵消掉了。"NOR"\n",

});

int valid_enable(string usage) {
int family;
object me=this_player();
if ( me->query("family/family_name") != "东厂")
        return (usage=="parry");
else
 return notify_fail("只有东厂太监才能用不死印法!!\n");

}

string query_parry_msg(string limb){

        return parry_msg[random(sizeof(parry_msg))];
}


int valid_learn(object me)
{
        int level,skill;
        level=me->query("taigan_level",1);
        skill=me->query_skill("taigan-parry",1);
        if(me->query("class")!="taigan"){
                return notify_fail("只有太监能学不死印法");
                return 0;
                }
         if(me->query_skill("taiyiforce",1) < 60)
         {
         write("你的太乙罡\气不够纯熟..无法学习不死印法\n");
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








