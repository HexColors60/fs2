// 平南将军
#include </open/open.h>
#include <ansi.h>
inherit NPC;
void create()
{
	set("title","正五品督军");
	set_name("张渊",({"officer zhang","officer","zhang"}));
	set("long","朝庭派来平南督军的钦命大臣,他正为苗人的入侵(烦恼).\n");
	set("gender","男性");
        set("attitude","heroism");
	set("chat_chance", 15);
	set("chat_msg", ({
	" 张渊说: 苗军入侵联绵不断,如何是好??\n",
	" 张渊说: 来此督军,真是个苦差事啊!!\n",
	" 张渊说: 有能人侠士愿意伸出(援手)哉??\n"
	}));
	set("inquiry",([
	"烦恼" : "本朝与苗军对抗已数年了,如今骑虎难下,不知如何收场,唉...\n",
	"援手" : "擒贼先擒王,本官欲征一壮士,买(苗王)颈上人头!!\n",
	"苗王" : "壮士欲效力朝廷吗? 必有(重赏)!\n",
	"重赏" : "壮士请先杀掉苗军队长,拿其配刀来证明汝之忠诚,后话再叙.\n",
	]) );
	set("age",32);
	set("int",30);
	set("per",30);
	set("str", 15);
	set("con", 30);
	set("force",1500);
	set("max_force",1500);
        set("combat_exp", 37500);
	set_skill("literate",40);
	set_skill("force",60);
        set_skill("dodge", 1);
        set_skill("parry", 1);
        set_skill("unarmed",45);
        set_skill("linpo-steps",1);
        set_skill("six-fingers",45);
	map_skill("dodge","linpo-steps");
	map_skill("parry","six-fingers");
        map_skill("unarmed","six-fingers");
        map_skill("stabber","six-fingers");
        set("functions/handwriting/level",10);
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
           (: perform_action("stabber.handwriting") :),
           }));        
        set("force_factor", 3);
	setup();
	carry_object("/open/ping/obj/fan-1")->wield();
	carry_object("/open/ping/obj/robe-1")->wear();
	carry_object("/open/ping/obj/wrists-1")->wear();
	add_money("silver",50);
}
int accept_object(object who, object ob)
{
  object mid;
  if( ob->query("id") == "maiu blade")
  { 
    destruct(ob);
    who->set_temp("maiu",1);
    say("正五品督军 张渊对苗刀详细审视,说道: 果真是苗军队长的配刀.\n"+
        "那...这是我方忍者盗得的信物,拿这个给苗人军师,便可见到苗王,\n"+
        "至时,杀了苗王,取其人头来见我即可,本朝必然不会亏待你.\n");
    mid=new("/open/ping/obj/mid");
    mid->move(who);
  }      
  else if( ob->query("id") == "maiu-head" && who->query_temp("maiu") )
  { 
   destruct(ob);
   say("正五品督军 张渊审视人头一番,大笑曰: 终于死了,你这老头...哈哈哈!!!\n"+
       "那...这是给你的谢礼.\n正五品督军给你一些药丸.\n");  
   mid=new("/daemon/class/doctor/medicine/curesick");
   mid->add_amount( who->query("per") );
   mid->move(who);
   who->delete_temp("maiu");
   who->delete_temp("k_m"); 
  }
   return 1;  
}
int accept_kill(object who)
{
  object head;
  if( who->query_temp("maiu") && !query("change"))
  {
   say("正五品督军大怒: 你这个贱民,竟敢背叛我!!看我怎么收拾你!!!\n"
        +"正五品督军的头上冒出腾腾紫气!\n");
   set("title","- 紫气 -");
   set("combat_exp", 180000);
   set("max_kee",3000);
   set("change",1);
   set("kee",3000);
   set("force_factor", 15);     
   set_skill("six-fingers",70);
   set_skill("linpo-steps",60); 
   head=new("/open/ping/obj/zhang-head");
   head->move(this_object());
   setup();
  }
  command("wield all");
  return 1;
}
int accept_fight(object who)
{
  if( who->query_temp("maiu") )
      return notify_fail("正五品督军说: 壮士别开玩笑了...要杀的是苗王啊!\n");
  command("wield all");
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

	if( winner->query_temp("bless")==1 )
	{
	j=random(6000);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {
	  new("/open/sky/obj11/green-crystal")->move(environment(winner));
	  message_vision(HIM"\n从张渊的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/green_crystal",sprintf("%s(%s) 让张渊掉下了绿色光晶于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
	  {
	  new("/open/sky/obj11/green-crystal")->move(environment(winner));
	  message_vision(HIM"\n从张渊的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/green_crystal",sprintf("%s(%s) 让张渊掉下了绿色光晶于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();
}
