#include <ansi.h>
inherit NPC;
mapping *action = ({

([ "action" : "$N使出绝情神掌第一招"+HIY+"【亢龙有悔】"+NOR+"，右掌划了个圈圆，向$n的$l推去",
                "dodge"      :    -25,
                "parry"      :    -20,                                      
                "damage"     :    100,
                "damage_type":   "瘀伤",
           ]),
([ "action" : "$N使出绝情神掌第二招"+HIG+"【飞龙在天】"+NOR+"，犹如飞龙般跃起半空，居高下击，向$n
的$l击出",
                "dodge"      :     -50,
                "parry"      :     -10,
                "damage"     :     110,
                "damage_type":   "瘀伤",
           ]),
([ "action" : "$N使出绝情神掌第三招"+HIR+"【突如其来】"+NOR+"，于迅雷不及掩耳的速度，让$n攻其不备",
                "dodge"      :    -30,
                "parry"      :    -45,
                "damage"     :    130,
                "damage_type":   "瘀伤",
            ]),
([ "action" : "$N使出绝情神掌第四招"+HIB+"【双龙取水】"+NOR+"，左右分使绝情神掌，令$n无法敌挡，内
外皆受到极大的伤害", 
                "dodge"      :   -50,
                "parry"      :   -50,
                "damage"     :   150,
                "damage_type":   "瘀伤",
            ]),
   });

void create()
  {
        set_name("陈平", ({ "pin" }) );
        set("title","电护法");
        set("nickname","绝情门四弟子");
        set("gender", "男性");
        set("age", 18);
        set("long","他是绝情门的护法，但别看他年轻就小看他，他可是个在蒙古地区
得武术冠军的少年。\n");
        set("str", 48);
        set("cps", 40);
        set("per", 34);
        set("int", 38);
        set("kar", 16);
        set("combat_exp",600000);
        set("force" , 1100);
        set("max_force" , 1100);
        set("force_factor", 5);
        set_skill("unarmed", 60);
        set_skill("force", 50);
        set_skill("dodge",50);
        set_skill("linpo-steps",60);

        map_skill("dodge", "linpo-steps");
        set("chat_chance_combat",25);
        set_temp("apply/armor",70);
        set_temp("apply/damage",30);
        set("chat_msg", ({
             (: this_object(),"random_move" :),
        }) );
        setup();
carry_object("/open/love/obj/legging.c")->wear();
carry_object("/open/love/obj/ring.c")->wield();
        add_money("silver",10);
        set("default_actions", (: call_other, __FILE__,"query_action" :));

        reset_action();

}

mapping query_action()
{
        return action[random(sizeof(action))];
}
void greeting(object ob)
{
    int exp,lv_1;
    string skill;
    object weapon;
    exp =ob->query("combat_exp",1);
      weapon = ob->query_temp("weapon");
      if( weapon ) skill = weapon->query("skill_type");
      else skill = "unarmed";
      lv_1 =(int) 1.8 * ob->query_skill(skill, 1);
    return;
}
void heart_beat()
{
 object env,mob,*enemy,target;
 int i,kee;
 mapping exit;
 string *exit_name;

 mob = this_object();
 env = environment(mob);

  if( random(70) < 15)
 {
    enemy=mob->query_enemy();
	if( i = sizeof(enemy) ) {
    target=enemy[random(i)];
    kee = target->query("max_kee") * 0.2;
    if( env == environment(target) )
    {
     message_vision(HIW+"$N看见陈平，祭起"+HIY+"「绝情诀”"+HIW+"以精化气，以
气御神，以神聚力，只见陈平的"+HIR+"手臂通红"+HIW+"，
直向$N的"+HIR+"心脏"+HIW+"抓来，你顿时"+HIR+"血液完全被抽干\n"+NOR,target);
     target->receive_damage("kee",(int)kee,mob);
     COMBAT_D->report_status(target,0);
    }
	}
 }
 set_heart_beat(1);
  ::heart_beat();

}


