
#include <weapon.h>

inherit AXE;
void create()
{
        set_name("铁斧",({"axe"}) );
	set_weight(4000);
	if( clonep())
		set_default_object(__FILE__);
	else{
	set("long","
一把十分锋利的单刃斧头，全身以钢铁铸成，拿起来十分地重。\n");
	set("value",120);
	set("material","steel");
	set("unit","柄");
	}
	init_axe(7);
	setup();
}

 
 
