inherit EQUIP;

void create()
{
        set_name("工作裤", ({ "working pants", "pants"  }) );
        set("unit", "件");
        set("long", "一件油腻肮脏的裤子,做苦工最常见的裤子.\n");
        set("armor_type", "pants");
        set("armor_prop/armor", 5 );
        set("material", "布料");
        set_weight(1500);
        set("value",600);
        setup();
}
