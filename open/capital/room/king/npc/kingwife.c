#include <ansi.h>

inherit NPC;

string ask_me(object who);
int accept_kill(object who);

void create()
{
        set_name("钟妃", ({ "King girl", "girl" }) );
        set("title", "当今皇后");
        set("gender", "女性" );
        set("age", 22);
        set("str", 22);
        set("cor", 30);
        set("cps", 21);
        set("int", 25);
        set("per", 29);
        set("long",
                "钟妃就是当今圣上的正室, 乃为凤仪天下之皇后\n" );
        set("combat_exp", 30000);
        set("attitude", "heroism");
        set("chat_chance", 15);
        set("chat_msg_combat", ({
                "钟妃说道：大胆狂徒, 竟敢来皇城撒野？\n",
                "钟妃说道：来人啊..有刺客!!\n",
           }) );
        set("force_factor",80);
        set_skill("force",120);
        set_skill("dodge",120);
        set_skill("parry",120);
        set_skill("dagger",120);
        set_skill("fireforce",120);
        set_skill("bss-steps",120);
        set_skill("fly-circle",120);
        set_skill("bss-parry",120);
        map_skill("dodge","bss-steps");
        map_skill("dagger","fly-circle");
        map_skill("force","fireforce");
        map_skill("parry","bss-parry");
        set("force",50000);
        set("max_force",50000);
        set("force_factor",80);
        set("max_gin",3000);
        set("gin",3000);
        set("max_kee",10000);
        set("kee",10000);
        set("max_sen",3000);
        set("sen",3000);

        setup();

        carry_object("/open/capital/room/king/obj/dagger1")->wield();
}

int accept_kill(object who)
{
        int i;
        object ob, guard;
        ob = this_object();

        if( !present("king guard", environment(ob)) ) {
        tell_room(environment(ob),HIW"\n突然！冲出五位御前护卫！\n\n"NOR);
     for(i=0;i<5;i++)
     {
        guard = new(__DIR__"fuguard");
        guard->move(environment(ob));
        guard->command("defend girl");
        guard->command("follow girl");
        guard->kill_ob(who);
        }
        }
     tell_object(users(),HIR "御前护卫大叫：有刺客！快保护殿下！！\n" NOR);
        return 1;
}
