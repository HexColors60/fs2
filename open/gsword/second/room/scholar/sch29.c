#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"������磭�ſ�ʥ����"NOR);
        set("long", @LONG
����ǰ��������һ����Ӱ�����е���������ƺ���Ӧ��ʲô�Ƶģ����������Ĺ�â��ҫ
����������������������Ӱ�񣬶���һ���ƺ��ǰٶ���ǰ��ħ��ս�ľ��󣡣�
LONG);
set("exits", ([ /* sizeof() == 3 */
  "south":"/open/common/room/inn.c",
 "north":"/open/gsword/room1/blood/room1/r1.c",
]));
        set("no_transmit", 1);
        set("no_drop",1);
  set("objects", ([ /* sizeof() == 1 */
   "/open/gsword/second/room/scholar/npc/scholar" :1,
]));
        set("no_auc",1);
        setup();
}

int valid_leave(object me, string dir)
{
if(dir=="north" && present("scholar",environment(me)))
   if(!me->query_temp("allow_pass",1))
   return notify_fail("����Ϊ���ܻ�ù�ȥ��??"+RANK_D->query_respect(me)+"��̫���˰�!\n");
return ::valid_leave(me,dir);
}