// trainer2.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("任青云", ({ "fist_trainer jen", "jen", "trainer" }) );
        set("title"   , "拳法教练");
        set("nickname", "小李靖");
        set("gender"  , "男性" );

        set("age", 26);
        set("str", 26);
        set("int", 29);

        set("long",
                "任青云是正晴武馆的拳法教练, 亦是任家的二儿子, 尽管年纪轻但他的\n" +
                "拳法却是此馆数一数二的。由于他自小天资优于其他手足, 又酷爱读书\n" +
                "使的他成为平南城著名的文武全才, 所以有‘ 小李靖 ’之称。\n" );

        set("attitude"      , "heroism");

        set("combat_exp",300000);
        set("force"         , 300);
        set("max_force"     , 300);
        set("force_factor"  , 10);

        set("inquiry", ([
                "here": "这里是任家正晴武馆, 请问有何事指教?\n",
                "name": "在下姓任, 名青云, 是本馆的拳法教练\n",
                "lungshan": "这个啊..此为本馆绝学, 在下对此颇有心得, 承蒙家父传授。\n",
        ]) );

        set_skill("literate", 80);
        set_skill("lungshan", 50);
        set_skill("dodge"   , 50);
        set_skill("haoforce", 50);
        set_skill("force"   , 70);

        map_skill("unarmed", "lungshan");
        map_skill("dodge"  , "lungshan");
        map_skill("force"  , "haoforce");

        setup();
        set("chat_chance"   , 25);
        set("chat_msg",
             ({
                // HIW "论语曰: 大道之行 , 天下为公也.......\n"NOR,
                HIW "礼记礼运大同篇: 大道之行 , 天下为公也.......\n"NOR,
                HIW "任青云喃喃说道: 书是吾人至宝, 怎能弃之！\n"NOR,
                HIW "任青云大叫一声: 啊! 父亲给我的\"浩日心经\"呢？又不见了！我的记性真差！\n"NOR,
             })
           );

        setup();
        carry_object(__DIR__"obj/fight_robe")->wear();
carry_object("/open/wu/npc/obj/silverclaw.c")->wield();

}

int recognize_apprentice(object ob)
{
        if( (string)ob->query("family/family_name")=="泷山派" ) return 1;

        command("say 抱歉，这位" + RANK_D->query_respect(ob) + "，您不是我们武馆的弟子。");
        return notify_fail( "任青云不愿意教你拳法。\n");
}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="泷山派" ) {
                command("nod");
                command("say 出招吧!");
                return 1;
        }
        command("say 馆主吩咐过，不许和来这里的客人过招。");
        return 0;
}
