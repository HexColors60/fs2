inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name(HIG"棉草"NOR,({"cotton grass","grass"}));
	set_weight(100);
	if( clonep() )
                set_default_object(__FILE__);
	else
	{
		set("value",1);
		set("base_unit","束");
		set("unit","堆");
		set("long","金锦马的最爱，仅有金锦马能够食用。\n");
	}
	set_amount(1);
setup();
}