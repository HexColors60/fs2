// dagger.c : an example weapon

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("木刀",({"wood blade","blade"}) );
        set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("long","一把木制的刀子.\n");
                set("value", 100);
                set("material","wood");
	}
        init_blade(5);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg","$N从背后抽出一把木刀.\n");
        set("unwield_msg","$N将木刀收入背后的刀鞘里.\n");

// The setup() is required.

	setup();
}
