//dancerboots//
#include <ansi.h>
inherit EQUIP;
void create()
{
        set_name(MAG "忍者鞋" NOR,({"boots"}) );
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else{
        set("long","此为东瀛忍者特制的工作鞋，效果非常特别\n");
        set("unit","双");
        set("value",20000);
        set("armor_prop/armor",3);
        set("armor_prop/dodge",3);
        set("armor_prop/parry",2);
        set("material","leather");
        set("armor_type","boots");
        setup();
        }
}