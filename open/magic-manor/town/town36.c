inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "破屋");
        set ("long", @LONG
一间破旧的屋子，屋顶也已经破了一个大洞了，这里则常常有几
个落魄的乞丐会将这当成住所，向路过的好心人仕们布施一些剩菜剩
饭来温饱。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town30",
	]));

	set("objects", ([ /* sizeof() == 1 */
	"/open/capital/npc/beggar" : 1,
	]));

        setup();
}