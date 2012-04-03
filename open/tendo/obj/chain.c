// chain.c
#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
	set_name(HIG "青龙崩云锁" NOR,({"dragon chain","chain"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","条");
                set("value",30000);
		set("material","blacksteel");
		set("rigidity",60);
		set("long",
	"\n一条龙形的锁链，相传是天界锁龙关的镇关之物。\n");
	set("wield_msg", "$n感应到$N的智慧，一股龙气自$N手中窜出。\n");
	set("unwield_msg","$n上的异光渐渐黯淡下来。\n");
	}
	init_whip(90);
	setup();
}




