// Room: /open/start/room/f15.c

#include <../start.h>

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
�㿴��һƬ�����͵ĵ�������г����ŵ��ݵ���ζ��
�Ĵ������ĵ����������ڹ�����ũ���ǣ�������һ����׼��
ũ�徰��������ȥ���Կ������ƴ塣

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/start/npc/farmer1" : 1,
]));

  set("outdoors", "/open/start");

  set("exits", ([ /* sizeof() == 3 */
  "west" : "/open/start/room/f14",
  "north" : "/open/start/room/f10",
  "south" : "/open/start/room/f20",
]));

  setup();
}