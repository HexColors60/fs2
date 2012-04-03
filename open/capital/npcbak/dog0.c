// by Onion
#include <command.h>
inherit NPC;

void create()
{
	set_name("凶恶的獒犬", ({ "bad dog","dog" }) );
        set("race", "野兽");
	set("age", 15);
	set("long", "非常具有攻击性的狗, 随时想要扑上来咬你一口的样子。\n");
	set("str", 100);
        set("max_kee", 800);
        set("limbs", ({ "头部", "身体", "前脚" , "后脚" , "尾巴" }) );
        set("verbs", ({ "bite"}));
        set("combat_exp",15000);
        set("attitude","aggressive");
	set_temp("apply/damage", 70);
        set_temp("apply/attack", 30);
	setup(); 
}
void greeting(object who)
{
	if( !is_killing(who) )
		write(name()+"朝着你扑过来, 似乎想把你给撕裂一般。\n");
}
int follow_me(object who, string dir)
{
	object ob=this_object();
	if ( !living(ob) || who==ob )
		return 0;
        call_out("delay_follow", 1, ob, dir);
        return 1;
}
void delay_follow(object ob,string dir)
{
        GO_CMD->main(ob, dir);
}
