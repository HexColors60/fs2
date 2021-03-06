#include <ansi.h>

inherit NPC;
void create()
{
	set_name("陆小双",({"lu"}));
	set("title","剑客");
	set("nickname",HIC "刀剑双绝" NOR);
	set("long",@LONG
眼前你所看到的是一个坐着轮椅的剑客「陆小双”。
LONG);
	set("gender","男性");
	set("combat_exp",1000000);
	set("attitude","heroism");
	set("age",30);
	set_skill("blade",100);
	set_skill("sword",100);
	set_skill("dragon-blade",100);
	set_skill("shasword",100);
	map_skill("blade","dragon-blade");
	map_skill("sword","shasword");
	set_skill("parry",100);
	map_skill("parry","shasword");
	set_skill("force",100);
	set_skill("snowforce",100);
	set_skill("dodge",100);
	set_skill("black-steps",100);
	map_skill("dodge","black-steps");
	map_skill("force","snowforce");
	set("kee",5000);
	set("max_kee",5000);
	set("force",2000);
	set("max_force",2000);
	set("force_factor",20);
	setup();
	carry_object("/open/snow/obj/lu_sword")->wield();
	carry_object("/open/snow/obj/lu_blade")->wield();
}
