// kame_suit.c

inherit EQUIP;

void create()
{
        set_name("武者战袍",({"robe"}) );
        set_weight(7000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","一般武士所爱用的战袍,能提供一些保护.\n");
        set("unit","件");
        set("value",1000);
	set("material","cloth");
        set("armor_type","cloth");
	set("armor_prop/armor", 7);
	set("armor_prop/dodge",1);
	set("armor_prop/parry", 1);
	}
        setup();
}
