// 钥匙, 有锁的房间请到 /u/w/wade/workroom 参考
inherit ITEM;

void create()
{
        set_name("钥匙", ({ "gold key","key" }) );
        set("unit", "把");
	set ("short", "test");
        set("long", "一把看起来普普的钥匙。\n");
	// 底下这个是设定它可以用的房间
	set ("key_of_room", ({ "*" }) );
}

int query_autoload () { return 1; }
