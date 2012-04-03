#include <ansi.h>//reflection by cgy
inherit F_SPELL;
inherit SSERVER;
int fun;

void remove_effect (object me);
int conjure(object me, object target)
{
	string msg;
	fun=me->query("spells/reflection/level");
	if (!me->query("spells/reflection/level"))
     return 0;
  if((me->query("family/family_name")!="夜梦小筑")&&(me->query("id")!="cgy"))
     return notify_fail ("只有舞者能用这种法术！\n");
  if (me->query ("atman") < 200)
     return notify_fail ("你的灵力不足!\n");
  if ((int)me->query_temp ("ref_shield", 1))
     return notify_fail ("你已经使用玄冰结界了。\n");

if( me->is_fighting() ) me->start_busy(1); //在战斗中使用,要busy自己一回合 by chan

  msg = HIG "$N集中全身灵力右手在身前划了一个大圆，渐渐的在$N的身前出现了一面"NOR;
  msg += HIG "\n冰盾保护着$N，原来是梦玄法鉴中的"HIR"终极防御术"HIC"「玄☆冰☆结☆界”\n"NOR;
  message_vision(msg, me, target);
  me->add ("atman", -200);

       
  message_vision (HIY"$N感到自己有着所向无敌的防御力。\n"NOR, me,target);

// 设这个mark后就有ref_shield 了
  me->set_temp ("ref_shield", 1);
  me->start_call_out((: call_other, __FILE__, "remove_effect",me:),fun+20);
  

  return 1;
}

void remove_effect (object me)
{
// 删除 manashield   
  int fun=me->query("spells/reflection/level");
  me->delete_temp ("ref_shield");
  tell_object (me,HIW"妳觉得自己的防御力下降了许多。\n"NOR);
  if(fun<100) spell_improved("reflection",random(300));   
  return;
}
