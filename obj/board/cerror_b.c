#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
set_name(HIY"我的记事板"NOR, ({"board"}));
set("location","/u/c/cerror/workroom.c");
set("board_id","cerror_b");
set("long",HIY"酸甜苦辣事 ,都付记事本\n"NOR);
    setup();
set("capacity", 80);
set("master",({"cerror"}));
}


