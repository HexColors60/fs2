// board.c
inherit BULLETIN_BOARD;
 
void create()
{
    set_name("天道工程留言版", ({ "board" }) );
    set("location", "/u/b/borstquc/workroom");
    set("board_id", "borstquc_b");
    set("long", "用来记录天道的工程进度\n" );
    setup();
    set("capacity", 100);
    set("master",({ "borstquc" }) );
}
