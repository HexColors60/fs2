// Room: /u/p/powell/room/r3.c

inherit ROOM;

void create ()
{
  set ("short", "大马路");
  set ("long", @LONG
这条大马路可是贯穿驿站南北的青石板大道, 尤其威武镳局就在附近, 
整条街更显的热闹非凡, 车水马龙, 过个街道可得小心一点, 别让来往的马
车给撞了, 由此往东走, 就是江湖上最有信誉的车马行, 往西走就是威武镳
局的总行。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"biau",
  "north" : "/open/trans/room/room4",
  "south" : "/open/main/room/r31",
  "east" : __DIR__"car",
]));

  set("outdoors", "/open/main");

  setup();
}
// by babe 防止 mob 进入                   
int valid_leave( object me, string dir )   
{                                          
        if( dir=="north" && !userp(me) )    
                return 0;                  
                                           
        return ::valid_leave( me, dir );   
}                                          

