#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string do_menu();
string do_can();

int accept_object (object me,object ob)
{
  object ob2;

  if (me->query("class") != "killer")
  {
    command ("say 神经病，你给我这个干嘛！\n");
    return 0;
  }
  if(ob->query("id") == "maiu-head") 
  {
     message_vision(" 李三笑将人头收下来，仔细检查了一下\n",me);
     command("say 果然不是造假的人头，很好！酬金给你吧\n");
     destruct(ob);
     ob2=new("/open/killer/obj/bellstar.c");
     ob2->add_amount(99);
     ob2->move(me);
     return 1;
  }
  if(ob->query("id") == "snow token") 
  {
     if (me->query_temp("mission2") == 3)
     {
     message_vision(" 李三笑将圣物收下来，仔细检查了一下\n",me);
     command("say 太好了，左青龙，右雷虎，这是幽冥之壶给你吧，不用还了，省得有人老来烦我\n");
     destruct(ob);
     ob2=new("/open/killer/obj/can.c");
     ob2->move(me);
     me->set_temp("mission2",4);
     return 1;
     }
  }
  if(ob->query("id") == "nija_head") 
  {
     message_vision(" 李三笑将人头收下来，仔细检查了一下\n",me);
     command("say 果然不是造假的人头，很好！酬金给你吧\n");
     destruct(ob);
     ob2=new("/open/killer/obj/s_pill.c");
     ob2->add_amount(4);
     ob2->move(me);
     ob2=new("/obj/money/gold");
     ob2->add_amount(19);
     ob2->move(me);
     return 1;
  }
  if(ob->query("id") == "sword_head") 
  {
     message_vision(" 李三笑将人头收下来，仔细检查了一下\n",me);
     command("say 果然不是造假的人头，很好！就让我来帮你转换内力吧！\n");
     message_vision("只见，李三笑使出黑牙神功奥义----化气成灵！！\n",me);
     destruct(ob);
     message_vision("由$N体内冒出一道白气，在李三笑的转换之下，化成紫气钻回体内\n",me);
     if (me->query("max_atman") < 750)
     {
	     me->add("max_force",-5);
	     me->add("max_atman",5);
	     return 1;
     }
     message_vision("那道紫气在接触$N的同时，再次化为白气\n",me);
     command("say 唉。。。我的能力不足以帮你转换灵力了！");
     return 1;
  }
  if(ob->query("id") == "killer_wanted") 
  {
     message_vision(" 李三笑将人头收下来，仔细检查了一下\n",me);
     command("say 果然不是造假的人头，很好！酬金给你吧\n");
     destruct(ob);
     ob2=new("/open/killer/obj/s_pill.c");
     ob2->add_amount(99);
     ob2->move(me);
     ob2=new("/obj/money/gold");
     ob2->add_amount(999);
     ob2->move(me);
     ob2=new("/open/killer/obj/bellstar.c");
     ob2->add_amount(999);
     ob2->move(me);
     return 1;
  }
  if(ob->query("id") == "zhang-head") 
  {
     message_vision(" 李三笑将人头收下来，仔细检查了一下\n",me);
     command("say 果然不是造假的人头，很好！酬金给你吧\n");
     destruct(ob);
     ob2=new("/open/killer/obj/k_ring.c");
     ob2->move(me);
     return 1;
  }
  if(ob->query("id") == "hou_head") 
  {
     message_vision(" 李三笑将人头收下来，仔细检查了一下\n",me);
     command("say 果然不是造假的人头，很好！酬金给你吧\n");
     destruct(ob);
     ob2=new("/open/killer/obj/bellstar.c");
     ob2->add_amount(49);
     ob2->move(me);
     ob2=new("/open/killer/memory/static.c");
     ob2->move(me);
     ob2=new("/open/killer/obj/s_pill.c");
     ob2->add_amount(1);
     ob2->move(me);
     return 1;
  }
  if(ob->query("id") == "fu_head") 
  {
     message_vision(" 李三笑将人头收下来，仔细检查了一下\n",me);
     command("say 果然不是造假的人头，很好！酬金给你吧\n");
     destruct(ob);
     ob2=new("/open/killer/obj/hate_knife.c");
     ob2->add_amount(199);
     ob2->move(me);
     ob2=new("/obj/money/gold");
     ob2->add_amount(9);
     ob2->move(me);
     return 1;
  }
  if(ob->query("id") == "yar_head") 
  {
     if (me->query_temp("mission3") != 6)
     {
      command("say 居然敢叫别人帮你拿！可恶！看掌！！\n");
      message_vision(" 李三笑一掌将$N打飞\n",me);
      me->add("kee",(me->query("kee"))/2);
      me->move("/open/killer/home/ru1.c");
      return 0;
     }
     message_vision(" 李三笑将人头收下来，仔细检查了一下\n",me);
     command("say 果然不是造假的人头，很好！酬金给你吧\n");
     destruct(ob);
     ob2=new("/open/killer/obj/s_pill.c");
     ob2->add_amount(9);
     ob2->move(me);
     ob2=new("/open/killer/weapon/k_cloth3.c");
     ob2->move(me);
     ob2=new("/open/killer/weapon/k_arm3.c");
     ob2->move(me);
     ob2=new("/open/killer/weapon/k_head3.c");
     ob2->move(me);
     return 1;
  }
  return 0;
}

void create()
{
        set_name("李三笑",({"king-lee","lee"}));
        set("long","传说此人曾为魔教的长老，后来因故加入黑牙联。\n
                    目前似乎负责传达杀手目标物的名单(menu)\n");
        set("gender","男性");
        set("class","poisoner");
        set("nickname", HIG "幽冥鬼王" NOR);
        set("combat_exp",700000);
        set("attitude","heroism");
        set("age",60);
        set("str", 40);
        set("cor", 34);
        set("cps", 30);
        set("per", 30);
        set("int", 30);
        set("force",1800);
        set("max_kee",3500);
       set("kee",3500);	
        set("max_force",1800);
        set_skill("move",80);
        set_skill("force",90);
        set_skill("dodge",100);
        set_skill("parry",70);
        set_skill("poison",60);
        set_skill("throwing",80);
        set_skill("rain-throwing",80);
        set_skill("poisonforce",99);
        set("force_factor",10);
        set_skill("coldpoison",80);
        set_skill("nine-steps",100);
        map_skill("throwing","rain-throwing");
        map_skill("dodge","nine-steps");
        map_skill("move","nine-steps");
        set_skill("ming-snake",60);
        set("inquiry",([
        "menu" : (: do_menu :),
        "借幽冥之壶" : (: do_can :),
        "叶秀杀"   : "真是超级高手，我完全不是他的对手\n",
        ]));
        setup();
        carry_object("/open/killer/obj/lustar")->set_amount(200);
        add_money("gold",10);
}
string do_menu()
{
  object me = this_player();
  object ob;

   if(me->query("class") == "killer")
   {
        tell_object(me,"目前工作不多，只有几件工作\n");
        tell_object(me,"想接就看纸上所写的名单，包含酬金\n");
        if(me->query_temp("menuget") !=1)
        {
           ob=new("/open/killer/obj/killmenu.c");
           me->set_temp("menuget",1);
           ob->move(me);
        }
        return "把人头给我，我就给你酬金\n";
   }
   command("waggle "+me->query("id"));
   return "你可不是杀手耶，你怎么敢杀呢\n";
}

string do_can()
{
  object me = this_player();
  object ob;

   if(me->query("class") == "killer")
   {
     if(me->query_temp("mission2") != 2)
     {
       return "干嘛！无聊，没事找事做呀！！";
     }
     if(me->query_temp("mission2") ==2)
     {
        tell_object(me,"可恶！那老太婆没事找事做。。。。\n");
        tell_object(me,"想借可以，我想得到雷虎之气，帮我拿个雪泉圣物吧\n");
        me->set_temp("mission2",3);
        return "把东西给我，我就给你幽冥之壶\n";
     }
   }
   command("waggle "+me->query("id"));
   return "凭什么借给你？\n";
}
