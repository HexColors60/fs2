#include <ansi.h>
inherit EQUIP;
void create()
{
 set_name("星空手链" , ({"starbracelet"}) );
     set_weight(200);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("long", "由星石所串成之手链, 散发着星石之能。\n");
            set("unit", "串");
            set("armor_type", "wrists");
            set("value", 10000);
            set("armor_prop/parry",2);
		set("armor_prop/armor",3);
            set("armor_prop/sword",2);
            set("wear_msg", "$N小心翼翼将$n往手上戴去。\n");
     }
}
