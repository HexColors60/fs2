#include <ansi.h>
inherit NPC;
inherit SSERVER;

void create()
{
	set_name("血魔将", ({"bloodknight","knight"}));
	set("age",100);
	set("long","血魔手下之精锐部队，为穴魔出生入死在所不辞。\n");
	set("gender","男姓");
	set("str",30);
	set("con",30);
	set("class","fighter");
	set("family/family_name","血魔一族");
	set("bellicosity",3500);
	set("get_sha_sp",1);
	set("no_hire",1);
	set("max_kee",30000);
//	set("attitude","aggressive");
	set("kee",30000);
	set("max_gin",10000);
	set("gin",10000);
	set("max_sen",10000);
	set("sen",10000);
	set("combat_exp",3000000);
	set("max_force",10000);
	set("force",10000);
	set("force_factor",20);
	set("random_move",200);
	set_skill("dodge",120);
	set_skill("force",150);
	set_skill("sha-steps",100);
	set_skill("unarmed",120);
	set_skill("blood_force",100);
	map_skill("dodge","sha-steps");
	set_skill("sword",120);
	set_skill("bloods_sword",120);
    map_skill("force","blood_force");
	map_skill("sword","bloods_sword");
	map_skill("force","haoforce");
    set("chat_chance",100);
    set("chat_msg",({
       (: random_move :),
	}));
	set("chat_chance_combat",25);
	set("chat_msg_combat",({
	"血魔将说 :杀杀杀杀!!!\n",
	}));
	set_temp("apply/armor",500);
	set_temp("apply/damage",80);
	set_temp("roared",1);
	setup();
    carry_object("/open/gsword/obj1/sadsword.c")->wield();
}
void greeting( object ob )
{   
    if( !ob || environment(ob) != environment() ) return;
	if(ob->query("combat_exp")>1500000)
	{    
     write( HIY"血魔将说道:死吧....人类\n"NOR );
	 command("kill ob");
	 command("follow ob");
	 kill_ob(ob);
	}
}
void heart_beat()
{
        object *enemy,*all,me;
        int i,j;
        me=this_object();
        j=random(100);
        if(!me) return ;
        if(!environment(me)) return ;
		all=all_inventory(environment(me));

	 if( j> 50 && is_fighting() )
          {
          enemy = me->query_enemy();
            i=random(sizeof(enemy));
              if(enemy[i])
              if(environment(me) == environment(enemy[i]))
              {
	      message_vision(HIR"$N高喊:该死的人类...看我的血魔无极杀。\n"NOR,me,enemy[i]);
              message_vision(HIW"‘"HIR"血 染 大 地 盖\ 红 尘"HIW"，"HIR"魂 迫 四 方 斩 无 边"HIW"’\n‘"HIY"哈！！血 霸 天 下"HIW"’，$N极招一出造成大地崩裂，江河逆流，$n瞬间遭血气掩没。\n"NOR,me,enemy[i]);
              enemy[i]->receive_damage("kee", 3000);
              enemy[i]->receive_wound("sen", enemy[i]->query("max_sen",1)/10);
              enemy[i]->receive_wound("gin", enemy[i]->query("max_gin",1)/10);
              enemy[i]->start_busy(1);
              COMBAT_D->report_status(enemy[i], 1);
              }
              me->delete_busy();
            }
        
  	if( !is_fighting() ) {
		
		if( query("eff_kee") < query("max_kee") ) 
			me->receive_curing("kee",100);
		if( query("eff_gin") < query("max_gin") )
		    me->receive_curing("gin",100);
		if( query("eff_sen") < query("max_sen") )
		    me->receive_curing("sen",100);
		if( query("gin") < query("eff_gin") ) 
			me->receive_heal("gin",100);
		if( query("kee") < query("eff_kee") )
			me->receive_heal("kee",100);
		if( query("sen") < query("eff_sen") ) 
			me->receive_heal("sen",100);
		}
        set_heart_beat(1);
        :: heart_beat();
}

void die()                                                                 
{    
	object winner = query_temp("last_damage_from");
	int j;
	j=random(3);
        if(!winner)
	{
	::die();
	return ;
        }

	  tell_object(users(),HIR"\n血魔将吼道：\n\t"HIW"可恨阿~~想不到我百年功力竟不敌"+winner->query("name")+"！\n\t血魔殿下要记得帮我报仇阿！\n\n"NOR);
	  message_vision(HIY"\n"+winner->query("name")+"打死血魔将从血魔将身上取下五十点血印!!\n"NOR,winner);
          write_file("sword/get_bscore",sprintf("%s(%s) 得到五十点血印于 %s\n",winner->query("name"),winner->query("id"),ctime(time())));
	  winner->add("blood_score",50);
 	::die();
}


