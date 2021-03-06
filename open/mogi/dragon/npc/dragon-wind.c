//by casey
#include <ansi.h>
inherit NPC;
mapping *action = ({
([ "action" :"$N"HIC"凶性大发 ,双翼狂振 ,卷起狂烈的真空气旋将$n整体围绕住"NOR"。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  290,
             "damage_type":  "割伤",
           ]),
([ "action" :"$N"HIC"迅速扑至$n面前 ,龙爪如旋风般朝$n直抓下去 ,$n当场鲜血飞溅"NOR"。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  280,
             "damage_type":  "抓伤",
            ]),
([ "action" :"$N"HIC"身形忽转 ,卷起一阵阵的狂风朝着$n袭去 ,狂猛的来势好不吓人"NOR"。",
             "dodge"      :  -30,
             "parry"      :  -25,
             "damage"     :  260,
             "damage_type":  "内伤",
            ]),
([ "action" :"$N"HIC"朝$n直抓了过去 ,挟带着狂风的真空爪劲 ,力道之猛 ,令人发指"NOR"。",
             "dodge"      :  -40,
             "parry"      :  -15,
             "damage"     :  275,
             "damage_type":  "抓伤",
            ]),
([ "action":"$N"HIC"狂吼长啸 ,天地为之色变 ,强劲气旋 ,$n的身体整个都被吞噬掉"NOR"。",
             "dodge"      : -10,
             "parry"      :  -20,
             "damage"     : 315,
             "damage_type":  "内伤",
           ]),
       });

void create()
{
     set_name(HIC"风龙"NOR ,({"wind dragon", "dragon"}) );
     set("race", "野兽");
     set("title", "守护者");
     set("age",2579);
     set("cor", 30);
     set("long","四条巨龙之一 ,是传说中上古时代的龙族\n");
     set("attitude","aggressive");   
     set_temp("apply/attack",130);
     set_temp("apply/damage",110);
     set_temp("apply/move",70);
     set("max_kee",7500);
     set("kee",7500);
     set("force",5000);
     set("max_force",5000);
     set("force_factor",37);
     set("max_gin", 7000);
     set("max_sen", 7000);
     set("combat_exp",2700000);
     set_skill("dodge",420);
     set_skill("parry",420);
     set_skill("unarmed",210);
 set("limbs", ({ "龙首", "龙身", "前肢" , "后足" , "龙尾" }) );
     setup();

 set("default_actions", (: call_other, __FILE__,"query_action" :));
         reset_action();
     set_heart_beat(1);
 add_money("gold",45);
}
mapping query_action()
{
   return action[random(sizeof(action))];
}

void heart_beat()
{
  object *enemy,me;
  int i;
  me = this_player();
  if( me->is_fighting() )
  {
    if( 80 > random(120) )
    {
      enemy = me->query_enemy();

      i=random(sizeof(enemy));

    message_vision(HIC+"天际狂风忽起 ,形成无数真空漩涡 ,$N被割的体无完肤!!!\n"NOR,enemy[i]);
      
      enemy[i]->receive_damage("kee", 100,me);
      COMBAT_D->report_status(enemy[i], 1);
     
     }
   }
   if( me->query("kee") < 0 )
      me->die();
   :: heart_beat();
}

 void die()                                                                 
{
    object winner = query_temp("last_damage_from");        

    new("/open/mogi/dragon/obj/wind")->move(environment(winner));
     new("/open/mogi/dragon/obj/wind-1")->move(environment(winner));

   tell_object(winner,HIY"\n\n经过一番血战后 ,风龙终于被你降服了\n\n"NOR);            
  tell_object(winner,HIC"\n风龙自口中吐出一块宝玉\n\n\n"NOR);                             
               destruct(this_object());
                                                                    
            ::die();                                                           
      }                    













