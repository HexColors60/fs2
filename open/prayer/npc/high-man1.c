//大徒弟
#include <command.h>
#include "/open/open.h"
 
inherit NPC;

void create()
{
    set_name("西域男子",({"man"}));
    set("gender", "男性");
    set("age",40);
    set("attitude","peaceful");
    set("long",@LONG

	他是广成派的弟子, 排行首位!!精通刀法!!

LONG);
 
    set("combat_exp",10000);
    set("str",36);
    set("con",34);
    set("int",22);
    set("max_kee",700);
    set("kee",700);
    set("max_force",500);
    set("force_factor", 10);
    set("force",500);
    set("limbs",({"头","手","脚","背","腹","腰"}));
    set_skill("dodge",60);
    set_skill("move",60);
    set_skill("parry",60);
    set_skill("force",60);
    set_skill("fireforce",60);
    set_skill("blade",60);
    set_skill("dragon-blade",60);
    map_skill("force", "fireforce");
    map_skill("blade", "dragon-blade");
    setup();
    carry_object("/open/port/obj/ghost_blade")->wield();
    
}

int accept_kill(object ob)
{
	if( ob->query("kill_high1") )
        {
        write("[36m少侠已经胜过在下,  恕在下不稍奉陪!![0m\n");
	return 0;
        }
	else
	{
        tell_object( ob ,"[36m奉师尊之命与少侠切磋几招!![0m\n");
        return 1;
	}
}

void die()
{
    object ob;
    ob= this_object()->query_temp("last_damage_from");
    if( ob && userp(ob) ) 
    {
    ob->add("potential", 10000);
    ob->set("kill_high1", 1);
    write("[36m少侠武学进展之快, 令在下可敬可佩!![0m\n");
    }
    ::die() ;
}


