inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(CYN"风之纹章"NOR,({"wind-emblem"}));
	set("long","握在手中可以感觉到有阵阵的风在指尖流动着，一枚称为风之纹章的\n"
		  +"奇怪东西，任你如何的细看和研究，却也不知它有何作用，也许和传\n"
		  +"说中的天灵地界有关。\n");
	set("unit","枚");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set_weight(1000);
        setup();
}
