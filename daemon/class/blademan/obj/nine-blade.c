//nine-blade.c
#include <weapon.h>
#include <ansi.h>


   inherit BLADE;
void create()
{
	seteuid(getuid());
set_name(HIB "九环宝刀" NOR,({"nine blade","blade"}));
	set_weight(13000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
   set("long","一把沉重的巨刀 ,刀背有九个刀环 .\n");
		set("value",10000);
		set("material", "steel");
	set("wield_msg", "$N从背后抽出$n,顿时全身充满力量。\n");
	set("unwield_msg", "$N将手中$n收回。\n");
	}
	init_blade(80);

/*
	set("ski_type1", "blade");
	set("ski_level1", 75);
*/

	setup();
}
