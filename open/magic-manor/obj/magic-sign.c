#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC"聚灵引"NOR, ({ "magic sign","sign" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "块");
		set("long","通往聚灵山庄的导引之物。\n");
		set("value", 0);
		set("no_sell",1);
		set("no_put",1);
		set("no_auc",1);
		set("no_sac",1);
		set("no_drop",1);
		set("no_steal",1);
		set("no_give",1);
		set("magic-manor",6);

        }
}
