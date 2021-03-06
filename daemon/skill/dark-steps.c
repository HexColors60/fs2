#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void reattack();
//当玩家驱动化影术得时候，会出现前三招(或许会在加)
//然后玩家趋到分功术的时候，会出现后三招
string *dodge_msg = ({
    "$n身影微动,已经藉一招「"HIC"幻影幢幢"NOR"”绕到$N四周形成四个幻影。\n",
    "$n身形一转使出「"HIC"缩  地"NOR"”瞬时人离原位而避了开去,$N击中了幻影。\n",
    "只见$n身影一晃即失,一式「"HIC"瞬天影舞"NOR"”已幻化在三丈之外。\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

string query_dodge_msg(string limb)
{
   int x=0,sk_lv=1,now_exp,skrate;
   object target,me=this_player();
   
   if(!me) return "";
   target=offensive_target(me);
//其实当dodge发动时，就已经代表没有受到伤害
//而且对于太强的对手来说，dodge发动的机率并不高
//所以，第一是为了下一次作准备，第二是作一些基本强化   

   if (me->query_temp("step-shadow"))
   {//代表玩家使用化影术
   	if (me->query("dark-steps/shadow/exp"))
   	{//检查玩家是否第一次使用化影术
        	 me->add("dark-steps/shadow/exp",1);
        	 now_exp=me->query("dark-steps/shadow/exp");
        	 sk_lv=me->query("dark-steps/shadow/lv");
        	 if ( now_exp > (20*sk_lv))
        	 {//作升级检查
        	 	me->set("dark-steps/shadow/exp",1);
        	 	if (me->query("dark-steps/shadow/lv") < 100)
        	 		me->add("dark-steps/shadow/lv",1);
        	 	now_exp=0;
        	 }
        }
   	else
   	{
   		 me->set("dark-steps/shadow/lv",1);
        	 me->set("dark-steps/shadow/exp",1);
        }
   	sk_lv=me->query("dark-steps/shadow/lv");
   	switch (sk_lv)
   	{
		case 0..10://玩家将有40%~50%的机率发动化影身法
			skrate= random (100)+ sk_lv +1;
			if (skrate > 60)
			{
				if (me->query("atman") > 30)
				    me->add("atman",-30);
				else
				    me->set("atman",0);
				me->set_temp("shadowfun",2);
message_vision(HIW"\n            分	 功	 化	 影	 身	 法!"NOR,target);
message_vision(HBMAG"\n              分		影		术   \n"NOR,target);
			}
			break;
		case 11..40://玩家将有40%~70%的机率发动化影身法
			skrate= random (100)+ sk_lv +1;
			if (skrate > 70)
			{
				if (me->query("atman") > 30)
				    me->add("atman",-30);
				else
				    me->set("atman",0);
				    
				me->set_temp("shadowfun",2);
				me->receive_heal("gin",skrate+50);
      				target->receive_wound("gin",skrate+50,me);
message_vision(HIW"\n            分	功	化	影	身	法!"NOR,target);
message_vision(HBMAG"\n              分		影		术   \n"NOR,target);
message_vision(HBYEL"\n$N幻出许多身影，令$n眼花撩乱，无法分清楚何者是实体\n"NOR,me,target);
			}
			break;
		case 41..70://玩家将有40%~70%的机率发动化影身法
			skrate= random (100)+ sk_lv - 40;
			if (skrate > 60)
			{
				if (me->query("atman") > 30)
				    me->add("atman",-30);
				else
				    me->set("atman",0);
				//用set是避免玩家连续发动后累加上去				    
				me->set_temp("shadowfun",3);
				me->delete_busy();
				target->receive_wound("gin",skrate+100,me);
message_vision(HIW"\n            分	功	化	影	身	法!"NOR,target);
message_vision(HBMAG"\n              分		影		术   \n"NOR,target);
message_vision(HBYEL"\n$N幻出许多身影，令$n眼花撩乱，无法分清楚何者是实体 \n"NOR,me,target);
message_vision(HBCYN"\n刹那间，整个空间中都是$N的身影，$n有点晕头转向了\n"NOR,me,target);
			}
			break;
		case 71..100://玩家将有60%~80%的机率发动化影身法
			skrate= random (100)+ sk_lv - 70;
			if (skrate > 40)
			{
				if (me->query("atman") > 30)
				    me->add("atman",-30);
				else
				    me->set("atman",0);
				//用set是避免玩家连续发动后累加上去				    
				me->set_temp("shadowfun",3);
				me->delete_busy();
				target->start_busy(1);
				me->receive_heal("gin",sk_lv);
				me->receive_heal("sen",sk_lv);				
      				target->receive_wound("gin",sk_lv*2+30,me);
      				target->receive_wound("sen",sk_lv*2+30,me);
message_vision(HIW"\n            分	功	化	影	身	法!"NOR,target);
message_vision(HBMAG"\n              分		影		术   \n"NOR,target);
message_vision(HBYEL"\n   $N幻出许身影，令$n眼花撩乱，无法分清楚何者是实体\n"NOR,me,target);
message_vision(HBCYN"\n   刹那间，整个空间中都是$N的身影，$n有点晕头转向了\n"NOR,me,target);
message_vision(HBRED"\n   $N的身影越幻化越多，仿佛整个空间为之牵动........\n"NOR,me,target);
			}
			break;
		case 101..150://特别等级，只有获得奖励的玩家才有可能 90% 机会
			if (random(100) < 90)
			{//专家级仅是发动机率变高，伤害公式计算那里，会有新高点
				if (me->query("atman") > 100)
				    me->add("atman",-100);
				else
				    me->set("atman",0);
				//用set是避免玩家连续发动后累加上去				    
				me->set_temp("shadowfun",3);
				me->delete_busy();
				target->start_busy(1);
				me->receive_heal("gin",sk_lv);
				me->receive_heal("sen",sk_lv);				
      				target->receive_wound("gin",sk_lv*2+30,me);
      				target->receive_wound("sen",sk_lv*2+30,me);
message_vision(HIW"\n            专		家		级"NOR,target);
message_vision(HIW"\n            分	功	 化	 影	 身	 法!"NOR,target);
message_vision(HBMAG"\n               分		影		术   \n"NOR,target);
message_vision(HBYEL"\n   $N幻出许身影，令$n眼花撩乱，无法分清楚何者是实体\n"NOR,me,target);
message_vision(HBCYN"\n   刹那间，整个空间中都是$N的身影，$n有点晕头转向了\n"NOR,me,target);
message_vision(HBRED"\n   $N的身影越幻化越多，仿佛整个空间为之牵动........\n"NOR,me,target);
			}
			break;

		default://巫师级(超过限制)     有100%的机率发动化影身法
			{
message_vision(HIW"\n            巫		师		级"NOR,target);
message_vision(HIW"\n            分	功	化	影	身	法!"NOR,target);
message_vision(HIY"\n   $N幻出许身影，令$n眼花撩乱，无法分清楚何者是实体\n"NOR,me,target);
message_vision(HIR"\n   刹那间，整个空间中都是$N的身影，$n有点晕头转向了\n"NOR,me,target);
message_vision(HIG"\n   $N的身影越幻化越多，仿佛整个空间为之牵动........\n"NOR,me,target);
				me->set_temp("shadowfun",4);
				me->delete_busy();
				target->start_busy(2);
				me->receive_heal("gin",sk_lv*5);
				me->receive_heal("sen",sk_lv*5);
      				target->receive_wound("gin",sk_lv*2+30,me);
      				target->receive_wound("sen",sk_lv*2+30,me);
      				me->set_temp("power-down",17);
			}
			break;
	}					
	return dodge_msg[random(3)];		
   }
   if (me->query_temp("step-share"))
   {//代表玩家使用分功术
    //目前暂时没有做这一部分，应该会等到比较后面的故事再弄
   	if (me->query("dark-steps/share/exp"))
   	{
        	 me->add("dark-steps/share/exp",1);
        	 now_exp=me->query("dark-steps/share/exp");
        	 sk_lv=me->query("dark-steps/share/lv");
        	 if ( now_exp > (20*sk_lv))
        	 {//作升级检查
        	 	me->set("dark-steps/share/exp",1);
        	 	me->add("dark-steps/share/lv",1);
        	 	now_exp=0;
        	 }
        }
   	else
   	{
        	 me->set("dark-steps/share/exp",1);
        	 me->set("dark-steps/share/lv",1);
        }
   	sk_lv=me->query("dark-steps/share/lv");
   }   
   return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
tell_object(me,"分功化影无法从学习中获得进展, 必须自己修行方有成果!!\n");
return 0;
}
string perform_action_file(string action)
{
        return CLASS_D("killer")+"/dark-steps/"+action;
}



