// Room: /open/badman/room/r4

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
һ�߽��������ŵ�һ�ɴ̱ǵ�ҩζ��ԭ��������������
����ҩ�ĵķ��䡣�㿴��һ�Ե�¯���������Ÿ�ʽ������ҩ�ݣ�ÿ
��������û��������ҩ�ģ�������۽硣�Դӵ������������
�˹��Ժ󣬱�Ǳ���о��������ҽ������ʮ������Ҳ½����������
���µ�ҩ������һ����������󡣲�������䷿������������ע��
�ģ����Ƿ���ǽ�Ǳߵ�һ����ҩ�ס�
    ������һ��ľ�Ƶ��š�

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"r2",
]));
  set("light_up", 1);

  create_door("east", "ľ��", "west", DOOR_CLOSED);
  setup();
}