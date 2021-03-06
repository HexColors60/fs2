#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit SSERVER;

string ask_roger();
string ask_array();
string ask_fish();
string ask_yao();
string ask_quest();
string ask_broken();
string ask_ball();
void create()
{
	set_name("平民", ({"man"}));
	set("age",33);
    set("long","谜一般的神秘男子，似乎已经在武林中打滚多年，像是在寻找某些东西。\n");
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
	set("random_move",200);
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
    set("chat_msg",({
       (: random_move :),
	}));
	set("chat_chance_combat",25);
	set("chat_msg_combat",({
	"流浪者说: 唉~就是找不到...",
	}));
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
  "李梦枕" : (:ask_roger:),
  "五行封印" : (:ask_array:),
  "仙剑山脚下的娃娃鱼" : (:ask_fish:),
  "血魔" : (:ask_quest:),
  "破解之道" : (:ask_broken:),
  "五行宝珠" : (:ask_ball:),

  "逍遥子" : (:ask_yao:),
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
message_vision(HIY"流浪者运起身上无极刀气，顿时刀芒充斥四周！

     "HIC"★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆"HIW"

            流浪者怒吼：看我的‘破体无形刀’！！！

     "HIC"★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆"HIY"
      瞬间，由流浪者身上射出无数逐渐凝聚而成的刀芒！
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
    message_vision(HIM"流浪者运起全身仙云之气，瞬间整个空间皆被红光包围，红光消失后，流浪者神色为之一亮。\n"NOR,me);
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
 string ask_roger()
{
 if(!this_player()->query_temp("find_roger"))
 {
  this_player()->set_temp("find_roger",1);
  return ("耸了耸肩，很抱歉地说：无可奉告。");
  }
 if (this_player()->query_temp("find_roger")==1)
  {
  this_player()->set_temp("find_roger",2);
  return ("李梦枕...没听过ㄝ.");
  }
 if (this_player()->query_temp("find_roger")==2)
  {
  this_player()->set_temp("find_roger",3);
  return ("嗯..这个嘛..嗯~~。");
 }
 if (this_player()->query_temp("find_roger")==3)
  {
  this_player()->set_temp("find_roger",4);
  return ("嗯..这个嘛..嗯~~。");
  }
 if (this_player()->query_temp("find_roger")==4)
  {
  this_player()->set_temp("find_roger",5);
  return ("阿..我不知道啦..烦不烦阿 一直问...我都烦死了~~。");
  }
 if (this_player()->query_temp("find_roger")==5)
  {
  this_player()->set_temp("find_roger",6);
  return ("你去找别人吧..这..我实在是不想跟你说。");
  }
 if (this_player()->query_temp("find_roger")==6)
  {
  this_player()->set("quests/find_roger",1);
  return ("唉~我就是李梦枕.你找我究竟有什么事??.");
 }
}
string ask_yao()
{
 if(!this_player()->query("quests/find_roger"))
 {
  return ("耸了耸肩，很抱歉地说：无可奉告。");
  }
 else
  {
  return ("你说师父,唉~他被血魔用五行封印,封印在仙剑山脚下的娃娃鱼身上.");
  }
}
string ask_array()
{
 if(!this_player()->query("quests/find_roger"))
 {
  return ("耸了耸肩，很抱歉地说：无可奉告。");
  }
 else
  {
  return ("五行封印,这是血魔的血咒之一,师父在封印他之后,就不慎中招,至今我还找不到对策");
  }
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
 if(!this_player()->query("quests/find_roger")||this_player()->query("quests/shatime")>1)
 {
  return ("耸了耸肩，很抱歉地说：无可奉告。");
  }

 else
  {
  this_player()->set_temp("shaswordtime",1);
  this_player()->apply_condition("shaswordtime",100);
  this_player()->set("quests/shatime",1);
  return ("五行宝珠金木水火土，分散各地，看样子我们分头找，希望能尽快找到，我想越快越好..就以两个时辰为限，两个时辰后我会找你回来，你可以往各个相关地方去搜索");
  }
}


