inherit NPC;     //百里勇 2000.4.2 by dhk
#include <ansi.h>
#include </open/open.h>
inherit F_MASTER;
string do_special_fight();

void create()
{
  set_name("百里勇",({"ung baily","ung","baily"}));
  set("long","百里勇乃是段氏嫡族中肩负、担任晶谷守关的四天王之一，\n"
            +"其刀术乃族中的第一把交椅，而且他爱刀如命。他一直认为\n"
            +"如果能拥有一把真正的好刀就可以在‘"HIR"刀"NOR"’的境界上更上一\n"
            +"层楼、更进一步。听说他最近在找一把传说中刀中之刀。\n");
  set("gender","男性"); 
  set("class","blademan");
  set("title","段家第十代刀宗");
  set("nickname",""HIR"万刃刀圣"NOR"");
  set("attitude","heroism");
  set("age",35);
  set("max_kee",5000);
  set("kee",5000);
  set("str",44);
  set("per",24);
  set("cps",18);
  set("cor",42);
  set("int",42);
  set("max_force",15000);
  set("force",15000);
  set("force_factor",10);
  set("combat_exp",9000000);
  set_skill("dodge",100);
  set_skill("move",100);
  set_skill("force",160);
  set_skill("parry",90);
  set_skill("literate",100);
  set_skill("blade",120);
  set_skill("linpo-steps",100);
  set_skill("gold-blade",100);
  set_skill("fast-blade",100);
  set_skill("sixforce",160);
  set_temp("apply/armor",100);
  map_skill("blade","fast-blade");
  map_skill("parry","gold-blade");
  map_skill("move","linpo-steps");
  map_skill("dodge","linpo-steps");
  map_skill("force","sixforce");
  set("chat_chance_combat",100);
  set("chat_msg_combat",({
     (:do_special_fight:),
     }));
  set("chat_chance",10);
  set("chat_msg", ({
            ""+HIC+"百里勇自言自语的道: 登峰造极的‘刀’是我尽管花尽我一生的精华，所追求的目标。"+NOR+"\n",
            ""+HIC+"百里勇对着手上的刀说: 我手上这把"+HIY+"紫金"+HIC+"堪称刀中之刀，但世上还有一把比之更具霸气的刀。"+NOR+"\n",
            ""+HIY+"百里勇叹道: 真想见识一下传闻中的最狂的刀"+HIR+"～"HIC"太皇刀─蓝牙"+HIY+"呀！"+NOR+"\n",
               }));
setup();
  add_money("gold",10);
  carry_object("/daemon/class/blademan/obj/gold-blade")->wield();
  carry_object("/open/ping/questsfan/obj/diamond_legging")->wear();
  carry_object("/open/ping/questsfan/obj/diamond_hands")->wear();
  create_family("金刀门",10,"刀宗");
}
string do_special_fight()
{
  if(query_skill_mapped("blade")=="gold-blade"){
  command("perform blade.gold-dest");
  if(!query_temp("fast/time"))
  map_skill("blade","fast-blade");
  }
  else if(query_skill_mapped("blade")=="fast-blade"){
  command("perform blade.fast-dest");
  map_skill("blade","gold-blade");
  }
  command("perform blade.gold-dest");
  return "";    
}
void init()
{
        add_action("do_answer","answer");
        set_heart_beat(1);
}
void heart_beat()
{
        if( random(4) < 1 ){
        if( is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
        else{
                if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
        }
        }
        :: heart_beat();
}

int accept_object(object me, object obj)
{
    if( obj->query("id") == "kingblade bluetooth" )
      {
        command("smile "+getuid(me));
        command("say 嗯...这是要送我的吗？谢了。");
         if( me->query("family/family_name") == "段家")
          {
            command("say 百里勇神情自若的对你说道:在下只是镇守第一关的关主，往后还得靠你自己，请吧!!!\n");
            me->set("questsfan/quest_step", 3);
          }
        destruct(obj);
      }
    else
      command("? "+getuid(me));
    return 1;
}
