inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name("盘古开天石",({"board"}));
	set("long","灌水专板");
	set("make_clan","hero");
	set("location","/open/clan/hero/room/hall");
	set("capacity",25);
	set("board_id","hero");
	setup();
}
