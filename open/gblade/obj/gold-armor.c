inherit EQUIP;

void create()
{
	set_name("精金战铠",({"gold armor","armor"}));
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
由精钢混合黄金打造而成 , 防护颇佳 ,但甚为沉重。
");
        set("unit", "套");
	set("value",4000);
        set("material","crimsonsteel");
	set("armor_type", "cloth");
	set("armor_prop/armor",20);
	set("armor_prop/dodge", -2);
	set("armor_prop/move",-2);
        }
        setup();
}
