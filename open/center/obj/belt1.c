inherit EQUIP;

void create()
{
        set_name("腰带", ({ "belt" }) );
        set_weight(500);
        set("long", "一条有虎状花纹的腰带" );
        set("unit", "件");
        set("value",100);
        set("material", "leather");
        set("armor_type", "waist");
        set("armor_prop/armor", 10);
        setup();
}
