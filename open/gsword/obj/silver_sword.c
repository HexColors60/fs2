// sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	seteuid(getuid());
        set_name(HIW"银鳞古剑"NOR,({"silver sword","sword"}));
        set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "把");
         set("long","一把古意盎然的剑，剑身上有着类似龙鳞的鳞片。\n");

                set("value",40000);
		set("material", "steel");
                set("ski_level",80);
                set("ski_type","sword");
         set("wield_msg", "$N拿着$n, 似乎感受到了仙龙的气势。 \n");
	}
            init_sword(110);

	setup();
}
