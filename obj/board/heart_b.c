inherit BULLETIN_BOARD;

void create()
{
        set_name("心情故事板", ({ "board" }) );
        set("location", "/open/su/room/hotel");
        set("board_id", "heart_b");
        set("long",     "这是一个心情板....当你不爽,生气,高兴,
快乐,赌烂,郁卒,被甩,甩人,被放鸽,被 pk 都可来这发泄一下..。\n" );
        setup();
        set("capacity", 30);
}
