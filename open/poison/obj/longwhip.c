// bleed_whip.c
#include <weapon.h>

inherit WHIP;

void create()
{
	set_name("长鞭",({ "long whip","whip"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","条");
	  set("value",500);
		set("material","iron");
		set("long",
	"这是一条普通的长鞭。\n");
	}
	init_whip(15);
	setup();
}
