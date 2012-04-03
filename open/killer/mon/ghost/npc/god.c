#include <ansi.h>
inherit F_VENDOR;

string magic1();

void create()
{
        set_name("土地公",({"ground god", "god"}));
        set("long","最近庙里香火不盛, 土地公为了生活, 所以兼点副业, 卖卖金纸跟香火。\n");
        set("gender","男性");
        set("combat_exp",100000);
        set("attitude","heroism");
        set("age",200);
        set("str", 99);
        set("cor", 99);
        set("cps", 99);
        set("per", 99);
        set("spi", 99);
        set("int", 99);
        set("force",5000);
        set("max_kee",5500);
        set("kee",5500);
        set("max_gin",5500);
        set("gin",5500);
        set("max_sen",5500);
        set("sen",5500);
        set("max_force",5000);
        set("max_mana",5000);
        set("mana",5000);
        set("max_atman",5000);
        set("atman",5000);
        set("force_factor",20);
        set_skill("literate",100);
        set_skill("move",100);
        set_skill("force",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("whip",100);
        set_skill("parry",100);

        set_skill("gwhip",100);
        set_skill("gforce",100);
        set_skill("g-steps",100);

        map_skill("whip","gwhip");
        map_skill("force","gforce");
        map_skill("dodge","g-steps");
        set("vendor_goods",({
                "/open/killer/mon/ghost/obj/gpaper.c",
                "/open/killer/mon/ghost/obj/incense.c",
        }) );   
        set("chat_chance_combat",20);
        set("chat_msg_combat",({
        (: magic1 :),
        }));
        setup();
        carry_object("/open/tendo/obj/goldwhisk")->wield();
        carry_object("/open/tendo/obj/hat")->wear();
        carry_object("/open/tendo/obj/robe")->wear();
        carry_object("/open/tendo/obj/shoe")->wear();
}

void init ()
{
  ::init ();
  set ("class", "taoist");
}

int accept_fight( object me)
{
   command("say 你看清楚, 我是土地公耶, 土地公你也敢打....");
   return 0;
}

int accepy_kill( object me)
{
   if( me->query("combat_exp") < 1000000)
   {
      command("say 哇靠...我是土地公耶, 是神耶, 你竟然要杀我...");
      command("say 不过我佛慈悲, 我不会跟你一般计较的, 你走吧...");
      return 0;
   }
   command("say 哇靠...我是土地公耶, 是神耶, 你竟然要杀我...");
   command("say 既然是这样, 那我就不能轻易饶了你。");
   message_vision("只见土地公口中念念有词:「南无ㄚ嘧哄, 风火雷电冰...”\n", me);
   message_vision("瞬间土地公的身形突然长大数倍, 全身青筋爆起, 周身缠绕着腾腾云雾\n", me);
   message_vision("随即大喝一声, 拂尘电闪而至...\n", me);
   set("combat_exp", me->query("combat_exp")*0.5);
   return 1;
}

string magic1()
{
        command("cast feeblebolt");
        return "\n";
}
