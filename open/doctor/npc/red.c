#include <ansi.h>
#include <command.h>
#include "/open/open.h"
inherit NPC;
void create()
{
    set_name("红衣人",({"red man","man"}));
    set("gender", "男性");
    set("age",68);
    set("attitude","peaceful");
    set("long",@LONG

        他是银针门藏经阁神秘黑衣老人的的弟子, 排行第二!!精通鞭法!!
LONG);

    set("combat_exp",100000);
    set("str",36);
    set("con",34);
    set("int",22);
    set("max_kee",900);
    set("kee",900);
    set("max_force",900);
    set("force_factor", 10);
    set("force",500);
    set_skill("dodge",60);
    set_skill("move",60);
    set_skill("parry",60);
    set_skill("force",60);
    set_skill("sixforce",60);
    set_skill("whip",60);
    set_skill("gwhip",60);
    map_skill("force", "sixforce");
    map_skill("whip", "gwhip");
    setup();
    carry_object("/open/poison/obj/snake_whip")->wield();

}
void die()
{
    object ob;
    ob= this_object()->query_temp("last_damage_from");
    if( ob && userp(ob) )
    {
    ob->set("red", 1);
    ob->delete("yellow");
    tell_object( ob ,"[1;33m少侠武学深不可测, 令人可敬!![0m\n");
    }
    ::die() ;
}
void greeting(object ob)
{
        if( ob->query("yellow") ==1 ) 
{
        command("say 奉师尊之命与少侠切磋几招!!");
        kill_ob(ob);
}
}


