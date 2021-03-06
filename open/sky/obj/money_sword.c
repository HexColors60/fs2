#include <weapon.h>
#include <ansi.h>

inherit SWORD;
object user,me=this_player(),ob=this_object();

void create()
{
	seteuid(getuid());
	set_name(HIC"摇"HIB"钱"HIC"树"HIB"邪"HIC"剑"NOR,({"money sword","sword"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把可以自由幻化的剑，幻化的方法为(change 武器的名称)。\n");
		set("value",100000);
		set("no_sell",1);
		set("no_put",1);
		set("no_sac",1);
		set("type", 1);
		set("rigidity",20);
		set("material", "steal");
	}
	init_sword(150);
	setup();
}

void init()
{
	add_action("do_drop","drop"); 
	add_action("do_auc","auc"); 
	add_action("do_wield","wield");
	add_action("do_unwield","unwield");
	add_action("do_change","change");
}

int do_wield(string str)
{ 
     ::wield();
     if( query("equipped") ) 
     {
        user = this_player();
        message_vision("拿起$n,$N觉得自己的财富之路似乎又近了一些!!\n",user,ob);
        set_heart_beat(1);
     } 
}

int do_drop(string str)
{  
   if(str=="money sword" || str=="all" || str=="sword" || str=="money claws" || str=="claws" ||
      str=="money blade" || str=="blade" || str=="money whip" || str=="whip" || str=="dagger" ||
      str=="money dagger" || str=="money fan" || str=="fan")
     if( query("equipped") )
     {
        message_vision("$N不舍的将$n小心的收起放好。\n",user,ob);
        set_heart_beat(0);
     }    
}

int do_unwield(string str)
{
   if(str=="money sword" || str=="all" || str=="sword" || str=="money claws" || str=="claws" ||
      str=="money blade" || str=="blade" || str=="money whip" || str=="whip" || str=="dagger" ||
      str=="money dagger" || str=="money fan" || str=="fan")
     if( query("equipped") )
     {
        message_vision("$N不舍的将$n小心的收起放好。\n",user,ob);
        set_heart_beat(0);
     }   
}

int do_auc(string str)
{
   if(str=="money sword" || str=="all" || str=="sword" || str=="money claws" || str=="claws" ||
      str=="money blade" || str=="blade" || str=="money whip" || str=="whip" || str=="dagger" ||
      str=="money dagger" || str=="money fan" || str=="fan")
     if( query("equipped") )
     { 
        message_vision("$N不舍的将$n小心的收起放好。\n",user,ob);
        set_heart_beat(0);
     } 
}

int do_change(string str)
{
   switch(str)
   {
     case "unarmed":
           set("skill_type", "unarmed");
           set_name(HIC"摇"HIB"钱"HIC"树"HIB"邪"HIC"爪"NOR,({"money claws","claws"}));
           message_vision("强烈的光茫过后，凝聚在$N手中的吓然是一把$n\n",me,ob);
           break;
     case "sword":
           set("skill_type", "sword");
           set_name(HIC"摇"HIB"钱"HIC"树"HIB"邪"HIC"剑"NOR,({"money sword","sword",}));
           message_vision("强烈的光茫过后，再度凝聚在$N手中的吓然是一把$n\n",me,ob);
           break;
     case "blade":
           set("skill_type", "blade");
           set_name(HIC"摇"HIB"钱"HIC"树"HIB"邪"HIC"刀"NOR,({"money blade","blade",}));
           message_vision("强烈的光茫过后，凝聚在$N手中的吓然是一把$n\n",me,ob);
           break;
     case "dagger":
           set("skill_type", "dagger");
           set_name(HIC"摇"HIB"钱"HIC"树"HIB"邪"HIC"刃"NOR,({"money dagger","dagger"}));
           message_vision("强烈的光茫过后，凝聚在$N手中的吓然是一把$n\n",me,ob);
           break;
     case "whip":
           set("skill_type", "whip");
           set_name(HIC"摇"HIB"钱"HIC"树"HIB"邪"HIC"鞭"NOR,({"money whip","whip"}));
           message_vision("强烈的光茫过后，凝聚在$N手中的吓然是一把$n\n",me,ob);
           break;
     case "stabber":
     case "fan":
           set("skill_type", "stabber");
           set_name(HIC"摇"HIB"钱"HIC"树"HIB"邪"HIC"扇"NOR,({"money fan","fan"}) );
           message_vision("强烈的光茫过后，凝聚在$N手中的吓然是一把$n\n",me,ob);
           break;
     default:      
           message_vision("$n怎么样就是感应不到$N的呼应!!\n",me,ob);
   }
     return 1;
}

void heart_beat()
{
	object m1,m2,m3,m4,m5,m6;
	int j;
	j=random(100000);

	m1=new("/obj/money/coin.c");
	m2=new("/obj/money/silver.c");
	m3=new("/obj/money/gold.c");
	m4=new("/obj/money/cash.c");
	m5=new("/obj/money/cash.c");
	m5->set_amount(10);
	m6=new("/obj/money/cash.c");
	m6->set_amount(100);

	if ( !objectp(user) )
        {
        set_heart_beat(0);
        return;
        }

	if( user->is_fighting() && query("equipped") )
	{
	  switch(j)
	  {
	  case 87500..92500:
		message_vision("忽然由$n里掉出了一文钱，结结实实的打在$N身上!!\n",user,ob);
		m1->move(user);
		break;

	  case 92501..95000:
		message_vision("忽然由$n里掉出了一两银子，结结实实的打在$N身上!!\n",user,ob);
		m2->move(user);
		break;

	  case 95001..97500:
		message_vision(HIY"忽然由$n"HIY"里掉出了一两金子，结结实实的打在$N身上!!\n"NOR,user,ob);
		m3->move(user);
		break;

	  case 97501..99985:
		message_vision(HIW"忽然由$n"HIW"里掉出了一张银票，结结实实的打在$N身上!!\n"NOR,user,ob);
		m4->move(user);
		break;

	  case 99986..99996:
		message_vision(HIW"忽然由$n"HIW"里掉出了十张银票，结结实实的打在$N身上!!\n"NOR,user,ob);
		m5->move(user);
		break;

	  case 99997..100000:
		message_vision(HIC"忽然由$n"HIC"里掉出了一百张银票，结结实实的打在$N身上!!\n"NOR,user,ob);
		m6->move(user);
		break;
	  }
	}
  return;
}  
