#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
set_name(""HIY"□HIW"□HIY"□HIW"□HIY"□HIW"@"HIY"□HIW"□NOR"",({"light_gloves","gloves"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                 set("long",
                 "外面看起来虽然毫不起眼 , 但是当你戴上他时\n"
                 "就会发辉出无与伦比的威力 。\n");
                set("unit","件");
                set("no_sell",1);
                set("no_give", 1);
                set("no_auc",1);
                set("no_drop",1);
   set("no_get",1);
                set("no_put",1);
                set("material","leather");
                set("armor_prop/armor",15);
                set("armor_prop/parry",10);
                set("armor_prop/force",5);
set("wear_msg","四周光芒忽然聚集到$N的双手，$n已在你手上形成一道保护。\n");
 }
        setup();
}
