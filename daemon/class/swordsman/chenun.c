#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
object ob2;
int have_say;
void create()
{
        set_name("张乘云", ({"chen un","un"}));
        set("long","郑士欣二第子,与其兄乘风同时进入仙剑派,乘云在剑法上虽已明显
落后于乘风,但说到内力深厚,仙剑派中除了掌门人郑士欣,无人能及
乘云项背,兄弟两因行侠于江湖,而并称风云双侠.乘云平时负责看管
藏经阁.\n");
        set("gender","男性");
        set("class","swordsman");
        set("combat_exp",500000);
        set("attitude","heroism");
        set("age",43);
        set("nickname","风云双侠");
        set("title","仙剑派第四代二弟子");
        set("kee",1500);
        set("max_kee",1500);
        set("gin",1500);
        set("max_gin",1500);
        set("sen",1500);
        set("max_sen",1500);
        set("force",1800);
        set("max_force",1800);
        set("force_factor",10);
        set("sha-stop-2",1);
        set_skill("array",80);
        set_skill("sha-array",80);
        set_skill("sword",80);
        set_skill("dodge",70);
        set_skill("shaforce",50);
        set_skill("shasword",80);
        set_skill("move",80);
        set_skill("parry",100);
        set_skill("sha-steps",70);        
        set_skill("force",50);
        map_skill("sword","shasword");
        map_skill("array","sha-array");
        map_skill("parry","shasword");
        map_skill("force","shaforce");
        map_skill("dodge","sha-steps");
        set("str", 30);
        set("con", 30);
        set("int",20);
        set("per",40);
        setup();
        carry_object("/open/gsword/obj/sword-2")->wield();
        create_family("仙剑派",4,"弟子");
        add_money("gold",5);
}

int accept_fight(object me)
{
  if((int)me->query("combat_exp")<=80000)
  {
  command("say 刀剑无眼,伤了你就不好了");
  return 0;
  }
  command("say 出招吧!");
  ob2=this_player();  
  return 1;
 }

int accept_kill(object me)
{
   ob2=this_player();
   return 1;
 } 

void attempt_apprentice(object ob)
{
        if(!ob->query_temp("allow_2"))
        {
        command("say 没有师父的同意，我不敢擅自收徒!");
        return 0;
        }
        command("smile");
        command("say 既然是师父的意思，以后你就跟我好好学吧!");
        command("recruit "+ob->query("id"));
        ob->set("marks/仙剑七侠",1);
}

int accept_object(object who,object ob)
{
	if( ob->query("id")!= "pass" )
	{
	write("张乘云说 你给我这个做什么??不过 ,看在你一份心意上 ,我还是接受了吧 \n");
	return 0;
	}
	else 
	{
	write("张乘云说: 看来你已经得到掌门得许可了，你就进去藏经阁吧!\n");
	write("不过.....我怀疑掌门人是否看错人了...让我来领教一下你的武功吧!\n");
	command("drop pass");
	command("kill "+who->query("id")); 
	have_say=0;
	return 1;
	}
}

void heart_beat()
{
	int kee;
    if(!ob1 || !ob2) return ;
	kee= ob1->query("max_kee");
	if( ob1->query("kee") < 0.4*ob1->query("max_kee") && ob2->query_temp("allow_pass",1) )
	{
        ob1->remove_all_killer();
        if(have_say==0)
        {
        message_vision("张乘云说: 等一下～～我认输了..............\n",this_object());
	if(!ob2) return ;
        if( ob2->query_temp("allow_pass",1) )
	{
	message_vision("看来你的确有这个实力，希望你学成之后能对仙剑做些有益的事，光大仙剑的武功\n",ob2);
	message_vision("好了，你可以进去了\n",ob2); 
	have_say=1;
	ob1->set("kee",kee);
	ob1->set("eff_kee",kee);
	ob2->set_temp("allow_read",1);
	}
        }
      } 
	::heart_beat();
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

	if( winner->query_temp("allow_pass",1) )
	{
	write("张乘云说: 看来你的确有这个实力，希望你学成之后能对仙剑做些有益的事，光大仙剑的武功!\n");
	write("好了，你可以进去了!\n");
	winner->set_temp("allow_read",1);
	}

	if ( winner->query_temp("bless")==1 )
	{
	j=random(6000);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {      
	  new("/open/sky/obj6/prairie_diamond")->move(environment(winner));
	  message_vision(HIM"\n从张乘云的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/prairie_diamond",sprintf("%s(%s) 让张乘云掉下了草原之青钻于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj6/prairie_diamond")->move(environment(winner));
	  message_vision(HIM"\n从张乘云的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/prairie_diamond",sprintf("%s(%s) 让张乘云掉下了草原之青钻于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();
}  
 
