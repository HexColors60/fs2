// hell_guard.c
//be airke

#include <ansi.h>
#include <combat.h>

inherit NPC;

#define bell_big 600
#define bell_small 400
#define INVLEVEL 50
#define MANACOST 100
#define INVCOST 50

int special_att ();

object room2;
void create()
{
	set_name("九天妖狐", ({ "nine-fox","fox" }) );
	set("long", "在妖界数一数二的强力妖怪，全身雪白，拥有极高的灵性\n" +
		    "和法力。后来被老君收服。\n");
		    
	set("attitude", "peaceful");
        set("race","野兽");
	set("gender","雌性");
        set("max_force",3000);	
	set("max_kee",4000);
	set("force_factor",10);
	set_skill("dodge",200);
        set("str", 30);
	set("cor", 30);
	set("cps", 25);
        set("int", 50);
        set("spi", 50);
	set("limbs",({"头部","胸部","腹部","背部","前脚","后脚","尾巴"}));
        set("verbs",({"bite","claw"}));
  set ("chat_chance_combat",35);
	set ("chat_msg_combat", ({(: special_att :)}));

	setup();

}

void besummon(object who,object room)
{
	int i, bell,pp;
	object *enemy;
	object me = this_object ();
	room2=room;

	message_vision (MAG"一阵冷风吹过，一只$N缓缓地现形。\n" NOR, me);
	pp=who->query("combat_exp");
	set("combat_exp",pp*3/2);
	if( pp > 500000 )	
		pp = 500000;
	set("max_kee",pp/100);
	set("kee",pp/100);
	
        bell = who->query ("bellicosity");
	if (bell > bell_small)
	{
	    message_vision (HIB"$N冷笑道:就凭你?\n", me);
	    kill_ob (who);
	    set_leader (who);
	    return;
	}

	enemy = who->query_enemy ();
	i = sizeof(enemy);
	while(i--) {
		enemy[i]->fight_ob(this_object());
		fight_ob(enemy[i]);

	}
	set_leader(who);
         who->add_temp ("invocation", INVCOST);
}

void init()
{
       
      set_heart_beat(1);
}

void heart_beat()
{
	object who = query_leader ();
     if(!who){
        call_out("leave",0);
        return;
     }

	if (!is_fighting() ) {
	     call_out("leave", 0);
	     return;
	}
	if(room2!=environment(who)||!who->is_fighting()) {
             call_out("leave",0);
             return;
        }

	   :: heart_beat();
}

void leave()
{
  object who = query_leader ();
	if( environment() )
  message_vision (
		  MAG"一阵冷风吹过，$N的身形再度隐入黑暗之中～～～\n" NOR, this_object ());
  if (who)
    who->add_temp ("invocation", -INVCOST);
  destruct(this_object());
}

void unconcious ()
{
  object who = query_leader ();
  if (who)
    who->add_temp ("invocation", -INVCOST);
  message_vision (HIG"$N惨叫一声啊！消失得无影无踪。\n", this_object ());
  destruct (this_object ());
}

int needlevel ()
{
  return INVLEVEL;
}

int manacost ()
{
  return MANACOST;
}

int invcost ()
{
  return INVCOST;
}

int special_att ()
{
  object me = this_object ();
  object *enemy = me->query_enemy (), victim;
  int i = sizeof (enemy);
  victim = enemy[random(i)];
message_vision (HIG"$N忽地一声长啸，一道异光自眼中电射而出～～～～～～\n\n"NOR, me);   
message_vision (HIC"$N顿时感到一阵迷惘，昏昏沈沈地不知所措。\n"NOR, victim);  
  victim->start_busy(3);  
  me->start_busy (1);
  return 1;
}
