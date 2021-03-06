// by roger

#include <ansi.h>
#include "castle.h"
inherit NPC;
inherit SSERVER;
void create() {
        
        set_name("灰衣魔将",({"seven-dark"}));
        set("long",
   "\n银闪灰衣, 其人如风飘逸, 腰上配剑魔光闪闪, 更显英气.\n");

        set("age",3121);
        set("str",35);
        set("cor",35);
        set("race","人类");
        set("gender","雄性");
        set("attitude","aggressive");
        set("class","fighter");
        set("bellicosity",500);
        set("max_gin",13000);
        set("max_kee",13000);
        set("max_sen",13000);
        set("max_force",15000);
        set("force",15000);
        set("force_factor",49);
        set("combat_exp",6300000);
        set_skill("sword",100);
        set_skill("dodge",100);
        set_skill("mogi-steps",100);
        set_skill("move",80);
        set_skill("parry",100);
        set_skill("literate",130);
        set_skill("mogi-strike7",100);
        set("clan_kill",1);
        set_skill("force",120);
        set_skill("badforce",90);
        map_skill("sword", "mogi-strike7");
        map_skill("dodge","mogi-steps");
        map_skill("parry","mogi-strike7");
        map_skill("move","mogi-steps");
        map_skill("force","badforce");
        set("limbs",({"头部","胸部","背部","腰部"}));
        setup();
        carry_object(C_OBJ"/sword-1")->wield();
carry_object(C_OBJ"/ninepill");
        carry_object("open/mogi/castle/obj/seven4-dark-head");

        add_money("gold",5);
}

void heart_beat()
{
 object env,mob,*enemy,target;
 int i;

 mob = this_object(); 
 env = environment(mob);  

 if( !query("wield") )
 {
   set("wield",1);
   command("wield all");
 }
 
 if( random(100) < 18)
 {
    enemy=mob->query_enemy();
    i=sizeof(enemy);
    target=offensive_target(mob);
    if(!target) return ;
    if( env == environment(target) )
    {
      message_vision(HIW"\n
$N横剑心凝，神形意止，银封剑开起激出阴冷寒气，魔风狂舞围住了在
场所有的人，温度随着$N的意识直线降低     
瞬间，$N将银封剑直指向天，凛凛一式"HIC"「十等千断  寒水无封”"HIW"，凛冽
的魔风尽化利刃剑气，闻血而腥 
\n"NOR,mob,target);
      target->receive_damage("kee",550);
      target->start_busy(2);
      COMBAT_D->report_status(target, 1);
    }
 }  
   set_heart_beat(1);
   ::heart_beat();
   
}





