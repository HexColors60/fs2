#include <ansi.h>
inherit NPC;
void create()
{
	set_name("��ҩ����", ({ "grass tiger","tiger" }) );
        set("race", "Ұ��");
	set("age", 15);
	set("long", "һֻ���ų�ħ�������ϻ�.\n");
	set("str", 55);
        set("max_kee", 3000);
        set("kee", 3000);
        set("limbs", ({ "ͷ��", "����", "ǰ��" , "���" , "β��" }) );
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
       message_vision(HIR+"��ҩ�����³��޴�Ļ���,������$N!!!\n"+NOR,enemy[i]);
       enemy[i]->receive_damage("kee",120,me);
       COMBAT_D->report_status(enemy[i], 0);
      }else{
      message_vision(HIM+"��ҩ����һ��ҧס$N,��ȡ����ѪҺ�ظ��Լ�!!!\n"+NOR,enemy[i]);
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