#include <ansi.h>
#include "/open/open.h"
inherit NPC;
  inherit F_MASTER;
void create()
{
	set_name("柳毅",({"master swordsman","master"}));
 set("long","剑士公会三长老 ,负责在署中城接收新会员 .\n");
		set("gender","男性");
	set("class","swordsman");
	set("nickname","飞音剑");
          set("combat_exp",1000000);
          set("attitude","heroism");
	set("age",43);
	set("title","剑士公会三长老");
		set("str", 44);
		set("cor", 24);
		set("cps", 18);
		set("per", 24);
		set("int", 42);
	set("force",1400);
	set_skill("literate",40);
	set("max_force",1400);
	set_skill("array",80);
	set_skill("move",60);
	set_skill("force",60);
	set_skill("dodge",80);
	set_skill("parry",60);
	set_skill("sword",100);
	set_skill("unarmed",40);
	set_skill("blade",40);
	set_skill("staff",40);
	set_skill("throwing",40);
	set_skill("dagger",40);
	set("force_factor",10);
	set_skill("hammer",40);
	setup();
	carry_object("/open/gsword/obj/heaven-sword")->wield();
	carry_object("/open/gsword/obj/tiger-surcoat")->wear();
	add_money("gold",10);
}

void init()
{
	add_action("do_join","join");
}
int do_join()
	{
	if(this_player()->query("class"))
		return notify_fail("你已经加入其他工会了。\n");
	this_player()->set("class","swordsman");
	message("system",HIW "柳毅纵声大呼 :\n
欢迎" +this_player()->name()+"加入剑士公会!!\n\n"NOR,users());
	return 1;
}
   /*
	int do_say(string str)
	{
	object who;
	who=this_player();
	if(!who->query_temp("allow_select"))
	{
	command("say 我又没答应让你挑? ");
	return 0;
	}
	if(who->query_temp("have_say")==1)
	{
	command("say 你不是挑过了?");
	return 0;
	}
	if(str=="张乘风")
        {
	this_player()->set_temp("allow_1",1);
	command("smile");
	command("say 嗯 ,你就拜我的首徒张乘风吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	if(str=="张乘云")
	{
	this_player()->set_temp("allow_2",1);
	command("smile");
	command("say 嗯 ,你就拜我的次徒张乘云吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	if(str=="范松")
	{
	this_player()->set_temp("allow_3",1);
	command("smile");
	command("say 嗯 ,你就拜我的三弟子范松吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	if(str=="赵鹤")
	{
	this_player()->set_temp("allow_4",1);
	command("smile");
	command("say 嗯 ,你就拜我的四弟子赵鹤吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	if(str=="梁发")
	{
	this_player()->set_temp("allow_5",1);
	command("smile");
	command("say 嗯 ,你就拜我的五弟子梁发吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	if(str=="何双双")
	{
	this_player()->set_temp("allow_6",1);
	command("smile");
	command("say 嗯 ,你就拜我的女弟子何双双吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	if(str=="李逍遥")
	{
	this_player()->set_temp("allow_7",1);
	command("smile");
	command("say 嗯 ,你就拜我的七弟子李逍遥吧!");
	this_player()->set_temp("have_say",1);
	return 0;
	}
	command("say 没这人!");
	return 0;
	}
  */
