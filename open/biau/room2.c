// Room: /u/o/onion/room/r_room0.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "管家房");
	set("long", @LONG
这里是镳局内的大管家所住的地方,大管家负责整间镳局上上下下数十口的生活起居,
大小事情都需大管家的过目,因此地位也算不错,整间房间布置的一丝不茍,东西都整齐的
放置着,由此可知大管家的为人处世是多耿直了...
    北边有一道木门(door).
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room1",
	]));
        set("item_desc", ([ 
        "door" : "一扇坚实的木门,上头雕着复杂的花纹.\n",
        ]));
        set("objects",(["/u/o/onion/npc/steward" : 1]));
	setup();
        create_door("north","木门","south",DOOR_CLOSED);
}
