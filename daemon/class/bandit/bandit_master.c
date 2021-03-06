#include </open/open.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
   set_name("蒋风",({"john fon","john","fon"}));
   set("family","恶人谷");
   set("nickname","百技神学");
   set("title","盗贼头子");
   set("gender", "男性");
   set("age",52);
   set("class", "bandit");
        set("guild_master", 1);
   set("bellicosity",1000);
   set("attitude", "badman");
   set("combat_exp",1000000);
   set("spi",50);
   set("int",50);
   set("str",10);
   set("cor",10);
   set("max_gin",1200);
   set("max_kee",3200);
   set("max_sen",1200);
   set("max_force",3500);
   set("force",3500);
   set("force_factor",10);
   
   set_skill("array",80);
   set_skill("steal",100);
   set_skill("change",100);
   set_skill("cure",60);
   set_skill("dodge",80);
   set_skill("force",80);
   set_skill("gamble",70);
   set_skill("literate",50);
   set_skill("magic",50);
   set_skill("move",80);
   set_skill("parry",80);
   set_skill("spells",50);
   set_skill("sword",80);
   set_skill("unarmed",80);
   set_skill("blade",80);
   set_skill("riding",20);
   set_skill("poison",60);
   set_skill("stabber",80);
   set_skill("archery",80);
   set_skill("whip",80);
   set_skill("throwing",80);
   set_skill("dagger",80);
   set_skill("plan",60);

setup();
        add_money("gold",30);
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player())&& !is_fighting() ) 
 {
        remove_call_out("greeting");
        call_out("greeting",1 , ob);
 }
        add_action("do_join", "join");
}

int do_join()
{
        object who;
        who = this_player();

        if( who->query("class") )
        return notify_fail("你已经是别的工会成员了，别来烦我！\n");
        who->set("class", "bandit");
    tell_object(users(),"[1;36m又有个家伙加入咱贼道啦！！！[0m");
 
        return 1;
}

void greeting(object ob)
{
  if( ob->query("class")=="bandit")
 {
  if (ob->query("quests/steal") == 1 )
  {
   message_vision("[1;37m嗯？偷得还过瘾吧？？[0m\n",ob);
  }
  else if (ob->query("combat_exp") > 100000 && ob->query("kar") == 30 )
  {
   message_vision("[1;32m哎呦！这么强运的人已经很少看到了，
我就特地教你怎么偷摸（steal）别人的东西吧！[0m\n",ob);
   ob->set("quests/steal",1);
  }
  else if(ob->query("quests/karup") == 1)
  {
  message_vision("[1;32m做得好啊！真是有出息，
那我就教你怎么去偷东西吧（steal）！[0m\n",ob);
  ob->set("quests/steal",1);
  }
  else if (ob->query_temp("marks/karup",1))
  {
  message_vision("[1;33m怎么还是老样子？再不努力点，我可不管你了！[0m\n",ob);
  }
  else if (ob->query("combat_exp") > 135000 && ob->query("kar") < 30 )
  {
   message_vision("[1;33m嗯，看来你有资格让我传授你一些东西，
但你的运气未免差了点，想办法让运势再加强点吧！[0m\n",ob);
   ob->set_temp("marks/karup",1);
  }
 }
}
