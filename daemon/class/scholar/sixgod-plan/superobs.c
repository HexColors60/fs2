// by sueplan 六韬火龙计修改 2000.7.26
//二度修改六韬奇略之火龙计于 2000.8.25 by sueplan
#include <ansi.h>
int count;
int again(object me);
int perform(object me,object target)
{
        int i, dam, dam1, j;
        object *all = me->query_enemy();
        object who = this_player();
        count=0;
        if(me->is_busy()) 
        return notify_fail("你现在是无法放火龙计的!!\n");
        if(!me->is_fighting())
        return notify_fail("火计只能在战斗中使用。\n");
        if( me->query("sen") < 50 )
        return notify_fail("你的精神力不够，无法用计。\n");
        if( me->query_skill("plan") < 120 )
        return notify_fail("你的谋略能力不够。\n");
        //加入如果用大火计在解穴时是不能放的
        if(me->query_temp("big_fire"))
        return notify_fail("你正在施放大火计, 此时是不可以再放火龙计的!!\n");
        // 不是儒门
        if( me->query("family/family_name") != "儒门")
        return notify_fail("不是儒生，不给你用咧！！^_^\n");
        me->add("sen",-20);
        me->start_busy(1);
        message_vision( HIR + @LONG
$N使用六韬奇略之中的火计！只见火舌似龙般飞舞于你的面前 .....
LONG + NOR , me , target );
  for( i = 0 ; i < sizeof(all) ; i ++ ) 
  {
 if( 80 > random(1))
  {
    if( me->query("quest/gold-fire") && (me->query("combat_exp")>5000000))
    {
      dam=who->query_skill("stabber")*10;
//一般ppl大约只会到2100 + weapon 只能到2200
      dam1 = dam;
      j=who->query_skill("plan",1)*3;
      message_vision( HIR + @LONG
$N熟知兵法运计之要，将儒门火计以及六韬奇略中大热之计，和而为一$n骤时发现身旁业火乱窜，竟然是赤壁之战时所用之‘火    龙    计’!
LONG + NOR , me , all[i] );
      all[i]->apply_condition("burn",30);  
     all[i]->receive_wound( "kee" ,dam1*10);
      all[i]->receive_wound( "sen" ,j);
      all[i]->receive_wound( "gin" ,j);
      COMBAT_D->report_status( all[i] );
    }
    else
    {
dam=all[i]->query("max_kee");
       message_vision( HIR + @LONG
$n来不及逃跑，因此被$N放出了火焰烧伤了！
LONG + NOR , me , all[i] );
       all[i]->apply_condition("burn",10);  
     all[i]->receive_wound( "kee" ,dam*10);
       COMBAT_D->report_status( all[i] );
     }
  }
  else 
  message_vision( HIY + @LONG
$n见情势不妙，跳了开来，逃过了一劫！
LONG + NOR , me ,all[i] );
  }
if (me->query("quest/gold-fire") && me->query("env/大火计"))
 {
  call_out("again",2,me);
}
  return 1;
}
//以下是set大火计会出现的情形
//大火计会busy自己4但考滤pkla 伤害不可太高
//加上书生穿meq 可能可以崩穴 by sueplan
int again(object me)
{
        int i;
        object *all = me->query_enemy();
        count ++;
        if(count>4) 
        {
//新加避免儒门meq解穴后还可以放
          me->delete_temp("big_fire");
          return 1;
        }
me->start_busy(1);
if (me->query("quest/gold-fire") && me->query("env/大火计"))
{
    if (me->query("bellicosity") < 500)
    {
    return 1;
    }
    me->set_temp("big_fire",1);
    me->add("bellicosity",-5);
//加入temp
    message_vision( HIR + @LONG
$N大喊  : ‘六韬奇略，烈火焚天 - 炬火计’一个巨大的火阵在众人面前展开!!
LONG + NOR , me );
    for(i=0;i<sizeof(all);i++)
    {
        if(random(100) <80)
        {
        all[i]->receive_wound( "kee" ,700);
        all[i]->receive_wound( "sen" ,100);
        all[i]->receive_wound( "gin" ,100);
//伤精及神调降 
//busy 自己 4所以强度调高, 不然没有busy(4)的强度 by sueplan
        COMBAT_D->report_status( all[i] );

        } 
        else 
        {
        message_vision( HIY + @LONG
$n见情势不妙，跳了开来，逃过了一劫！
LONG + NOR , me ,all[i] );
        }
   }
  call_out("again",2,me);
//busy算好了心跳时间, 故在放大火计时自己是不会出手的
  }
return 1;
}

