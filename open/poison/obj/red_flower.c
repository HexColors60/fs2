
#include <ansi.h>

inherit EQUIP;

void create()
{
	set_name(HIR"红花"NOR,({ "red flower", "flower" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
else	{
	set("meterial","leather");
	set("unit","朵");
	set("value", 0);
	set("armor_type","neck");
	set("armor_prop/armor", 1);
	set("long","
这是一朵鲜红色的红花，其特殊外形，不知有何特殊意义。\n");
	}
	setup();
}
