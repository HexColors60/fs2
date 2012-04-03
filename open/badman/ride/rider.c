#include </open/open.h>
#include <ansi.h>

inherit NPC;

string do_want();
void create()
{
  set_name("许老",({ "elder shi","elder","shi"}) );
  set("title","牧人");
  set("gender", "男性");
  set("age",68);
  set("attitude", "peaceful");
  set("no_kill",1);
  set("no_fight",1);
  set("long","一个面貌和善的老人，是个好人。他正在准备狼群的食物。\n");
  set("chat_chance",6);
  set("chat_msg", ({
  "狼儿乖啊乖，好吃的就要来！\n",
  }) );

  set("inquiry", ([
  "骑狼" : "想骑啥就跟我要（want）就好了，问东问西的想干嘛？\n",
  ]));

setup();
}
