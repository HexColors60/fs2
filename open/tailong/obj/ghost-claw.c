//  made by xman

#include <weapon.h>
#include <ansi.h>
inherit UNARMED;
void create()
{
        object me=this_player();
        set_name(HIB"鬼指神抓"NOR, ({"ghost-claw", "claw"}) );
        set_weight(6000);
        if( clonep() )
         set_default_object(__FILE__);
        else
         {
          set("unit", "个");
          set("long","一把奇门兵器, 外型古怪无比, 正是云中鹤最喜爱的武器。\n");
        set("wield_msg", HIB"$N将$n"HIB"载在手上，一股诡异的气息垄罩着四周。\n"NOR);
          set("value", 10000);
          set("material", "crimsonsteel");
         }
        init_unarmed(80);
        setup();
}

