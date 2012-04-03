//made by smirk
#include <ansi.h>

inherit NPC;

void create(){
	set_name("清道夫",({"clean man","man"}) );
	set("gender","男性");
	set("age",42);
	set("long",@LONG
	一位清早起床打扫环境的清道夫
LONG);
	set("combat_exp",2000);
	set("attitude","friendly");
	set("str",28);
	set("int",18);
	set("per",15);
	set_skill("dodge",20);
	set_skill("parry",10);
	set("chat_chance",30);
	set("chat_msg",({
	"清道夫说道:早睡早起身体好!!\n",
	"清道夫说道:身体是要好好保养的,像我40岁还是一条活龙,就是因为*保养*有方\n",
	"清道夫说道:每天都有清不完的垃圾,真麻烦!!\n",
	(: this_object(),"around" :),
        }) );
	set_temp("apply/armor",10);
	  set("inquiry", ([
	  "thief" : "你是说那个最近在皇城恶名昭彰的大盗是吧?!
                     可惜我连影子都没看过,一定是位高人,能够飞檐走壁说!!\n",
	  "保养"  : "这保养的方法(method)可是我纵横京城的秘宝!!",
	  "method": "方法就是早睡早起嘛!!........什么!!想知道秘技?!",
	  "秘技"  : "你真想知道就付点代价吧!!这可是我吃饭的家伙咧",
	  "代价"  : "嘿嘿....不二价....10两黄金!!",
	  ]) );	
setup();
	carry_object("/open/capital/obj/broom")->wield();
	carry_object("/obj/cloth")->wear();
	carry_object("/open/capital/obj/workpants")->wear();
	add_money("/obj/money/silver",20);
}

int accept_object(object who,object ob)
{  
  if( ob->value() < 1000000 )
   { say("清道夫说道:你太小看我的秘技了吧!!\n");
	return 1;}
  else{
    message_vision("清道夫说道:嘿嘿,果然你是个明眼人,来....这颗灵丹给你!!\n",who);
    new("/open/capital/obj/ggpill")->move(who);
    	return 1;}
}	
