//made by bss
//king 身上的ring
//二版,king can call 3 只,ppl just can call one
//增加判断对手是否set("no_gring",1),如果是则不呼叫mob出来 modify by cyw at 91/04/03
#include <ansi.h>
#include <armor.h>
inherit EQUIP;
object user;
int kar,cor;
void create()
{
     set_name(HBRED+HIY"护卫戒指"NOR ,({"guard ring", "ring"}));
     set_weight(2500);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long","一只可以于战斗中请出护卫帮忙战斗的指戒,闪烁着奇异的金色光芒.\n");
            set("unit", "件");
            set("value",500000);
            set("material","gold");
            set("armor_type","finger");
            set("armor_prop/armor",7);
           }
        setup();
}
void init()
{
     add_action("do_drop","drop");
     add_action("do_auc","auc");
     add_action("do_wear","wear");
     add_action("do_give","give");
     add_action("do_remove","remove");
}
int do_wear(string str)
{

     ::wear();
     if( query("equipped") )
     {
        user = this_player();     // 取得使用者
        kar = user->query("kar");
        cor = user->query("cor");
        cor = cor *2;
        message_vision("$N戴上了护卫指戒,刹那间四周金光大作.\n",user);
        set_heart_beat(1);
     }
}
int do_drop(string str)
{
   if(str=="ring" || str="guard ring" || str=="all")
     if( query("equipped") )
     {
        set_heart_beat(0);
     }
}
 int do_give(string str)
{
   if(str=="ring" || str="guard ring" || str=="all")
     if( query("equipped") )
     {
        message_vision("$N脱下了护卫指戒,奇异的金光也随之消逝.\n",user);
        set_heart_beat(0);
     }
}
int do_remove(string str)
{
   if(str=="ring" || str="guard ring" || str=="all")
     if( query("equipped") )
     {
        message_vision("$N脱下了护卫指戒,奇异的金光也随之消逝.\n",user);
        set_heart_beat(0);
     }
}
int do_auc(string str)
{
   if(str=="ring" || str="guard ring" || str=="all")
     if( query("equipped") )
     {
        message_vision("$N脱下了护卫指戒,奇异的金光也随之消逝.\n",user);
        set_heart_beat(0);
     }
}
void heart_beat()
{
        object mob,*enemy;
        int i,j,k;
  if( !objectp(user) )
        {
        set_heart_beat(0);
        return;
        }
  if(user->is_fighting()){
  	enemy=user->query_enemy();
  	j=sizeof(enemy);
  	k=0;
  	for(i=0;i<j;i++){
  	if(enemy[i]->query("no_gring",1))	
  	k++;
     }
     }
  
  if( user->is_fighting() && query("equipped") && k==0)
  {
	if(user->query("capital_king"))
	{
    		if(!user->query_temp("have_guard"))
    		{
    		mob=new(__DIR__"guard");
    		mob->set("title",user->query("name")+"的护卫");
      		mob->set("combat_exp",user->query("combat_exp"));
    		mob->move(environment(user));
    		mob->invocation(user);
		mob=new(__DIR__"guard1");
    		mob->set("title",user->query("name")+"的护卫");
      		mob->set("combat_exp",user->query("combat_exp"));
    		mob->move(environment(user));
    		mob->invocation(user);
    		mob=new(__DIR__"guard2");
    		mob->set("title",user->query("name")+"的护卫");
      		mob->set("combat_exp",user->query("combat_exp"));
    		mob->move(environment(user));
    		mob->invocation(user);
    		}
	}
	else
	{
    		if(!user->query_temp("have_guard"))
    		{
		switch(random(2))
		{
		case 0:
    		mob=new(__DIR__"guard");
    		mob->set("title",user->query("name")+"的护卫");
      		mob->set("combat_exp",user->query("combat_exp"));
    		mob->move(environment(user));
    		mob->invocation(user);
		break;
		case 1:
    		mob=new(__DIR__"guard1");
    		mob->set("title",user->query("name")+"的护卫");
      		mob->set("combat_exp",user->query("combat_exp"));
    		mob->move(environment(user));
    		mob->invocation(user);
		break;
		case 2:
    		mob=new(__DIR__"guard2");
    		mob->set("title",user->query("name")+"的护卫");
      		mob->set("combat_exp",user->query("combat_exp"));
    		mob->move(environment(user));
    		mob->invocation(user);
		break;
		}
    		}
	}
  }
  return;
}

