#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
int exert(object me, object target)
{
        int fun,damage,i;
        object *enemy;
        if(!wizardp(me) && userp(me)) return 0;
        if(me->query_temp("using_threeforce"))
                return notify_fail("敌人正因你的气劲而行动迟缓，快趁现在攻击吧!!!\n");
        fun=me->query("functions/threeforce/level");
        if(!fun) fun=1;
        damage=fun*80;
        if(!me->is_fighting()) return notify_fail("战斗中才可以使出「叠浪三重”!!\n");
        enemy=me->query_enemy();
        target=enemy[random(sizeof(enemy))];
       if(!target) return notify_fail("找不到敌人!!\n");
        if(userp(target)) damage/=2;
        me->set_temp("using_threeforce",1);
        message_vision(HIG"
只听$N"HIG"狂喝一声，在$N"HIG"与$n"HIG"接触之时，体内三气分作三重，化成滔天巨浪，刹那间
三波真气全送入了$n"HIG"的体内!!!
「轰!”一声劲气交接的巨响，两人同时被震退!!\n"NOR,me,target);
        message_vision(HIR"
可是$N"HIR"在退到一半的时候突然全身剧震，经脉受到了$n"HIR"第一重真气的影响，
全身经脉如同被一股巨力重锤，劲力登时丧失了许多!!!\n"NOR,target,me);
        target->add_temp("apply/damage",-(target->query_temp("apply/damage")/2));
        target->add_temp("apply/attack",-(target->query_temp("apply/attack")/2));
        target->add("force",-(target->query("force")/5));
        target->receive_wound("kee",damage,me);
        target->set_temp("no_power",1);
        target->apply_condition("no_power",3);
        COMBAT_D->report_status(target);
        call_out("action1",3,me,target,damage);
        return 1;
}
int action1(object me,object target,int damage)
{
        if(target)
        {
        if(target->is_fighting())
        {
        message_vision(HIB"
就在$N"HIB"以为摆\拖了$n"HIB"的真气攻击时，$n"HIB"的第二波真气开始发挥作用，阴渺难测的真气
开始在$N"HIB"的体内乱窜，$N"HIB"全身经脉就如同被扭在一起，身体的灵活度登时变差了许多!!\n"NOR,target,me);
        target->add_temp("apply/defense",-(target->query_temp("apply/defense")/2));
        target->add_temp("apply/armor",-(target->query_temp("apply/armor")/2));
        target->add("force",-(target->query("force")/4));
        target->receive_wound("gin",damage,me);
        COMBAT_D->report_status(target);
        call_out("action2",3,me,target,damage);
        }
        else
        {
        call_out("add_fun",2,me);
        }
        }
        else
        {
        call_out("add_fun",2,me);
        }
        return 1;
}
int action2(object me,object target,int damage)
{
        if(target)
        {
        if(target->is_fighting())
        {
        message_vision(HIM"
正当$N"HIM"凭藉着本身真气将$n"HIM"第二重真气引入地上时，$n"HIM"的第三重真气却已经全无预兆的
侵入到$N"HIM"的精神之中，$N"HIM"登时整个人飘飘荡荡，说不出的心颤魂摇，难受得要命，大脑
似若不再听$N"HIM"的指挥，斗志大减!!\n"NOR,target,me);
        target->set_temp("apply/damage",1);
        target->set_temp("apply/attack",1);
        target->add("force",-(target->query("force")/3));
        target->receive_wound("sen",damage,me);
        COMBAT_D->report_status(target);
        call_out("add_fun",2,me);
        }
        else
        {
        call_out("add_fun",2,me);
        }
        }
        else
        {
        call_out("add_fun",2,me);
        }
        return 1;
}
int add_fun(object me)
{
        int fun;
        if(!me) return 1;
        me->delete_temp("using_threeforce");
        fun=me->query("functions/threeforce/level");
        if(!userp(me)) return 1;
        if(fun<100)
                function_improved("threeforce",random(2000));
}
