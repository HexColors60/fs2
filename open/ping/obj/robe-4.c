inherit EQUIP;
void create()
{
        set_name("五品睨兽官服",({"robe"}) );
        set_weight(7000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","一件五品睨兽官服,上面用金丝织上了美丽图案.\n");
        set("unit","件");
        set("value",1000);
	set("material","cloth");
        set("armor_type","cloth");
	set("armor_prop/armor", 5);
	set("armor_prop/dodge",1);
	set("armor_prop/parry", 1);
	}
        setup();
}
