// Room: /open/tendo/room/t08.c
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
 set("short",HIB"昆仑太极殿"NOR);
        set("long",@LONG
传说中的道家圣地太极殿，地上有幅极大的太极图形( picture)。两
旁的墙壁则雕刻一连串的道家神话--盘古开天辟地，共工怒触不周山，后
羿射日等等知名的故事。雕工细致非凡。而天道掌门则正坐在蒲团上闭眼
冥思。

LONG);
set("item_desc",([
	"picture" : "用法: 站立于图形的八个方位(stand 1~8)\n"+
"	1.京城    2.蜀中城  3.平南城  4.中央驿站    \n"+
"	5.凌云村  6.login处 7.枫林港  8.夜梦小筑\n",
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"t03",
	"north" : __DIR__"eqroom",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/daemon/class/taoist/master_lu" : 1,
  "/open/tendo/npc/taoist1" : 1,
]));
  set("light_up", 1);
  set("valid_startroom", 1);
	set("cango",1);

  setup();
  call_other("/obj/board/tendo_b","???");
}
void init()
{
	add_action("do_into","stand");
}

int do_into(string arg)
{
	object who;
	string room;
        who = this_player();

        if(who->query("class")!="taoist")
        return notify_fail("汝非我派中人，不得进入此图。\n");
    switch(arg)
    {
       case "1":
         room="/open/capital/room/r70";         break;
       case "2":
         room="/open/gsword/room/su3";          break;
       case "3":
         room="/open/ping/room/road4";          break;
       case "4":
         room="/open/center/room/inn";          break;
       case "5":
         room="/open/start/room/s5";            break;
	case "7":
         room="/open/port/room/r3-1";           break;
	case "8":
	room = "/open/dancer/room/cafeteria";	break;
	case "6":
	room = who->query("start_room");     break;
       default:
	}
	if(!room)
		return 1;
	who->move(room);
        tell_room(this_object(),"你看到"+who->query("name")+"进入太极图中，忽"+
                                "的一声，人已不见了。\n");
        return 1;
}

 int valid_leave(object me, string dir)
{
  if( dir=="north" )
     if( me->query("family/family_name")!="天道派")
       return notify_fail("只有天道弟子才能进入。\n");
   return ::valid_leave(me,dir);
}


