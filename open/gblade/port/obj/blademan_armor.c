// kame_suit.c

inherit EQUIP;

void create()
{
	set_name("刀者之铠",({"blademan armor","armor"}));
	set_weight(4000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long","初入江湖之刀客最常用的基本配备 .\n");
        set("unit","件");
	set("value",300);
	set("material","cloth");
	set("armor_type","armor");
	set("armor_prop/armor",3);
	}
        setup();
}
