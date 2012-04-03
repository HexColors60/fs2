inherit NPC;
#include <ansi.h>
#include "wind-rain.h"
void create()
{
        object ob;
	set_name("雨护卫",({"rain guard","guard"}));
	set("long","
金风细雨楼中，「金风细雨”四辈护卫中的雨护卫，他正站在
楼前庭园的门旁守卫着。
");
	set("gender","男性");
	set("combat_exp",50000);
	set("attitude","peaceful");
	set("age",25);
	set("class","soldier");
	set("str",30);
        set("cor", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 30);
        set("max_force",800);
        set("force",800);
        set("max_kee",550);
        set("force_factor",10);
	set_skill("throwing",20);
        set_skill("rainthrowing",35);
	set_skill("parry",20);
        set_skill("wind-rain",35);
	set_skill("dodge",20);
        set_skill("move",40);
        set_skill("lo-steps",35);
        map_skill("throwing", "rainthrowing");
        map_skill("dodge","lo-steps");
        map_skill("move","lo-steps");
        map_skill("parry","wind-rain");
        ob=carry_object(C_OBJ"/throw-1");
        ob->set_amount(15);
        ob->wield();
	setup();
	add_money("silver",10);
}
int accept_kill(object who)
{
  command("say 好小子！！竟敢硬闯风雨楼！！");
  return 1;
}

int accept_fight(object who)
{
    return notify_fail("风护卫摇摇头说说 : 我现在在值勤，没空切磋武艺。");
}
