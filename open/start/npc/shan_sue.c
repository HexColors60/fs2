#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("圣贤书",({"master sue","sue"}));
	set("long","他是一个十分儒雅的年轻人，但却是武林中的有名的侠客。\n");
	set("gender","男性");
	set("class","scholar");
	set("nickname","九指书生");
          set("combat_exp",1000000);
          set("attitude","heroism");
	set("age",26);
		set("str", 44);
		set("cor", 24);
		set("cps", 18);
		set("per", 24);
		set("int", 42);
	set("force",1400);
	set_skill("literate",100);
	set("max_force",1400);
	set("force_factor",10);
	set_skill("force",60);
	set_skill("stabber",80);
	set_skill("dodge",50);
	set_skill("knowpen",100);
	map_skill("stabber","knowpen");
	set_skill("parry",40);
	set_skill("poetforce",80);
	map_skill("force","poetforce");
	map_skill("parry","knowpen");
	set_skill("unarmed",40);
	set("chat_chance_combat",30);
	set("chat_msg_combat",({
	(: perform_action, "stabber.movedown" :)
	}));
	setup();
	create_family("儒门",16,"弟子");
	carry_object(START_OBJ"ten_pen")->wield();
}

  void attempt_apprentice(object ob)
{
	if(this_player()->query("class")!="scholar")
	{
		command("say 汝非儒生也，焉能收汝为徒乎 ?\n");
		return;
	}
	command(":)");
          command("recruit "+ob->query("id"));
}
