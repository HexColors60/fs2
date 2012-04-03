#include <ansi.h>

inherit NPC;
int tt=0;
void create()
{
	set_name("血妖", ({ "Bloody","bloody" }) );
	set("race", "野兽");
	set("age", 30);
	set("long", "全身流动着红色液体的怪物,忽而膨胀,忽而缩小,宛如要将你吞下去.\n");
	set("str", 40);
	set("cor", 40);
        set("limbs", ({ "头部", "身体", }) );
        set("verbs", ({ "poke"}));
	set("combat_exp", 4000);
	set_temp("apply/armor", 30);
        set_temp("apply/attack", 20);
	set("attitude","aggressive");
	set("random_move",2);
	set("chat_chance_combat",10);
	set("chat_msg_combat", ({
	    (: this_object(),"add_att" :), 
	   "[1;33m      ～血妖发出阵阵邪恶的气息～   \n[0m",      
	         }) );
	set_skill("dodge",35);
	setup();               
	 add_money("silver",10);

}
 
int add_att() 
{  int att ;
   att=random(3);
   if (tt <1) { 
     this_object()->add_temp("apply/attack",att);
     message_vision ("[1;34m不知道是不是错觉 , "
	"你发现血妖的身躯突然变得粗壮许多\n"NOR,this_object());
   }
   tt++;
   return 1;
}

void die()
{
 
  object me;
  me=this_object()->query_temp("last_damage_from");
  if( me&& userp(me) )  {
   me->add("bounds",20);
     tell_room(environment(),sprintf("%s从血妖身上除下20根绿毛放进口袋\n",me->name()));
    }
 :: die();
 } 
      
