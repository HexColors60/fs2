// chen.c
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("陈玄龙", ({ "hong_son_chen", "chen", }) );
        set("title"   , "拳法教头");
        set("nickname", "浩气长存");
        set("gender"  , "男性" );
        set("age", 27);
        set("str", 30);
        set("int", 29);
        set("long","陈玄龙是泷山武馆的拳法教头,泷山拳的造诣以达出神入化的境界再加上其心思慎密,所以被任正晴所看重,看管所有弟子。\n");

        set("attitude"      , "heroism");
        set("combat_exp",400000);
        set("force"         , 2500);
        set("max_force"     , 2000);
        set("force_factor"  , 10);
        set("super_fire",1);
         set("env/狂击","YES");
        set_skill("lungshan", 80);
        set_skill("dodge"   , 50);
        set_skill("haoforce", 50);
        set_skill("force"   , 70);
        set_skill("unarmed", 90);
        set_skill("parry", 60);
        set_skill("dodge",40);
        set_skill("henma-steps",40);
        set_skill("fire-kee",60);
        map_skill("force", "haoforce");
        map_skill("unarmed", "lungshan");
        map_skill("dodge", "henma-steps");
        map_skill("parry", "fire-kee");
        set("chat_chance_combat",65);
        set("chat_msg_combat",({
//             (: perform_action, "force.kang_kee"   :),
//              (: "cmd god_kee"   :)
        }));
        setup();
        carry_object(__DIR__"obj/fight_robe")->wear();
       carry_object("/open/wu/obj/ring1.c")->wield();
        add_money("gold", 8);
}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="泷山派" ) {
                command("nod");
                command("say 出招吧!");
                return 1;
        }
        command("say 掌门吩咐过，不许和来这里的客人过招。");
        return 0;
}
