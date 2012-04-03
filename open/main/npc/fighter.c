#include "/open/open.h"
inherit NPC;
void create()
{
set_name("扶桑武者", ({ "fighter"}) );
	set("gender", "男性" );
	set("age", 34);
	set("long", @LONG
他是扶桑中程度的武者.
负责守卫着扶桑的安全!
LONG);
      set("attitude","aggressive");
set("force_factor",5);
        set("combat_exp",50000);
        set("max_force",1000);
        set("kee",400);
set("force",1000);
set("max_kee",400);
        set_skill("season-flower-blade",50);
        set_skill("dodge",50);
set_skill("force",50);
set_skill("gforce",50);
map_skill("force","gforce");
	set_skill("blade",50);
	set_skill("parry",50);
	set_skill("mirage-steps",50);
        map_skill("blade","season-flower-blade");
        map_skill("parry","season-flower-blade");
        map_skill("dodge","mirage-steps");
        set("chat_chance",40);
        set("chat_msg",({
        (: this_object(),"random_move" :),
        }));
	setup();
        carry_object("/open/ping/obj/guard_blade")->wield();
	
}
void die()
{
  object me;
  me= this_object()->query_temp("last_damage_from");
  if( me&& userp(me) ) {
      me->add("head",2);
tell_room(environment(),sprintf("%s杀死了扶桑武士,得到两点战功。\n",me->name()));
}
      ::die() ;
}
