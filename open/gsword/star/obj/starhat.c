#include <ansi.h>
inherit EQUIP;

void create()
{
 set_name("星护之盔",({"starhat","starhat"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","由星之石所铸 , 具有不错的防护力 .\n");
        set("unit","件");
        set("value",2000);
        set("material","cloth");
        set("armor_type","head");
        set("armor_prop/armor",11);
        set("armor_prop/parry", 2);

        }
        setup();
}
