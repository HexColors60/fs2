#include <ansi.h>
inherit EQUIP;

void create()
{
	set_name("大红彩带",({"red cape","cape"}) );
	set_weight(3000);
	if ( clonep())
		set_default_object(__FILE__);
	else {
		set("unit","条");
		set("material","silk");
		set("value", 320);
		set("armor_type", "cape");
		set("armor_prop/armor", 9);
		set("armor_prop/whip", 5);
		set("long","
以西域运来之大红丝绸织成的彩带，挥舞时红光耀眼，令人眼花撩乱。\n");

	}
	setup();

}
