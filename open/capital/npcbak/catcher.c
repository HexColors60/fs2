//bun.c

#include <../capital.h>

inherit PARTY_NPC;

void create()
{
	set_name("捕快",({"catcher"}));
	set("gender","男性");
	set("officer_type","catcher");
	set("class","officer");
	set("officer_class","捕快");
	set("combat_exp",1155);
	set_skill("sword",40);
	set_skill("dodge",40);
	set("officer_power",10);
	set("max_officer_power",10);
	set("age",30);
	set("lim",1);
	set("be_party_msg","可否与我同行 ?\n");
	set("lim_msg","没有接到命令，我不能擅离职守。\n");
	set("no_kill",1);
	setup();
	carry_object("obj/longsword")->wield();
}
int test_limit()
{
	return 0;
}
int test_kill_limit(object ob)
{
	if(ob->query("id")!=this_object()->query_temp("catch_id"))
		return 0;
}
