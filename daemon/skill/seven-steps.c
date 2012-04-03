// change bye adam..
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        
"\n$n使出‘"HIW"蛇行诀"NOR"’身行一晃，如蛇行般轻灵，滑过$N的身旁，躲过了$N的攻击！\n",
        
"\n$n使出‘"HIG"鹤冲天"NOR"’身形如鹤，飞身冲上云端，轻易的闪过$N的攻击！\n",
        
"\n$n施展‘"HIM"鹰凌霄"NOR"’$n好比飞鹰，绕着$N身子左盘又旋，兜圈急转，趁隙发招！\n",
        
"\n$n施展‘"HIY"凤蝶舞"NOR"’把$N的攻势，借劲一送，结果$N的攻势如沈入大海一般！\n",
        
"\n$n施展‘"HIB"龙吟行"NOR"’气运单田，发出龙吟气功护体，把$N的攻势，轻易瓦解！\n",
        
"\n$n施展‘"HIR"麟踪火"NOR"’只见$n全身如火焚身般，如火麒麟附体，大显神威，$N的攻势完全无用！\n",
        
"\n$n施展‘"HIC"虎跃冲"NOR"’$n有如猛虎一般凶猛，动作灵活，结果把$N的攻势，视若无睹！\n",
});

int valid_enable(string usage) {
        return (usage=="dodge")||(usage=="move");

}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if((int)me->query("kee")<5)
                return notify_fail("你的气不够，不能练七灵驭风诀 。\n");
        me->receive_wound("kee",5);
        return 1;
}