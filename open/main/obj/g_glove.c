inherit EQUIP;
#include <ansi.h>
void create()
{
    set_name(HIY"金"+HIW"蚕"+NOR"护手",({"gold gloves","gloves"}));
	set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
千年金蚕丝所制成的手套，能提升防御度及加强自身攻击。
");
        set("unit", "双");
	set("value",4000);
        set("material","cloth");
	set("armor_type", "hands");
	set("armor_prop/armor",10);
      set("armor_prop/attack",8);
      set("armor_prop/parry",8);
        }
        setup();
}
