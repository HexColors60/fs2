inherit ROOM;

void create()
{  
   
   set("short","���ɵ���");
   set ("long", @LONG
������ǰ����һ���޼ʵ�ɳ̲������ɫ��պ��
һ���߲ʵĺ磬���ܵľ�ɫ������ԭ���Ѽ���������
�����滨��ݣ��ڰ�ɫ��ӨӨɳ�����Եø��������
�ҷ���������һƬ��ԭ��                     
LONG);
   set("light_up", 1);
        set_heart_beat(1);
 set("exits", ([ /* sizeof() == 4 */

   "north" : "/open/island/room/i1",
    "east" : "/open/island/room/i6",
  "south" : "/open/island/room/i7",
]));
   set("outdoors", "/open/main");

 setup();
}
