#include </open/open.h>
#include <ansi.h>
inherit NPC;

string call_liu();
void create()
{
	set_name("师爷 张冰",({ "zhang pin","zhang","pin"}) );
	set("race", "人类");
	set("age", 47);
	set("long",
"一位彬彬有礼的书生,他跟随将军征讨已经数十年了,一直是将军器
重的人材,他正忙于公务.
");
	set("inquiry",([
	    "搜索令" : "对不起,这东西不轻易外借的",
	    "柳毅风" : (: call_liu :),
	    "liu"    : (: call_liu :),
	   ])); 
	set("str", 20);
	set("max_force", 250);
	set_skill("unarmed", 25);
	set("force", 250);
	set_skill("parry", 27);
	set_skill("dodge", 24);
	set_skill("six-fingers", 20);
	set("force_factor", 8);
	map_skill("unarmed","six-fingers");
	set("combat_exp",5000);
	set_temp("apply/armor", 13);
	set_temp("apply/dodge", 13);
	setup();
	carry_object(GS_OBJ"boots")->wear();
	carry_object(GS_OBJ"robe_3")->wear();
	add_money("silver", 10);
}

string call_liu()
{
	object ob = this_object();
	object me = this_player();
	if( !ob->query_temp("call_liu") )
	{
	  ob->set_temp("call_liu",1);
	  call_out("call_liu_1",3);
	  return(RANK_D->query_respect(me)+"你找柳毅风柳大侠是吧, 我马上叫他过来"+
	  "\n\n"+ob->query("name")+"悠扬的声音往楼上传去: 柳毅风柳大侠, 有位"+
	  RANK_D->query_respect(me)+"想拜见你\n");
	}  
	else
	{
	  if( present("liu",environment(ob)) )
	    return(RANK_D->query_respect(me)+"你眼花了是吧, 柳大侠不就站在你面前吗?\n");
	  else
	    return("柳毅风柳大侠刚刚出门去了, "+RANK_D->query_respect(me)+"你待会再来好了");
	}
}

void call_liu_1()
{
	object ob = this_object();
	object me = this_player();
	object liu = new(PING_NPC"duan1");
	tell_room(environment(ob),"一阵脚步声由楼上传来...\n");
	tell_room(environment(ob),"柳毅风拱手作揖. 很有礼貌的对你说:「 在下柳毅风! 请多指教! ”\n");
	liu->move(environment(ob));
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

	if ( winner->query_temp("bless")==1 )
	{
	j=random(6000);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {
	  new("/open/sky/obj9/life_charm")->move(environment(winner));
	  message_vision(HIM"\n从张冰的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/life_charm",sprintf("%s(%s) 让张冰掉下了生命之符于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(12000);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
	  {
	  new("/open/sky/obj9/life_charm")->move(environment(winner));
	  message_vision(HIM"\n从张冰的身上掉下了一件奇怪的东西!!\n"NOR,winner);
          write_file("/log/sky/life_charm",sprintf("%s(%s) 让张冰掉下了生命之符于 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	::die();
}