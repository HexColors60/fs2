//diaper.c by chun

inherit ITEM;

void create()
{
	set_name("强褓",({"diaper"}));
	set("long","提供婴儿最基本保护的布。\n");
	set_weight(10);
	set("unit","块");
        set("value",10);
        setup();
}
