#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name(HIW"削"HIC"云"HIG"匕"HIM"首"NOR,({"cloud dagger","dagger"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
                set("unit", "把");
                set("long","\n");
                set("value",1000000);
                set("material", "iron");
        }
        init_dagger(1);


        set("wield_msg", HIY"$N手握$n"HIY"，顿时风云大作，晴天霹雳～\n"NOR);
        set("unwield_msg", HIW"$N将手中的$n"HIW"收好，放入了腰间。\n"NOR);
        setup();
}

