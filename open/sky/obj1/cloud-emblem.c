inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIG"云之纹章"NOR,({"cloud-emblem"}));
	set("long","一枚如云似雾让你快看不清的的奇怪纹章，若隐若现，名为云之纹\n"
		  +"章，任你如何的细看和研究，却也不知它有何作用，也许和传说中\n"
		  +"的天灵地界有关。\n");
	set("unit","枚");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set_weight(1000);
        setup();
}
