#include <weapon.h>
#include <ansi.h>

inherit STABBER;

void create()
{
        seteuid(getuid());
        set_name(HIR"火灵焰扇"NOR,({"fire fan","fan"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","火飞笙所使用的宝扇，火光闪闪的，令人无法直视。\n");
                set("value",1000000);
                set("material", "gold");
                set("wield_msg", "拿起$n,$N觉得有一股灵光注入了身躯。\n");
                set("unwield_msg", "$N将手中的$n小心的收起。\n");
		set("magic-manor-obj",1);
        }
        init_stabber(100);

        setup();
}
