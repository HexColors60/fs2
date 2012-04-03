#include <ansi.h>

inherit NPC;

string do_ask();

void create()
{
      set("title","六婆");
      set_name("瘦妇人",({"thin woman","thin","woman"}) );
      set("long",@LONG
一个身材削瘦的妇人，却有一双刻薄的眼睛，和胖妇人号称是街上的最佳拍档，
其泼妇骂街的本事也是当仁不让于胖妇人的。
LONG
      );
      set("age",49);                 
      set("attitude","peaceful");
      set("gender","女性");

      set_skill("dodge",30);
      set_skill("unarmed",35);
      set_skill("parry",25);
      set("combat_exp",1000);

      set("chat_chance",4);
      set("chat_msg",({
      "瘦妇人笑道:喔!这样子啊,呵.....\n",
      "瘦妇人笑道:那个明月啊,听说还想在这做一番大事业呢!呵....\n",
      }) );      

      set("chat_chance_combat",9);
      set("chat_msg_combat",({
      "瘦妇人冷笑道:既然那么想死,老娘就送你一程吧。\n",
      "瘦妇人冷讽说:小子,你是怕活太久会当米虫,是不是?我看有可能喔!!\n",
      }) );
  set("inquiry",([
  "杜杀的左手" : (: do_ask :),
  ]));

      setup();

      carry_object("/obj/cloth")->wear();
      add_money("silver",2);
}

int accept_fight(object who)
{
      write("瘦妇人竖起中指挖了挖耳朵。\n");
      switch( random(2) ) {
       case 0: say ("瘦妇人叹道:年纪轻轻便要夭折,唉~~可惜啊。\n");break;
       case 1: say ("瘦妇人喝道:"+RANK_D->query_rude(who)+"!老娘就陪你玩玩,让你瞧瞧老娘的手段。\n");break;
  return 1;
      }
  return 1;
}
string do_ask()
{
  int me;
  object who = this_player();
    if(who->query_temp("marks/hand")!=1)
  {
    return "怎么不问问杜杀呢 ?\n";
  }
  else
  {
  who->set_temp("marks/hand_again",1);
       return "唉呦 !被骂啦..好可怜的小兄弟呀 !没关系 ,杜杀只是不想欠你人情而已 ,再试一次看看..他应该会跟你说明的 .\n";
  }
}
