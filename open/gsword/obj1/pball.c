#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC"丽玉蝶兰晶珠"NOR, ({ "pball" }));
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "个");
        set("long","开天三灵器中丽玉蝶兰所化之晶珠,似乎具有神奇之功效。\n");
        set("no_drop", 1);
        set("no_auc", 1);
        set("value", 0);
        }
}    
