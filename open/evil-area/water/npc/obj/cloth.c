#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIC"七"HIM"彩"HIW"羽"HIG"衣"NOR, ({ "seven color feather","feather"}) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
	{
                set("unit", "件");
		set("value",1000000);
                set("material", "cloth");
                set("armor_prop/armor", 1);
		set("long","
谣传这是天界所传下来的天衣制法所制成的，穿上它后可以像天仙
一样翱翔天际；可惜由于太过于贵重，很多仿制品纷纷出笼，如今
已有许多人上当了。\n");
        }
        setup();
}
