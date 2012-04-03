#include <ansi.h>
inherit NPC;

void create()
{
        seteuid(getuid());      // 这行一定要
        set_name("闇界杀手", ({ "killer" }) );
        set("attitude","aggressive");
        set("race", "人类");
        set("gender", "男性");
        set("age", 35);
        set("long", "
他....长的很丑....没啥吸引力....
乃武林中的烂人....江湖上的败类。\n");
        set("str", 30);
        set("cor", 30);
        set("max_kee", 1000);
        set("max_force", 500);
        set("force", 500);
        set("force_factor", 5);
        set("combat_exp", 400000);
        set_skill("unarmed", 80);
        set_skill("parry", 80);
        set_skill("force", 80);
        set_skill("haoforce",80);
        set_skill("lungshan", 70);
        set_skill("sha-steps", 60);
        map_skill("unarmed","lungshan");
        map_skill("dodge","sha-steps");
        map_skill("force","haoforce");
        set("chat_chance", 8);
        set_temp("apply/armor", 60);

        setup();
        add_money("gold",3);
}

