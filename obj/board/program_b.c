inherit BULLETIN_BOARD;

void create()
{
	set_name("程式心得讨论版", ({ "board" }) );
	set("location", "/open/wiz/program_room");
	set("board_id", "program_b");
	set("long",	"这是专门供给所有巫师讨论程式与提供心得的板子\n");
	setup();
	set("capacity", 300);
}
