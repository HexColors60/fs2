#include <ansi.h>
inherit NPC;
void create()
{
	set_name("守药神兽", ({ "grass tiger","tiger" }) );
        set("race", "野兽");
	set("age", 15);
	set("long", "一只带着超魔神力的老虎.\n");
	set("str", 55);
        set("max_kee", 3000);
        set("kee", 3000);
        set("limbs", ({ "头部", "身体", "前脚" , "后脚" , "尾巴" }) );
        set("verbs", ({ "bite"}));
	set("combat_exp",250000);
	set_temp("apply/armor", 80);
        set_temp("apply/attack", 40);
        set("attitude","aggressive");
	set_skill("dodge",70);
	setup(); 
        carry_object("/open/doctor/item/ff_item");
        carry_object("/open/doctor/item/f_item");
        set_heart_beat(1);
}
void heart_beat()
{
  object *enemy,me;
  int i;
  me = this_object();
  if( me->is_fighting() )
  {
    if( 50 > random(200) )
    {
      enemy = me->query_enemy();
      i=random(sizeof(enemy));
      if(environment(me) == environment(enemy[i]))
      if( random(10) > 7)
      {
       message_vision(HIR+"守药神兽吐出巨大的火球,击中了$N!!!\n"+NOR,enemy[i]);
       enemy[i]->receive_damage("kee",120,me);
       COMBAT_D->report_status(enemy[i], 0);
      }else{
      message_vision(HIM+"守药神兽一口咬住$N,吸取他的血液回复自己!!!\n"+NOR,enemy[i]);
      enemy[i]->receive_damage("kee",60,me);
      COMBAT_D->report_status(enemy[i], 0);
      me->receive_curing("kee",60);
      me->receive_heal("kee",60);
      }
     }
   }
   if( me->query("kee") < 0 )
      me->die();
   ::heart_beat();
}                             
