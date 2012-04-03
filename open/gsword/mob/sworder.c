// guard.c

#include <ansi.h>

inherit NPC;

string ask_me(object who);
int counter = 1;
void create()
{
	set_name("潦倒剑客", ({ "sworder", "man" }) );
	set("gender", "男性" );
	set("age", 41);
	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 5);
	set("long",
		"一位从东北来的剑客,他抱着满腹的希望想向无极真人学剑.\n"
		"他的盘缠用完了,正踌躇不知如何是好,你想你可以资助他.\n" );
	set("combat_exp",893);
	set("attitude", "peaceful");
	set("chat_chance", 10);
	set("chat_msg", ({
		"潦倒剑客说: 没想到要见无极真人如此困难.\n",
		"潦倒剑客说: 天下第一高手无极真人,我只要学得其十分之一剑术,就足以独霸武林了.\n",
	}) );
	set("inquiry", ([
		"help": "谢谢你...我只是欠些钱而已...\n",
		"资助": "$$$$...一毛钱逼死一条好汉...\n",
	]) );
	set_skill("sword", 25);
	set_skill("parry", 30);
	set_skill("dodge", 35);
	setup();
	add_money("silver",4);
        carry_object("/open/gsword/obj/robe_1")->wear();
        carry_object("/open/gsword/obj/boot-1")->wear();
        carry_object("/open/gsword/obj/sword")->wield();
}
int accept_object(object who, object ob)
{       object book;
        if(counter)
        {  
          if( ob->value() < 500 )
          {    say(" 潦倒剑客说: 谢谢你,等我成名后会记得你的.\n");
              return 1; }
          else {  say(" 潦倒剑客说: 真是太感谢了,这本书给你算是回报.\n");
               book = new("/open/gsword/obj/sword_book");
               book->move(this_player());
               counter = 0;
               return 1; }
         } else {
               say(" 潦倒剑客说: 谢谢你了,我的钱够用了...\n");
               return 1; }      
}                 	

