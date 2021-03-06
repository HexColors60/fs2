#include <ansi.h>
#include "/open/open.h"
inherit NPC;

void create()
{
	set_name("老园丁", ({"old gardener","gardener"}) );
	set("age", 70);
	set("combat_exp",100000);
	set("score", 100000);
	set("long","一个园丁模样的人,瞧他的服饰应是魔教中人.但你奇怪他为何能终年
在此地做事而不为毒所侵,想必是具有深厚内力的内家高手。\n"+
"他正为了井水不足的问题在烦恼着。\n");
	set("class", "poisoner");
	set("gender", "男性");
	set("attitude", "friendly");
	set("str", 44);
	set("cps", 30);
	set("cor", 30);
	set("con", 33);
	set("force", 600);
	set("max_kee",800);
	set("max_sen",800);

	set("gin", 800);
	set("max_gin",800);
	set("max_force", 600);
	set("force_factor",1);
	set_skill("parry", 30);
	set_skill("dodge", 50);
	set_skill("move", 50);
	set_skill("unarmed", 20);
	set_skill("force", 20);
	set_skill("poison", 60);
	set_skill("poisonforce", 30);
	set_skill("coldpoison", 60);
	set_skill("nine-steps", 60);
	map_skill("move","nine-steps");
	map_skill("dodge","nine-steps");
	map_skill("poison", "coldpoison");
	map_skill("force", "poisonforce");
	set_skill("dagger",40);
	set("chat_chance", 10);
	set_skill("dragon-dagger", 40);
	map_skill("dagger", "dragon-dagger");
	set("chat_msg",({
		"老园丁说道:嘿,这里很漂亮吧.我可是每天很辛苦的除草、浇花喔!\n",
            "老园丁忧愁说道:最近园子里不知怎么了,井水的供给一直不足。\n",
}) );
	set("chat_chance_combat", 6);
	set("chat_msg_combat",({
		"老园丁说道:不自量力的小伙子,敢向我挑战。\n",
		"老园丁说道:我老归老,但可是宝刀未老,小子你还嫩得很呐!\n",
}) );
	set("inquiry", ([
	"井水" : " 你能帮老朽查探查探吗?若事成,老朽有一物相赠。\n",
"巨蟒" : "原来是此物在做怪,你若是能制伏此物,并带来证明之物,老朽即将身上所带
之奇书赠之。\n",
]) );
	setup();

	carry_object("/obj/poison/rose_poison")->set_amount(30);
	carry_object("/obj/poison/five_poison")->set_amount(30);
	carry_object("/obj/poison/dark_poison")->set_amount(30);
	carry_object("/open/poison/obj/scissors.c")->wield();
        carry_object("/open/poison/obj/ecloth.c")->wear();
	carry_object("/open/poison/obj/ebelt.c")->wear();
}
int accept_object(object who, object item)
{
	object me;
	me = this_player();
	if (item->query("id") == "serpent tooth")
	{ destruct (item);
	tell_object (who, "老园丁高兴的说:真是多谢了,这本书就当谢礼吧。\n");
	new("/open/poison/obj/pkingbook.c")->move(who);
	return 1;
	}
	else
	{
	tell_object (who, "老园丁疑惑的说:你给我这样东西做甚？？\n");
	 return 1;
	}
}
