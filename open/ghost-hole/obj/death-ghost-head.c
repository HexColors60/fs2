#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIB"死冥王的首级"NOR, ({ "death-ghost-head","head" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long","死冥王的首级!!\n");
                set("value", 0);
                set("no_sell",1);
                set("no_put",1);
                set("no_auc",1);
                set("no_sac",1);
                set("no_drop",1);
        }
}

