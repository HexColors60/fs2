#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name(HIC "匕首" NOR,({"dagger","dagger"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",100);
                set("material", "steel");
        }
        init_dagger(10);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", "$N从怀中摸出一把$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n藏入怀中。\n");

// The setup() is required.
        setup();
}