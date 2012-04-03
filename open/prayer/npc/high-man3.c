//三徒弟
#include <command.h>
#include "/open/open.h"
 
inherit NPC;

void create()
{
    set_name("西域男子",({"man"}));
    set("gender", "男性");
    set("age",23);
    set("attitude","peaceful");
    set("long",@LONG

	他是广成派的弟子, 排行第三!!精通剑术!!

LONG);
 
    set("combat_exp",3000);
    set("str",36);
    set("con",34);
    set("int",22);
    set("max_kee",100);
    set("kee",100);
    set("max_force",500);
    set("force_factor", 1);
    set("force",500);
    set("limbs",({"头","手","脚","背","腹","腰"}));
    set_skill("dodge",60);
    set_skill("move",60);
    set_skill("parry",60);
    set_skill("force",60);
    set_skill("fireforce",60);
    map_skill("force", "fireforce");
    set_skill("sword",60);
    set_skill("shasword",60);
    map_skill("sword", "shasword");
    setup();
    carry_object("/open/gsword/obj/woodsword")->wield();
}

int accept_kill(object ob)
{
	if( ob->query_temp("high-man") == 4 && !ob->query("quests/high-man") )
        {
        message_vision("[36m他突然狂性大发, 紧接着一剑刺穿了你的胸膛 .... [0m\n",ob);
        message_vision("\n",ob);
        tell_object( ob ,"[31m你的眼前一片黑暗......[0m\n");
        this_object()->remove_all_killer();
        ob->unconcious();
        load_object("/open/prayer/room/westarea/highroom");
        ob->move("/open/prayer/room/westarea/highroom");
        return 1;
        }
        else
        {
        return 1;
        }
}

