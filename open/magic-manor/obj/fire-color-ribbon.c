#include <weapon.h>
#include <ansi.h>

inherit UNARMED;
object user=this_player();
object ob=this_object();
int be,bb,k,sp,qq,co,st;

void create()
{
     set_name(MAG"雷火彩凤翔"NOR,({"fire-color-ribbon","ribbon"}) );
     set_weight(10000);
     if( clonep() ) 
            set_default_object(__FILE__);
     else {
            set("long","妩情生所使用的武器，为一神秘铸将精心铸造的「八色灵器”之一，周身\n不时的泛出七彩的光芒，是最美的武器之一。\n");
            set("unit", "条");             
            set("value",20000);
            set("sharp",9);
            set("material","blacksteel");
			set("e-weapon",1);
			set("no_give",1);
 			set("no_steal",1);
            }
	init_unarmed(100);
 	set("wield_msg",MAG"$N"MAG"载上$n"MAG"，$n"MAG"雷火之气幻成七彩光芒环绕着周身!!\n"NOR);
        set("unwield_msg","$N轻轻卸下$n，$n雷火之气也渐渐消散。\n"NOR);

          setup();
}                   


void init()
{
     add_action("do_drop","drop");
     add_action("do_auc","auc");
     add_action("do_wield","wield");
     add_action("do_unwield","unwield");
}
int do_wield(string str)
{
	int uexp;
//	::wield();
	if( !query("equipped") )
	{
	user = this_player();
	uexp = user->query("combat_exp");
	  if( uexp < 3000000 )
	  {
	  message_vision("$N的经验并不足以完全支配这样的神兵利器!!\n"NOR,user);
	  set_heart_beat(0);
	  }else{
//	  message_vision(MAG"$N"MAG"载上$n"MAG"，$n"MAG"雷火之气幻成七彩光芒环绕着周身!!\n"NOR,user,ob);
	  set_heart_beat(1);
	  }
	}
}

int do_drop(string str)
{
	if(str=="fire-color-ribbon" || str=="ribbon" || str=="all")
	if( query("equipped") )
	{
	message_vision("$N轻轻卸下$n，$n雷火之气也渐渐消散。\n"NOR,user,ob);
	set_heart_beat(0);
	}
}

int do_unwield(string str)
{
	if(str=="fire-color-ribbon" || str=="ribbon" || str=="all")
	if( query("equipped") )
	{
//	message_vision("$N轻轻卸下$n，$n雷火之气也渐渐消散。\n"NOR,user,ob);
	set_heart_beat(0);
	}
}

int do_auc(string str)
{
	if(str=="fire-color-ribbon" || str=="ribbon" || str=="all")
	if( query("equipped") )
	{
	message_vision("$N轻轻卸下$n，$n雷火之气也渐渐消散。\n"NOR,user,ob);
	set_heart_beat(0);
	}
}
void heart_beat()
{
	object *enemy;
	int i;

	if( !objectp(user) )
	{
	set_heart_beat(0);
	return;
	}

	if( user->query_skill("unarmed") )
	{
	be = user->query_skill("unarmed",1);
	}else{
	be = random(120);
	}

	k = user->query("int",1);
	sp = user->query("spi",1);
	co = user->query("cor",1);
	st = user->query("str",1);
	qq = (int)((k+sp+co+st)*(k+sp+co+st) / 60);
	if( user->query("class") == "dancer" )
	{
	qq = qq*1.5;
	be = be*0.75;
	}

	if( user->is_fighting() && query("equipped") )
	{
	  if( be > random(500) )
	  {
	  enemy=user->query_enemy();
  	  if(!enemy) return ;
	  i=random(sizeof(enemy));
	  if( environment(user) == environment(enemy[i]) )
	  if( random(300) > random(enemy[i]->query_skill("dodge",1)) )
	  {
	  message_vision("$n"HIB"周身环绕的雷火之气化成"HIC"雷气"HIB"和"HIR"火气"HIB"直奔$N"HIB"垄罩$N"HIB"全身要害!!\n"NOR,enemy[i],ob);
	  enemy[i]->receive_wound("kee",(int)(qq+be),user);
	  COMBAT_D->report_status(enemy[i], 0);
	  }else
	  message_vision(BLU"$N"BLU"一个闪身，已躲开了雷火之气的袭击!!\n"NOR,enemy[i],ob);
	  }
	}
	return;
}

