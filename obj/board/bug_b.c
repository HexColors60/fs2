inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HBRED+HIY"bugs公布版"NOR,({"board"}));
set("location","/open/wiz/bug_room");
set("board_id","bug");
set("long","给wiz公布bugs用的,请勿随意乱post,报bug请直接打record,thx\n");
setup();
set("capacity",300);
replace_program(BULLETIN_BOARD);
}
