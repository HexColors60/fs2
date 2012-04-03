// tujau.c by oda

#include <../badman.h>

inherit NPC;

void create()
{
	set_name("屠娇娇", ({ "tu jau jau", "tu", "jau" }) );
	set("nickname", "不男不女");
	set("gender", "女性");
	set("age", 39);
	set("long", "你正在怀疑你眼前的这个人究竟是个美女还是美男子，但是你大概永远也搞/n不清，因为屠娇娇的易容术堪称天下第一，少有人能看到她的真面目。\n");

	set("str", 25);
	set("cor", 26);
	set("int", 35);
	set("spi", 25);
	set("cps", 30);
	set("con", 22);
	set("per", 35);
	set("combat_exp", 2200);

	// set("chat_chance", 5);
	set("chat_msg", ({
		"农夫抬起头来擦擦额头上的汗水，又再弯下腰去努力的耕田。\n",
	}) );
	// set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		"农夫尖叫道：救命啊！有人杀人啊！\n",
		"农夫尖叫道：你要干什么？要钱也不用杀我吧！\n",
	}) );

	setup();
	// carry_object(S_OBJ"t_shirt")->wear();
}

int accept_fight(object me)
{
	return notify_fail("农夫笑着对你说：这位"+RANK_D->query_respect(me)+"别开玩笑了好吗?\n");
}
