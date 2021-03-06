// Room: /d/death/gateway.c

inherit ROOM;

void create ()
{
  set ("short", "酆都城门");
  set ("long", @LONG
你现在来到一座黑色城楼之前，城楼上刻着三个大字：酆都城。往
南不远处有一座桥，桥上鬼影幢幢，但是却听不到半点声音，往北走进
城楼只见一片黑漆漆的，只有少许暗红色的火光若隐若现地闪烁着。
LONG);
   set("no_auc",1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road1",
  "south" : __DIR__"gate",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bgargoyle" : 1,
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_transmit", 2);

  setup();
}
