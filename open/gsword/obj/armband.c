// kame_suit.c

inherit EQUIP;

void create()
{
        set_name("铁甲护臂",({"steel armband","armband"}) );
        set_weight(12000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","用熟铁制成的护臂,上面有美丽的花闻.\n");
        set("unit","件");
        set("value", 750);
        set("material","steel");
        set("armor_type","armbands");
	set("armor_prop/armor", 5);
	}
        setup();
}
