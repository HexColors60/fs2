inherit EQUIP;

void create()
{
        set_name("风之短统靴",({"wind boots","boots"}) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","西域特制的靴子，以西域特制的布料与皮革混织而成。\n");
        set("unit","双");
        set("value", 1500);
        set("material","leather");
        set("armor_type","boots");
        set("armor_prop/armor", 1);
        }
        setup();
}        