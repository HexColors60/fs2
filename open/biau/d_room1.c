// Room: /u/o/onion/room/d_room1.c

inherit ROOM;

void create()
{
	set("short", "小客厅");
	set("long", @LONG
这里是武威镳局瓢把子 赵鼎天的独生女--赵淑媛所居住的小楼,里头有木桌木椅等
普通的家具,所有的东西都显的很朴素,和外头豪华的一切实在是格格不入,丝毫都不似
一个大小姐所住的地方.
    往楼上走便是赵淑媛所住的房间.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"d_room2",
  "west" : __DIR__"d_room0",
	]));
	set("objects",(["/u/o/onion/npc/squire" : 1,]));

	setup();
}

int valid_leave(object me,string dir)
 {
        object who;
        if (dir=="up" && who=present ("squire", environment(me)))
          if(!who->query_temp("unconcious"))
          return notify_fail ("婢女拦在楼梯前说道:小姐吩咐过,不想有人打扰她,"
          +RANK_D->query_respect(me)+ "还是别让我为难吧..\n");
        return ::valid_leave(me, dir);
 }    
  
