// fusword.c
#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
        seteuid(getuid());
         set_name(HIR"血"+HIB"影摧"+HIR"心"NOR,({"blood figring","figring"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
set("long","不知何人曾用它来屠杀过无数百姓，浓厚的血腥味，似乎附有无数怨灵．\n");

                set("value",10000);
                set("material", "steel");
                  set("armor_prop/unarmed",10);
     set("wield_msg", "$N运足五成功力戴上$n，脸上微微露出狰狞的面孔。 \n");
      set("unwield_msg", "$N你将手上的$n卸了下来，缓缓的吐出一口阴气。\n");
        }
        init_unarmed(80);
        setup();
}
