#include <weapon.h>
#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("血丝带", ({"daemon belt","belt"}));
        set_weight(2000);
        if ( clonep() )
                 set_default_object(__FILE__);
        else {
                 set("unit", "付");
                 set("armor_type", "waist");
                 set("material", "leather");
                 set("armor_prop/armor",10);
                 set("value", 5000);
                 set("wear_msg", "$N把$n系在腰上。\n");
        }
        setup();
 }                      
