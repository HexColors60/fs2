// 地邪鬼weapon exp 175万
// QC by Anmy (98/3/3)
#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
	seteuid(getuid());
        set_name("龙虎钢环",({"dragon tiger circle","circle"}));
        set_weight(3500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "对");
         set("long","传说中一对右大左小的奇形空手武器。\n");

                set("value",70000);
		set("material", "steel");
                set("ski_level",70);
                set("ski_type","unarmed");
         set("wield_msg", "装备上$n,$N的攻击力大幅提升\n");
		set("unwield_msg", "$N放下$n,脸色缓和多了。\n");
	}
          init_unarmed(55);

	setup();
}
