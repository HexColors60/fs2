#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
int perform(object me, object target)
{
        int bone_lv;
        int j;
        string msg;
        object weapon;
        string *name;
        bone_lv= query_function("melt-bone");
        j=random(100);
        if( !target ) target = offensive_target(me);
        if(!target) return notify_fail("可能是精神错乱的关系,你竟然找不到敌人在那??\n");
//不可以攻击自己by bss
        if(target==me) return notify_fail("攻击自己???找死吗?\n");
        if(!me->is_fighting(target))
        return notify_fail("化骨绵掌只能在战斗中使用。\n");
        if(me->query("family/family_name")!="冥蛊魔教")
        return notify_fail("不是毒教教徒，不给你用\n");
  if(target->is_busy())
  return notify_fail("敌人busy中，快攻击吧！\n");
        if ( me->query("force") < 310 )
        return notify_fail("你的内力不够\n");
    message_vision(HIC"$N左手一收 ,一股腥臭之气在你手中凝聚 ,刹那间 ,\n"NOR,me,target);
    message_vision(HIC"天地变色 ,鬼哭神嚎!!\n"NOR,me,target);
    message_vision(HIC"\n$N左手微拍 ,低呼"HIR"‘  化骨绵掌!! ’ "HIC"$N阴毒掌风悄然向对手飘去!! \n"NOR,me,target);
if(80>random(100)) {
    if( j >= 95 && bone_lv>=90 && target->query_temp("no_die_soon")!=1)
    {
    me->add("force",-300);
    target->die();
    write (HIY"\n你的将真气凝灌双掌，砰的一声，敌人化为血水!!\n"NOR);
    say (HIY"\n哇哇....眼看着对手化为一摊血水 ,真是恶心死了......\n"NOR);
    }
else if( bone_lv <= 40)
    {
    me->add("force",-200);
    target->receive_damage("kee",(200+(bone_lv*3)));
    target->start_busy(1);
    write (HIG"只见掌风悄巧的朝敌人飘去 ,对手虽已有所警觉 ,但仍被掌风扫中!!\n"NOR);
    say (HIY"对手被"+me->query("name")+"所发出的掌风扫中 ,受到不小的伤害!\n"NOR);
    }
else  if( bone_lv >= 41 && bone_lv <= 80)
    {
    me->add("force",-250);
    target->receive_damage("kee",(250+(bone_lv*4)));
    target->start_busy(2);
    write (RED"只见掌风似有似无般飘向敌人 ,对手闪避不及 ,已中掌风!!\n"NOR);
    say (HIY"煞那间 ,对手身上多出一道掌印 ,显然受伤不轻!!\n"NOR);
    }
else if( bone_lv >= 81) {
    me->add("force",-300);
    target->receive_damage("kee",(300+(bone_lv*5)));
    target->start_busy(3);
    write (HIC"只见掌风似一阵薄暮轻烟般飘向敌人 ,对手在浑然不觉下 ,已惨遭毒手!!\n"NOR);
    say (HIY"不知怎么的 ,对手鲜血狂喷 ,已颓然倒下!!\n"NOR);
}
} else {
    write (HIW"天哪 ,掌风竟朝你自己飘来 ,啊啊!!真是逊毙了!!!\n"NOR);
    say (HIY"只见"+me->query("name")+"左手一阵乱摇 ,而对手毫发无伤地站在原地\n"NOR);
}
    me->start_busy(1);
if( bone_lv < 100) function_improved ("melt-bone",random(700));
    return 1;
}
