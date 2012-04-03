
#include <ansi.h>
inherit NPC;
inherit SSERVER;
   
void create()
{
	set("long","
传说中的千年冰蟾，终年住在天邪峰上除了觅食外甚少出洞。它是只巨大的怪物
高度至少有七尺，皮肤呈带蓝色并且有着一粒粒的瘤物，看了就令人毛骨悚然的
怪物。\n
");
	set("race","野兽");
set("clan_kill",1);
        set("gender","雄性");
        set("attitude","aggressive");
        set_name("千年冰蟾",({"ice-frog","frog"}));
        set("combat_exp",3000000);
        set("bellicosity",3000);
	set("age",10000);
        set("max_force",5500);
        set("force",5500);        
        set("max_kee",6000);
        set("kee",6000);
        set("max_gin",3000);
        set("max_sen",3000);
        set("sen",3000);
        set("gin",3000);
	set("str", 35);
	set("cor", 35);
	set("cps", 30);
	set("per", 30);
	set("int", 30);
        set_skill("dodge",300);
        set_skill("parry",400);
        set_skill("unarmed",350);
        set_temp("apply/armor",100);
        set_temp("apply/damage",80);
        set("limbs",({"头部","胸部","蟾蜍眼","蟾蜍脚","背部"}));
        set("verbs",({"bite","claw"}));
	setup();
       
}

void heart_beat()
{
 object mob,*enemy,target;
 int i;
 mob=this_object();
 enemy=mob->query_enemy();
 i=sizeof(enemy);
 target=offensive_target(mob);
 if(!target) return ;
        if( random(100) < 15 ){
 message_vision(HIG"\n千年冰蟾从嘴里吐出一团绿雾笼罩住$N，使$N觉得头昏脑胀\n"NOR,target);
 target->add("eff_kee",-200);
 target->apply_condition("five_poison",random(5)); 
        }
	:: heart_beat();
}	
	   
void die()
{
 object me = query_temp("last_damage_from");
 new("/open/mogi/mountain/obj/frog-pill")->move(environment(me));
 tell_object(me,"千年冰蟾的竖目从额上掉了下来\n");
 :: die();
}                    
