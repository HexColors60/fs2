// sword.c : an example weapon

#include <weapon.h>

inherit BLADE;
				
void create()
{
	set_name("虎头军刀",({"tiger blade","blade"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","由精钢铸成 , 非常锋利 , 是守卫队头的装备 .\,
 刀身染满了倭寇的鲜血 .\n");
		set("value",10000);
		set("material", "steel");
		set("wield_msg", "$N「唰”地一声抽出一把$n握在手中。\n");
		 set("unwield_msg", "$N将手中的$n收了起来 .\n");
	}
	init_blade(60);
	setup();
}
