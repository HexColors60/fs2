#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
set_name(HIR"圣火"HIW"风云录"NOR,({"fire board","board"}));
set("location","/open/clan/fire.c");
set("board_id","fire_b");
set("long","记载圣火教历代大事的记实册。\n");
setup();
set("capacity",100);
}

