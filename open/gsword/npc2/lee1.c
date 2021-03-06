#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit SSERVER;
string ask_fish();
string ask_yao();
string ask_quest();
string ask_broken();
string ask_ball();
string ask_gball();
string ask_fireball();
string ask_waterball();
string ask_woodball();
string ask_soilball();
void create()
{
set_name("李梦枕",({"roger lee","lee","roger"}));
        set("age",33);
    set("long","传说中金风细雨楼楼主，谜一般的神秘男子，似乎已经在武林中打滚多年，拥有无数迷团于一身，其武功似乎和其身家一样，无人知悉。\n");
        set("gender","男姓");
        set("str",50);
        set("cor",50);
        set("cps",50);
        set("int",50);
        set("con",50);
        set("spi",50);
        set("kar",50);
    set("class","swordsman");
    set("family/family_name","仙剑派");
        set("bellicosity",400);
        set("get_sha_sp",1);
        set("no_hire",1);
        set("max_kee",50000);
        set("kee",50000);
        set("max_gin",50000);
        set("gin",50000);
        set("max_sen",50000);
        set("sen",50000);
        set("combat_exp",10000000);
        set("max_force",50000);
        set("force",50000);
        set("force_factor",10);
        set_skill("dodge",200);
        set_skill("star-blade",200);
        set_skill("force",300);
        set_skill("sha-steps",100);
        set_skill("unarmed",120);
        set_skill("fireforce",100);
        map_skill("dodge","sha-steps");
        set_skill("stars-blade",150);
        set_skill("blade",120);
        map_skill("blade","star-blade");
        map_skill("force","fireforce");
    set("chat_chance",100);
        set("chat_chance_combat",25);
        set_temp("apply/armor",500);
        set_temp("apply/damage",80);
        set_temp("armor_vs_force",1500);
        set_temp("no_die_soon",1);
        set_temp("apply/armor",100);
        set_temp("apply/defense",100);
        set_temp("apply/damage",100);
        set_temp("apply/attack",100);
        set_temp("apply/dodge",50);
         set_temp("apply/parry",50);
set("inquiry",([
  "仙剑山脚下的娃娃鱼" : (:ask_fish:),
  "血魔" : (:ask_quest:),
  "破解之道" : (:ask_broken:),
  "五行宝珠" : (:ask_ball:),
  "逍遥子" : (:ask_yao:),
   "金法珠" : (:ask_gball:),
   "火法珠" : (:ask_fireball:),
   "水法珠" : (:ask_waterball:),
   "木法珠" : (:ask_woodball:),
   "土法珠" : (:ask_soilball:),
]));
    setup();
        carry_object("/u/a/appo/kdblade.c")->wield();
        add_money("gold",10);

}
void heart_beat()
{
 object me,*target;
 int i,j;
 i=sizeof(target);
 me=this_object();
 if(me->is_fighting()||me->is_killing())
 {
  target=me->query_enemy();
 if (random(10)<=4)
   {
message_vision(HIY"$N运起身上无极刀气，顿时刀芒充斥四周！

     "HIC"★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆"HIW"

            $N怒吼：看我的‘破体无形刀’！！！

     "HIC"★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆"HIY"
      瞬间，由$N身上射出无数逐渐凝聚而成的刀芒！
          转眼间，数百道刀芒已贯穿你的身体！！！
"NOR,me);
     me->delete_busy();
     me->clear_condition();
     for(j=0;j < i;j++)
     {
      target[j]->add("kee",-1500);
      target[j]->apply_condition("hellthunder",3);
       COMBAT_D->report_status(target[j]);
     }
   }
else
   {
 if ((random(2)+1)==1)
   {
    message_vision(HIM"李梦枕运起全身仙云之气，瞬间整个空间皆被红光包围，红光消似李梦枕神色为之一亮。\n"NOR,me);
    me->receive_curing("gin",3000);
    me->receive_heal("gin",3000);
    me->receive_curing("kee",6000);
    me->receive_heal("kee",6000);
    me->receive_curing("sen",3000);
    me->receive_heal("sen",3000);
    me->delete_busy();
    me->add("force",4000);
    me->clear_condition();
   }
}
if((me->query("eff_kee") < 6000 || me->query("kee") < 6000) &&!me->query("dead"))
{
    message_vision(HIM"$N叹道:真要逼我使出独门刀法吗??\n"NOR,me);
        me->set("force_factor",50);
        me->set("eff_kee",50000);
        me->set("kee",50000);
        me->set("eff_gin",50000);
        me->set("eff_sen",50000);
        me->set("gin",50000);
        me->set("sen",50000);
        me->set("force",100000);
        me->set("combat_exp",15000000);
        me->set("dead",1);
        map_skill("blade", "stars-blade");
        me->reset_action();
        me->delete_busy();
        me->clear_condition();
  }
}
else if( !is_fighting() ) {

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

string ask_yao()
{
  return ("你说师父，唉~他被血魔用五行封印，封印在仙剑山脚下的娃娃鱼身上，对了，你的五行宝珠呢?");
 }
string ask_fish()
{
 if(!this_player()->query("quests/find_roger"))
 {
  return ("耸了耸肩，很抱歉地说：无可奉告。");
  }
 else
  {
  return ("那是师父灵识所在..最近血魔气息翻动我想我要得加快脚步了");
  }
}
string ask_quest()
{
 if(!this_player()->query("quests/find_roger"))
 {
  return ("耸了耸肩，很抱歉地说：无可奉告。");
  }
 else
  {
  return ("我想,再过不了多久,血魔必重现江湖,我必须尽快找出破解之道");
  }
}

string ask_broken()
 {
 if(!this_player()->query("quests/find_roger"))
 {
  return ("耸了耸肩，很抱歉地说：无可奉告。");
  }
 else
  {
  return ("我曾找到过大破魔师于兰天武,他说我需要找齐五行宝珠才能破阵.");
  }
}
string ask_ball()
{
  return ("我们一个一个来对吧..你一个一个问我，确认完之后，就往娃娃鱼那去吧。");
 }


string ask_gball()
{
 if(!this_player()->query_temp("quests/findball1"))
 {
  new("/open/gsword/obj1/gball")->move(this_player());
  return ("这都办不好，我已经帮你找到了金法珠了，给你。");
  }
 else
  {
  this_player()->add("quests/sunmoon",2);
  return ("嗯，做的好~还好你找到了..否则我还找不着呢!!");
  }
}
string ask_fireball()
{
 if(!this_player()->query_temp("quests/findball2"))
 {
  new("/open/gsword/obj1/fireball")->move(this_player());
  return ("这都办不好，我已经帮你找到了火法珠了，给你。");
  }
 else
  {
   this_player()->add("quests/sunmoon",2);
  return ("嗯，做的好~还好你找到了..否则我还找不着呢!!");
  }
}
string ask_waterball()
{
 if(!this_player()->query_temp("quests/findball3"))
 {
  new("/open/gsword/obj1/waterball")->move(this_player());
  return ("这都办不好，我已经帮你找到了水法珠了，给你。");
  }
 else
  {
   this_player()->add("quests/sunmoon",2);
  return ("嗯，做的好~还好你找到了..否则我还找不着呢!!");
  }
}
string ask_woodball()
{
 if(!this_player()->query_temp("quests/findball4"))
 {
  new("/open/gsword/obj1/woodball")->move(this_player());
  return ("这都办不好，我已经帮你找到了木法珠了，给你。");
  }
 else
  {
   this_player()->add("quests/sunmoon",1);
  return ("嗯，做的好~还好你找到了..否则我还找不着呢!!");
  }
}
string ask_soilball()
{
 if(!this_player()->query_temp("quests/findball5"))
 {

  new("/open/gsword/obj1/soilball")->move(this_player());
  return ("这都办不好，我已经帮你找到了木法珠了，给你。");
  }
 else
  {
  this_player()->add("quests/sunmoon",1);
  return ("嗯，做的好~还好你找到了..否则我还找不着呢!!");
  }
}
