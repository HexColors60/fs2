//check.c
#include <ansi.h>
inherit SSERVER;
int perform(object me,object target)
{
        string msg,opp;
        int a,b;
        if(!target) target=offensive_target(me);
        if((!target)
        ||(target==me)
        ||(!target->is_character())
        ||(target->is_corpse()))
                return notify_fail("探脉指只可用在其他人身上。\n");
        if (((string)me->query("class")!="healer")&&(me->query("force")<20))
                return notify_fail("你内力不足，无法使用探脉指。\n");
        if ((string)me->query("class")!="healer") me->add("force",-20);
        message_vision(HIC"$N的手如风般快速地按在$n的脉门上 ....\n"NOR,me,target);
        me->start_busy(1);
        if ((random(target->query("bellicosity"))>1200)&&(!environment(target)->query("no_fight"))) {
                tell_object(target,"你发现"+me->name()+"捉着你的手腕，你火气爆涨！相当忿怒！\n");
                message_vision("$N叫道：你干么捉着我？我看你是活得不耐烦了！！\n",target);
                target->kill_ob(me);
        }
        opp=target->name();
        write("\n");
        if(random(10)>2) {
                if (target->query("combat_exp") > me->query("combat_exp")*10)
                msg=HIR"你触到"+opp+"的身体时，感到了一份前所未有的恐惧 ....\n"NOR;
                else if (target->query("combat_exp") > me->query("combat_exp")*5)
                msg=HIM""+opp+"的力量比你强许多 ....\n"NOR;
                else if (target->query("combat_exp")> me->query("combat_exp")*3/2)
                msg=HIG""+opp+"的力量比你强些许儿 ....\n"NOR;
                else if(target->query("combat_exp")>me->query("combat_exp")*2/3)
                msg=HIY""+opp+"的斗气跟你相当的接近 ....\n"NOR;
                else if(target->query("combat_exp")>me->query("combat_exp")/5)
                msg=HIB""+opp+"力量根本比不上你 ....\n"NOR;
                else if(target->query("combat_exp")>me->query("combat_exp")/10)
                msg=MAG"你差不多感觉不到"+opp+"的力量 ....\n"NOR;
                else msg=CYN"你根本感觉不到"+opp+"有任何的战斗力 ....\n"NOR;
                if (target->query("max_force")>me->query("max_force")*3/2) {
                        msg+=HIB""+opp+"的内力看来比你高，";
                        if (target->query("force")>target->query("max_force")/2)
                        msg+="而且内力很充沛！\n"NOR;
                        else msg+="但内力有一点不足 ....\n"NOR;
                }
                else if (target->query("max_force")>me->query("max_force")/2) {
                        msg+=HIB"你的内力跟对方不相伯仲，";
                        if (target->query("force")>target->query("max_force")/2)
                        msg+="但对方胜在内力充裕！\n"NOR;
                        else msg+="但"+opp+"的内力好像不太足够 ....\n"NOR;
                }
                else {
                        msg+=HIB"你的内力比"+opp+"强，";
                        if (target->query("force")>target->query("max_force")/2)
                        msg+="但对方充足的内力真的不容轻视！\n"NOR;
                        else msg+="而且"+opp+"的内力严重不足 ....\n"NOR;
                }
        write(msg);
        if (userp(target)) {
        a=(int)(target->query("learned_points")*(target->query("int")-1)
                +target->query("combat_exp"));
        b=(int)(me->query("learned_points")*(me->query("int")-1)
                +me->query("combat_exp"));
        if (a>b*3/2) write("从"+opp+"血脉的流动，你感到自己的技术比不上"+opp+" ....\n");
        else if (a>b/2) write(opp+"的气息告诉你 - 你和"+opp+"的技俩其实相差不了多少 ....\n");
        else write ("你从对方的脉象看得出，"+opp+"的技术根本比不上你的 ....\n");
        }
        write("\n");
        return 1;
        }
        write("你的指劲点往"+opp+"的身上，却触不到穴道所在，无法使用探脉指 ....\n");
        return 1;
}
