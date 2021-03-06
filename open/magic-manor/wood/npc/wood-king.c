inherit NPC;
#include "/open/open.h"
#include <ansi.h>

void create()
{
        set_name("木燃落", ({ "wood king","wood","king" }) );
        set("long","木灵塔的镇塔之王，能力比小木妖和木灵兽不知强上几倍。\n");
        set("title",HIG"(绿色灵气)"NOR"木灵塔王"NOR);
        set("family/family_name","仙剑派");
	set("gender","男性");
        set("class","swordsman");
        set("age", 60);
        set("max_gin", 50000);
        set("max_kee", 50000);
        set("max_sen", 50000);
        set("max_force", 20000);
        set("force",20000);
        set("max_atman",50000);
        set("max_mana",50000);
        set("atman",50000);
        set("mana",50000);
        set("force_factor",20);
        set("attitude","aggressive");
        set("str", 35);
        set("cor", 35);
        set("spi", 35);
        set("int", 35);
        set_temp("apply/armor", 150);
        set_temp("apply/defense", 250);
	set("s_kee",1000);
	set("max_s_kee",1000);
	set("sec_kee","god");
        set("bellicosity",10000);
	set("functions/sha_kee/level",100);
        set_skill("sword",150);
        set_skill("shasword",150);
        set_skill("sha-steps",150);
        set_skill("move",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("force",150);
	set_skill("shaforce",150);
        map_skill("dodge","sha-steps");
        map_skill("move","sha-steps");
	map_skill("parry","shasword");
        map_skill("sword","shasword");
	map_skill("force","shaforce");

        set("combat_exp", 8000000);
	set("wood-monster",1);
	set("get_sha_sp", 1);
	set("bounds", 40000);
        set("chat_chance_combat",20);
        set("chat_msg_combat",({   (: perform_action,"sword.sha_kee" :)   }) );
        setup();
	add_money("cash",500);
        carry_object("/open/magic-manor/wood/obj/wood-sword")->wield();
}

void heart_beat()
{
    object mob,me,obj;
	mixed enemy;
	int i,j=0,k=random(2);
    mob = this_object();
    me = this_player();
	enemy = all_inventory( environment(mob) );
    i = sizeof(enemy);

	if( !mob->is_fighting() || mob->is_fighting() )
	{
	  for (j=0 ; j < i ; j++)
	  {
	    if( !enemy[j] ) continue;
 	    {
 	    if (!enemy[j]->is_fighting() && enemy[j]->is_character() && !enemy[j]->is_corpse() 
	    && living(enemy[j]) && !enemy[j]->query("wood-monster") ) 
	    mob->kill_ob(enemy[j]);
	    }
	  }
	}

	if( random(10) > 6 && mob->is_fighting() )
	{
	message_vision(HIM"\n木影丛丛，森然罗列，草木轻扬于风中，$N有感于此身形微动随意发出

            "HIW"----===≡◎ 木影森罗式 ◎≡===----
                 "NOR+GRN"  ‘"HIG"木光流莺．惊天鸣"NOR+GRN"’\n\n"NOR,mob);
          for (j=0 ; j < i ; j++)
          {
	    if( !enemy[j] ) continue;
 	    {
              if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j])
              && !enemy[j]->query("wood-monster") )
              {
		if( !enemy[j]->query_temp("magic-manor/gold-shield") )
		{
		message_vision(HIG"$N"HIG"已经避无可避，只能眼睁睁的让蔓藤在身上刺出无数血痕!!\n"NOR,(enemy[j]));
		enemy[j]->receive_wound("kee",600);
		enemy[j]->start_busy(1);
		COMBAT_D->report_status(enemy[j]);
		}else{
		message_vision(HIY"$N"HIY"身上的金灵之气缓和了部份的蔓藤的刺击!!\n"NOR,(enemy[j]));
		enemy[j]->receive_wound("kee",300);
		enemy[j]->start_busy(k);
		COMBAT_D->report_status(enemy[j]);
		}
              }
	    }
	  }
	}   
	set_heart_beat(1);
	::heart_beat();
   
}

void die()
{
	object me=query_temp("last_damage_from");

	if( !me->query_temp("magic-manor/woodmagic") )
	{
	message_vision(HIG"木燃落死后的灵魂忽然化为一道绿色灵光，灌入了$N"HIG"的身体之中!!\n"NOR,me);
	me->set_temp("magic-manor/woodmagic",1);
	}
	me->delete_temp("magic-manor/breakwood",1);
    message_vision("\n\n塔身因为木灵王的灭亡而慢慢的出现了一些裂痕.....\n",me);

	:: die();
}

int accept_fight(object who)
{
	command("cmd god_kee");
	fight_ob(who);
	command("perform sword.sha_kee");
	return 1;
}

int accept_kill(object who)
{
	kill_ob(who);
	command("cmd god_kee");
	command("perform sword.sha_kee");
	return 1;
}