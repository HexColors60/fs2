
inherit NPC;

void create()
{
        set_name("老船夫",({"boat man","man"}));
        set("long","一位年近古稀的老人 , 但眼底闪着精光 !\n");
        set("gender","男性");
        set("combat_exp",300000);
        set("attitude","heroism");
        set("age",20);
        set("str",30);
        set("cor", 30);
        set("per", 25);
        set("int", 30);
        set("cps",20);
        set("con", 30);
        set("spi", 15);
        set("kar", 30);
        set_skill("unarmed",300);
        set_skill("dodge",200);
       set_skill("parry",260);
        set("chat_chance",20);
        set("chat_msg",({
        "海浪拍打着船身 , 溅起一阵阵的海花 !\n",
        "耳边传来阵阵的海浪声及海鸟的叫声令人悠然入梦 !\n",
        "放眼望去是一片的碧海蓝天 , 真是美丽啊 !\n",
        }));
        setup();
        add_money("coin",100);
}
 int accept_kill(object me)
 {
        return notify_fail("船夫说道 : 既然如此我就不客气了!\n");
  }
 int accept_fight(object me)
 {
         return notify_fail("船夫叹道 : 真是没礼数的年轻人\n");
 }



