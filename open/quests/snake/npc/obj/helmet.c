#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIG"青蛇头盔"NOR, ({"snake helmet", "helmet"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "顶");
        set("value", 100000);
        set("material", "steel");
        set("long","
这顶头盔上头有标示着一只蛇，虽然不晓得有什么意义，不过
却是一个不错的头盔。\n");
        set("armor_prop/armor", 10);
	set("armor_prop/force",3);
        }
        setup();
}
