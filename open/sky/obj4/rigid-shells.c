inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIW"执着之贝壳"NOR,({"rigid-shells"}));
	set("long","一个奇怪的贝壳，似乎并不怎么值钱，上面传递着执着的意念，任\n"
		  +"你如何的细看和研究，却也不知它有何作用，也许和传说中的天灵\n"
		  +"地界有关。\n");
	set("unit","个");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set_weight(1000);
        setup();
}
