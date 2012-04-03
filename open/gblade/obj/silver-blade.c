
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("镀银刀", ({ "silver blade","blade" }));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "
一把由白银镀造而成的刀，刀柄系着银绸带，刀身隐隐泛着白光，这
是金刀门弟子相互拆练招式时所使用的兵刃。\n");
		set("value", 2000);
                set("material", "steel");
                set("wield_msg", "银光一闪，$N从刀鞘中抽出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入背后的刀鞘里。\n");
        }
	init_blade(30);

	set("ski_type1", "blade");
	set("ski_type2", "gold-blade");
	set("ski_level1", 30);
	set("ski_level2", 20);
        setup();
}

