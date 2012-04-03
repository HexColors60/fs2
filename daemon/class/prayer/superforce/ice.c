#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;
int skill;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
skill=this_player()->query("functions/ice/level");
        if(userp(me))
        return notify_fail("请改用 mixforce。\n");
        if( (string)me->query_skill_mapped("force")!= "superforce")
         return notify_fail("碧雪冰必须使用浑天心法才能发挥威力。\n");
        if( target != me ) return notify_fail("你只能用浑天心法提升内力威力。\n");
        if (me->query_skill("superforce",1) < 50)
            return notify_fail("你的浑天心法等级不足，须要 50 级。\n");
        if (me->query("force") < skill*5)
            return notify_fail("你的内力不够，无法领悟碧雪冰的浑天内劲。\n");
        if( (int)me->query("max_force") < 600 )
        return notify_fail("你的内力根基不足,无法完全发挥出碧雪冰雄浑的内劲。\n");

        if(me->query_temp("ice")) return notify_fail("你已经在用了。\n");
        if(me->query_temp("purple")) return notify_fail("你已经在运行[32m紫星河心法[0m了。\n");
        if(me->query_temp("white")) return notify_fail("你已经在运行[37m白云烟心法[0m了。\n");
        if(me->query_temp("nine")) return notify_fail("你已经在使用[35m玫荡霞心法[0m了。\n");
        if(me->query_temp("gen")) return notify_fail("你已经在使用[35m土昆仑心法[0m了。\n");
        if(me->query_temp("black")) return notify_fail("你已经在运行[30m玄混沌[0m了。\n");
        if(me->query_temp("bluesea")) return notify_fail("你已经在催运[34m靛沧海[0m内劲了。\n");
        if(me->query_temp("goldsun")) return notify_fail("你已经在强运[33m金晨曦[0m内劲了。\n");
        if(me->query_temp("blood")) return notify_fail("你已经在催鼓[31m血穹苍[0m内劲了。\n");
        if(me->query_temp("green")) return notify_fail("你已经在运行[32m玄宇宙[0m内劲了。\n");

        me->set_temp("ice",1);
        message_vision(
HIC "$N运起浑天心法第四层的"HIW"碧雪冰"HIC"，身上发出如寒霜般的寒劲,四周的空气似乎也为之冻结!!\n" NOR,me);

        me->add_temp("apply/force", 5);
        me->add_temp("apply/move", 5);
        me->add_temp("apply/stick", 5);
        me->add_temp("apply/parry", 5);
        me->add_temp("apply/dodge", 5);
        me->add_temp("apply/unarmed", 5);
        call_out("remove_effect", skill, me);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->set_temp("ice",0);
        me->add_temp("apply/force", -5);
        me->add_temp("apply/move", -5);
        me->add_temp("apply/stick", -5);
        me->add_temp("apply/parry", -5);
        me->add_temp("apply/dodge", -5);
        me->add_temp("apply/unarmed", -5);
        tell_object(me,"你身上的碧雪冰气劲慢慢的消退中,四周寒意也随之降低。\n");
        if(skill < 50)
        function_improved("ice",random(700));
}
