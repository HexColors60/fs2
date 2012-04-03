// Room: /open/main/room/s36.c

inherit ROOM;

void create ()
{
  set ("short", "��ԭ");
  set ("long", @LONG
������һƬ��ԭ�����˵�Ұ�����ҵĳ��ţ��߸ߵ͵͵�â
�����ŷ����������Ӧ���в��ٶ�����.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/center/npc/sparrow" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"s29",
  "west" : __DIR__"s35",
  "east" : __DIR__"s37",
]));

  setup();
}