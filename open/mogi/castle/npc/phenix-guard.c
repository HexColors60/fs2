// by roger

#include <ansi.h>
#include "castle.h"
inherit NPC;
void create() {
	
	set_name("朱雀守卫",({"phenix guard","guard"}));
	set("long",
	    "\n他是厉害妖魔。\n");

	set("age",3121);
	set("str",35);
	set("cor",35);
	set("race","人类");
	set("gender","雄性");
	set("attitude","peaceful");
	set("class","fighter");
	set("bellicosity",9500);
	set("max_gin",3300);
	set("max_kee",12000);
	set("max_sen",3300);
	set("max_force",15000);
	set("force",15000);
	set("force_factor",35);
	set("combat_exp",4800000);
	set_skill("unarmed",120);
	set_skill("dodge",100);
	set_skill("mogi-steps",130);
	set_skill("move",40);
	set_skill("parry",100);
	set_skill("literate",130);
	set_skill("mogi-strike2",120);
	set_skill("force",120);
	set_skill("badforce",120);
	map_skill("unarmed", "mogi-strike2");
	map_skill("dodge","mogi-steps");
	map_skill("parry","mogi-strike2");
	map_skill("move","mogi-steps");
	map_skill("force","badforce");
	set("limbs",({"头部","胸部","背部","腰部"}));
	set("verbs",({"bite","claw"}));
	setup();
	add_money("gold",5);
 }
int accept_fight(object who)
{
return notify_fail("朱雀守卫说道 : 我没空陪你玩。\n");
}
int accept_kill(object who)
{
 who=this_player();
 command("hehe "+who->query("id"));
 command("exert roar");
 command("kill "+who->query("id"));
 return 1;
}
void die()
{    
	object winner = query_temp("last_damage_from");
	int j;

        if(!winner)
	{
	::die();
	return ;
        }	 
	if(random(100) > 50)	
	new("/data/autoload/mogi/blood-water")->move(environment(winner));
	else
	new("/data/autoload/mogi/blood-water-f")->move(environment(winner));
	tell_object(winner,HIM"\n你从朱雀守卫身上割下一颗黑色的心脏\n"NOR);

	if ( winner->query_temp("bless")==1 )
	{
	j=random(10000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj7/phoenix_order")->move(environment(winner));
	  message_vision(HIM"\n从朱雀守卫的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/u/n/neverend/log/phoenix_order",sprintf("%s(%s) 让朱雀守卫掉下了朱雀结令于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj7/phoenix_order")->move(environment(winner));
	  message_vision(HIM"\n从朱雀守卫的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/u/n/neverend/log/phoenix_order",sprintf("%s(%s) 让朱雀守卫掉下了朱雀结令于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();							     
} 								    

