// open/killer/ninja/find/rx13.c
// 当玩家发生抉择错误，就会受到严重精神伤害，退回最初点
#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "心灵探索");
  set ("long", @LONG
  
  开玩笑，这么强的老祖，你还担心什魔，你决定跟老祖一起并肩作战，
  顺便看看还有没有什么东西可以挖，开玩笑，居然连分功化影身法都清楚
  不好好搞清楚怎么可以呢？搞不好还可以得到老祖亲自传授绝招.....
  老祖也为了全神灌注，而不愿里你，深知老祖个性与实力的柴荣已先行离去
  不久那股强大的压迫感已经逼近，一道强大的剑气抢先袭击而来！！！
  前所未有的强大剑气，直接由你身上贯穿而过，你根本无法反应.....
  在你眼前一黑之前，隐隐约约听到老祖说
  ‘太小看我了吧，居然才用仙剑后九式的第五式对我......’
  
  仙剑后九式？？？仙剑不是才有后三式而已吗？？？
  
LONG);
  set("no_transmit",2);
  setup();
}

void init()
{
    object ob=this_player();
    if( interactive(ob))
	    remove_call_out("greeting");
  call_out("greeting",3 , ob);   
}

void greeting(object ob)
{
   if( ob->query_temp("firstpart")== 8)    
   {
     ob->set_temp("firstpart",7);
     ob->set("sen",1);
     ob->set("gin",1);
     tell_object(ob," 你感到精神逐渐涣散....逐渐陷入昏迷状态..... \n");
     ob->move("/open/killer/room/pillrm.c");
    }
    // 基本上是很不合理啦，就当成巫师测试用，一到最初点
    else 
     ob->move(__DIR__"r1.c");
}

