//虹晶头钗---2000.4.3 by dhk
#include <armor.h>
#include <ansi.h>

inherit HEAD;
void create()
{
        set_name(HIM"虹晶头钗"NOR, ({"diamond hairpin", "hairpin"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long", "一件由北胜天使用＂虹晶″特异矿石铸成，表面散发着特异的紫光，是万年的宝物。\n");
            set("unit", "支");
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1); 
            set("value", 300000);
            set("material", "diamond");
            set("armor_prop/armor", 10);
        set("armor_prop/dodge",7);
        set("armor_prop/move",7);
        }
        setup();
}

