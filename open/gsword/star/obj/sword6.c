// sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	seteuid(getuid());
    set_name("天璇之剑"NOR,({"star sword","sword"}));
	set_weight(6700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value",20000);
		set("material", "steel");
     set("wield_msg","将$n从腰际抽出,天上天璇的星力源源不断的向$n注入.\n");
		set("unwield_msg", "$N将手中$n插入腰入的剑鞘之中。\n");
	}
        init_sword(55);
	setup();
}
