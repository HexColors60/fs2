// Room: /open/poison/room/room9
inherit ROOM;

void create ()
{
  set ("short", "ִ���ò���");
  set ("long", @LONG
������ִ���õĲ������ڴ���һλʹ�����ھ�ϸ������
̴ľ���ϣ��۹⾫��ֱ��������������ħ�綥������������
�����Ĺ���ʹ�ߣ��ڴ�Э��ִ�����ϰ참��
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room8",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/envoy3.c" : 1,
]));
  set("light_up", 1);

  setup();
}