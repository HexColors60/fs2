#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("玉鐕",({"topknot"}) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
else    {
        set("meterial","gem");
        set("unit","件");
        set("value", 100);
        set("armor_type","head");
        set("armor_prop/armor", 1);
        set("long","
        和阗玉一体成形所制成的玉鐕，是玉女派掌门所用的装饰品。\n");
        }
         setup();
}





