inherit ITEM;
#include <ansi.h>
string bname;

object me=this_player();
object ob=this_object();

void create()
{
	seteuid(getuid());
	set_name(HIC"五转"HIW"聚"HIY"灵盘"NOR,({"five turn","five","turn"}));
	set("long", @LONG
    聚灵山庄的镇庄宝物，是聚灵庄主「凤翔天”随身携带的贴身宝
物，相传如果能获得五道灵魂注入此中，可以获得极大的能量，足以
提供攻击和防护的能力。而且若能配合一阴一阳的聚灵宝物，将是开
启天灵地界的最重要宝物。

    此宝物必需先将注入在身上的灵魂吸取入灵盘中，方有作用，还
可以将其他人身上所注入的魂魄吸取至灵盘中，但必需本身有一道魂
魄做为牵引，否则将无法作用。

吸取魂魄方式：  suck soul  (对自己)
                suck id    (从别人那吸取)
灵气运转方式：  turn five  (开启运转)
                stop five  (关闭运转)
LONG);

	set_weight(1000);
	set("value",100000);
	set("unit","块");
	set("magic-manor-f",1);
	set("no_put",1);
	set("no_drop",1);
	set("no_get",1);
	set("no_sell",1);
	set("no_auc",1);
	set("no_give",1);

	setup();
}

void init()
{
	add_action("do_suck","suck");
	add_action("do_turn","turn");
	add_action("do_stop","stop");
}

int do_suck(string arg)
{
	object npc;
	int mag1,mag2,mag3,mag4,mag5,su1,su2,su3,su4,su5;

	mag1 = me->query_temp("magic-manor/goldmagic");
	mag2 = me->query_temp("magic-manor/woodmagic");
	mag3 = me->query_temp("magic-manor/watermagic");
	mag4 = me->query_temp("magic-manor/firemagic");
	mag5 = me->query_temp("magic-manor/soilmagic");
	su1 = ob->query("suck1");
	su2 = ob->query("suck2");
	su3 = ob->query("suck3");
	su4 = ob->query("suck4");
	su5 = ob->query("suck5");

	if( !arg )
	return 0;

	if( ob != this_object() )
	return 0;

	if( arg == "soul" )
	{
	  if( su1 == 1 && su2 == 1 && su3 == 1 && su4 == 1 && su5 == 1 )
	  return notify_fail("已无法再吸取任何魂魄。\n");
	  if( !mag1 && !mag2 && !mag3 && !mag4 && !mag5 )
	  return notify_fail("你身上没有魂魄可吸取。\n");

		if( mag1 == 1 )
	    {
	      if( ob->query("suck1") != 1 )
	      {
	      message_vision(ob->name()+HIY"泛起一阵灵光，将$N身体中的金色魂魄吸入了"NOR+ob->name()+HIY"。\n"NOR,me);
	      ob->set("suck1",1);
		  me->delete_temp("magic-manor/goldmagic");
	      }else{
	      message_vision(ob->name()+HIY"已经吸取金色魂魄了。\n"NOR,me);
	      }
		}
		if( mag2 == 1 )
	    {
	      if( ob->query("suck2") != 1 )
	      {
	      message_vision(ob->name()+HIG"泛起一阵灵光，将$N身体中的绿色魂魄吸入了"NOR+ob->name()+HIG"。\n"NOR,me);
	      ob->set("suck2",1);
		  me->delete_temp("magic-manor/woodmagic");
	      }else{
	      message_vision(ob->name()+HIG"已经吸取绿色魂魄了。\n"NOR,me);
	      }
		}
		if( mag3 == 1 )
	    {
	      if( ob->query("suck3") != 1 )
	      {
	      message_vision(ob->name()+HIC"泛起一阵灵光，将$N身体中的水色魂魄吸入了"NOR+ob->name()+HIC"。\n"NOR,me);
	      ob->set("suck3",1);
		  me->delete_temp("magic-manor/watermagic");
	      }else{
	      message_vision(ob->name()+HIC"已经吸取水色魂魄了。\n"NOR,me);
	      }
		}
		if( mag4 == 1 )
	    {
	      if( ob->query("suck4") != 1 )
	      {
		  message_vision(ob->name()+HIR"泛起一阵灵光，将$N身体中的红色魂魄吸入了"NOR+ob->name()+HIR"。\n"NOR,me);
	      ob->set("suck4",1);
		  me->delete_temp("magic-manor/firemagic");
	      }else{
	      message_vision(ob->name()+HIR"已经吸取红色魂魄了。\n"NOR,me);
	      }
	    }
		if( mag5 == 1 )
	    {
	      if( ob->query("suck5") != 1 )
	      {
		  message_vision(ob->name()+NOR+YEL"泛起一阵灵光，将$N身体中的土色魂魄吸入了"NOR+ob->name()+NOR+YEL"。\n"NOR,me);
	      ob->set("suck5",1);
		  me->delete_temp("magic-manor/soilmagic");
	      }else{
	      message_vision(ob->name()+NOR+YEL"已经吸取土色魂魄了。\n"NOR,me);
	      }
		}
	return 1;
	}

	if( !npc = present(arg,environment(me)) )
//	if( !(npc = find_player(arg)) )
	return notify_fail("此地没有这号人物哩？！\n");

	if( arg == arg )
	{
	mag1=npc->query_temp("magic-manor/goldmagic");
	mag2=npc->query_temp("magic-manor/woodmagic");
	mag3=npc->query_temp("magic-manor/watermagic");
	mag4=npc->query_temp("magic-manor/firemagic");
	mag5=npc->query_temp("magic-manor/soilmagic");

	  if( su1 == 1 && su2 == 1 && su3 == 1 && su4 == 1 && su5 == 1 )
	  return notify_fail("已无法再吸取任何魂魄。\n");
	  if( !su1 && !su2 && !su3 && !su4 && !su5 )
	  return notify_fail("你没有吸取任何魂魄作导引，无法吸取别人身上的魂魄。\n");
	  if( !mag1 && !mag2 && !mag3 && !mag4 && !mag5 )
	  return notify_fail("对方身上没有魂魄可吸取。\n");

		if( mag1 == 1 )
	    {
	      if( ob->query("suck1") != 1 )
	      {
	      message_vision(ob->name()+HIY"泛起一阵灵光，将$N身体中的金色魂魄吸入了"NOR+ob->name()+HIY"。\n"NOR,npc);
	      ob->set("suck1",1);
		  me->delete_temp("magic-manor/goldmagic");
	      }else{
	      message_vision(ob->name()+HIY"已经吸取金色魂魄了。\n"NOR,npc);
	      }
		}
		if( mag2 == 1 )
	    {
	      if( ob->query("suck2") != 1 )
	      {
	      message_vision(ob->name()+HIG"泛起一阵灵光，将$N身体中的绿色魂魄吸入了"NOR+ob->name()+HIG"。\n"NOR,npc);
	      ob->set("suck2",1);
		  me->delete_temp("magic-manor/woodmagic");
	      }else{
	      message_vision(ob->name()+HIG"已经吸取绿色魂魄了。\n"NOR,npc);
	      }
		}
		if( mag3 == 1 )
	    {
	      if( ob->query("suck3") != 1 )
	      {
	      message_vision(ob->name()+HIC"泛起一阵灵光，将$N身体中的水色魂魄吸入了"NOR+ob->name()+HIC"。\n"NOR,npc);
	      ob->set("suck3",1);
		  me->delete_temp("magic-manor/watermagic");
	      }else{
	      message_vision(ob->name()+HIC"已经吸取水色魂魄了。\n"NOR,npc);
	      }
		}
		if( mag4 == 1 )
	    {
	      if( ob->query("suck4") != 1 )
	      {
		  message_vision(ob->name()+HIR"泛起一阵灵光，将$N身体中的红色魂魄吸入了"NOR+ob->name()+HIR"。\n"NOR,npc);
	      ob->set("suck4",1);
		  me->delete_temp("magic-manor/firemagic");
	      }else{
	      message_vision(ob->name()+HIR"已经吸取红色魂魄了。\n"NOR,npc);
	      }
	    }
		if( mag5 == 1 )
	    {
	      if( ob->query("suck5") != 1 )
	      {
		  message_vision(ob->name()+NOR+YEL"泛起一阵灵光，将$N身体中的土色魂魄吸入了"NOR+ob->name()+NOR+YEL"。\n"NOR,npc);
	      ob->set("suck5",1);
		  me->delete_temp("magic-manor/soilmagic");
	      }else{
	      message_vision(ob->name()+NOR+YEL"已经吸取土色魂魄了。\n"NOR,npc);
	      }
		}
	}

	return 1;
}

int do_turn(string arg)
{
	if( !arg )
	return 0;
	arg=lower_case(arg);
	if( !ob = present(arg,me) )
	return 0;
	if( ob != this_object() )
	return 0;
	if( me->query_temp("magic-manor/turn-five") )
	return notify_fail("你已经在使用"+ob->name(1)+"。\n");

	message_vision("$n"HIY"内中蕴含的魂魄灵力开始运转不停，发出柔和的光芒。\n"NOR,me,ob);
	me->set_temp("magic-manor/turn-five",1);
	ob->set("name",HIW"(运转中) "+ob->name(1));
	set_heart_beat(1);
	return 1;
}

int do_stop(string arg)
{
	if( !arg )
	return 0;
	arg=lower_case(arg);
	if( !ob = present(arg,me) )
	return 0;
	if( ob != this_object() )
	return 0;
	if( !me->query_temp("magic-manor/turn-five") )
	return notify_fail("你没有使用"+ob->name(1)+"。\n");

	ob->set("name",HIC"五转"HIW"聚"HIY"灵盘"NOR);
	message_vision("$n"NOR+YEL"内中蕴含的魂魄灵力慢慢停止运转，柔和的光芒渐渐暗淡。\n"NOR,me,ob);
	me->delete_temp("magic-manor/turn-five");
	set_heart_beat(0);
	return 1;
}

void heart_beat()
{
	object *enemy;
	int i,j,k,su1,su2,su3,su4,su5,cn,cr,cs,kr,it,pr,si,sr;

	cn = me->query("con");
	cr = me->query("cor");
	cs = me->query("cps");
	kr = me->query("kar");
	it = me->query("int");
	pr = me->query("per");
	si = me->query("spi");
	sr = me->query("str");

	su1 = ob->query("suck1");
	su2 = ob->query("suck2");
	su3 = ob->query("suck3");
	su4 = ob->query("suck4");
	su5 = ob->query("suck5");

	enemy=me->query_enemy();
	i=sizeof(enemy);

	if( !objectp(me) )
	{
	set_heart_beat(0);
	return;
	}

	if( me->is_fighting() && me->query_temp("magic-manor/turn-five") == 1 )
	{
	  if( !su1 && !su2 && !su3 && !su4 && !su5 )
	  {
	    if( random(100) < (int)((kr+sr+cn+cr+si+cs)/12) )
	    {
	    message_vision(HIW"由"HIC"五转"HIW"聚"HIY"灵盘"HIW"运转出微弱的五色灵光，轻轻抚平了$N的伤口。\n"NOR,me,ob);
	    me->receive_curing("kee",500);
	    me->receive_heal("kee",500);
		}
	  }else{
	    if( su1 == 1 && random(100) < 5 )//金色主定人
	    {
	    message_vision(HIM"\n夕阳残照，暮色泛起，余晖映照于大地，"HIY"金极飘魂魄"HIM"感受如此无限晚意轻轻带出

              "HIW"----===≡◎ 金封大地式 ◎≡===----
                   "NOR+YEL"  ‘"HIY"金灵蛇动．残阳坠"NOR+YEL"’\n\n"NOR,me);
		  for( j=0 ; j < i ; j++ )
	      {
	      k = random(3);
		    if(!enemy[j]) return ;
	        {
	          if( k > 0 )
	          {
	          message_vision(HIY"$N"HIY"被此招式隐含宏大的气劲给完全的封住了行动!!\n"NOR,enemy[j]);
			  enemy[j]->start_busy(k);
	          COMBAT_D->report_status(enemy[j]);
	          }else{
	          message_vision(HIW"$N"HIW"看准了来势，巧妙的避开了这股气劲宏大的气劲。\n"NOR,enemy[j]);
	          COMBAT_D->report_status(enemy[j]);
	          }
		    }
	      }
	    }
	    if( su2 == 1 && random(100) < 5 )//绿色主回复
	    {
	    message_vision(HIM"\n木影丛丛，森然罗列，草木轻扬于风中，"HIG"木燃落魂魄"HIM"有感于此身形微动随意发出

              "HIW"----===≡◎ 木影森罗式 ◎≡===----
                   "NOR+GRN"  ‘"HIG"木光流莺．惊天鸣"NOR+GRN"’\n\n"NOR,me);
		message_vision(HIG"魂魄中释放出巨大的生命气息，$n"HIG"感受在这股气息中有说不出的受用!!\n"NOR,me);
	    me->receive_curing("gin",500);
	    me->receive_heal("gin",500);
	    me->receive_curing("kee",500);
	    me->receive_heal("kee",500);
	    me->receive_curing("sen",500);
	    me->receive_heal("sen",500);
		}
	    if( su3 == 1 && random(100) < 5 )//蓝色主化内力为己用和降enforce
	    {
	    message_vision(HIM"水气凝结，龙形渐现，狂啸奔腾于四海，"HIC"水渊流魂魄"HIM"感同身受狂意渐起慕然使出

              "HIW"----===≡◎ 水袭狂涛式 ◎≡===----
                   "NOR+CYN"  ‘"HIC"水舞狂龙．苍海啸"NOR+CYN"’\n"NOR,me);
		  for( j=0 ; j < i ; j++ )
	      {
	      k = random(5);
			if(!enemy[j]) return ;
	        {
	          if( k > 0 )
	          {
			  message_vision(HIC"$N"HIC"被水气凝住气血，渐感使不上力，内力也迅速流失!!\n"NOR,enemy[j]);
	            if( enemy[j]->query("force") > 1000 )
	            {
			    enemy[j]->set("force",(int)(enemy[j]->query("force")-1000));
	            me->add("force",1000);
	            }else{
			    enemy[j]->set("force",0);
	            me->add("force",100);
	            }
	            if( enemy[j]->query("force_factor") > 0 )
	            {
			    enemy[j]->set("force_factor",(int)(enemy[j]->query("force_factor")-1));
	            }else{
			    enemy[j]->set("force_factor",0);
	            }
			  COMBAT_D->report_status(enemy[j]);
	          }else{
	          message_vision(HIW"$N"HIW"看准了来势，巧妙的避开了这股气劲宏大的水气。\n"NOR,enemy[j]);
	          COMBAT_D->report_status(enemy[j]);
	          }
			}
	      }
	    }
	    if( su4 == 1 && random(100) < 5 )//红色主攻精气神
	    {
	    message_vision(HIM"火卷漫天，云淡风轻，轻烟漫舞于天际，"HIR"火飞笙魂魄"HIM"别有感触翩然起舞飘然唤出

              "HIW"----===≡◎ 火卷风云式 ◎≡===----
                   "NOR+RED"  ‘"HIR"火云凤舞．翔风飞"NOR+RED"’\n\n"NOR,me);
		  for( j=0 ; j < i ; j++ )
	      {
	      k = random(9);
		    if(!enemy[j]) return ;
	        {
	          if( k > 0 )
	          {
			  message_vision(HIR"$N"HIR"被这漫天的火气和铺天盖\地的焰气所卷伤，浑身显的残破不堪!!\n"NOR,enemy[j]);
	          enemy[j]->receive_damage("kee",1000);
	          enemy[j]->receive_damage("gin",350);
	          enemy[j]->receive_damage("sen",350);
	          COMBAT_D->report_status(enemy[j]);
	          }else{
	          message_vision(HIW"$N"HIW"变幻莫测的巧妙步法使了开了，漫天的火气只和$N"HIW"擦身而过。\n"NOR,enemy[j]);
	          COMBAT_D->report_status(enemy[j]);
	          }
			}
	      }
	    }
	    if( su5 == 1 && random(100) < 5 )//蓝色主损精气神之最大值
	    {
	    message_vision(HIM"雷厉风行，惊天动地，横扫万物于须臾，"HIB"土爆波魂魄"HIM"感念深刻聚力一指瞬间击出

              "HIW"----===≡◎ 土爆雷霆式 ◎≡===----
                   "NOR+BLU"  ‘"HIB"土假虎威．地雷震"NOR+BLU"’\n\n"NOR,me);
		  for( j=0 ; j < i ; j++ )
	      {
	      k = random(7);
		    if(!enemy[j]) return ;
	        {
	          if( k > 0 )
	          {
			  message_vision(HIB"$N"HIB"被这万马千军般的飞沙走石刮的浑身是伤，显得狼狈不堪!!\n"NOR,enemy[j]);
	          enemy[j]->receive_wound("kee",1000);
	          enemy[j]->receive_wound("gin",350);
	          enemy[j]->receive_wound("sen",350);
	          COMBAT_D->report_status(enemy[j]);
	          }else{
	          message_vision(HIW"$N"HIW"变幻莫测的巧妙步法使了开了，漫天的飞沙走石只和$N"HIW"擦身而过。\n"NOR,enemy[j]);
	          COMBAT_D->report_status(enemy[j]);
	          }
			}
	      }
	    }
	  }
	}
	return;
}