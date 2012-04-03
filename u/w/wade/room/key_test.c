// Room: /u/w/wade/room/test.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "钥匙房");
	set("long", @LONG



                 菠萝面包的专用测试房




LONG
	);

	set("exits", ([
	    "east"	:	"/u/w/wade/workroom"
	]));
	set ("need_key/east", 1);
	create_door("east", "红漆大门", "west", DOOR_CLOSED);

	set("no_clean_up", 0);
	set("light", "1");
	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}
