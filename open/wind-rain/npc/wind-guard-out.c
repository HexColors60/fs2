inherit NPC;
#include <ansi.h>
#include "wind-rain.h"
void create()
{
       
	set_name("楼外风护卫",({"wind guard","guard"}));
	set("long","
金风细雨楼中，「金风细雨”四辈护卫中的风护卫
负责楼外花园的巡逻。
");
	set("gender","男性");
	set("combat_exp",150000);
	set("attitude","peaceful");
	set("age",25);
	set("class","soldier");
	set("str",30);
        set("cor", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 30);
        set("max_force",1000);
        set("force",1000);
        set("max_kee",550);
        set("force_factor",3);
	set_skill("hammer",50);
        set_skill("wind-hammer",70);
	set_skill("parry",30);
        set_skill("wind-rain",60);
	set_skill("dodge",45);
        set_skill("move",55);
        set_skill("lo-steps",50);
        map_skill("hammer", "wind-hammer");
        map_skill("dodge","lo-steps");
        map_skill("move","lo-steps");
        map_skill("parry","wind-rain");
	setup();
        carry_object(C_OBJ"/star-hammer")->wield();
	add_money("silver",50);
}
int accept_kill(object who)
{
  command("say 竟敢动风雨楼的人！");
  return 1;
}
