inherit EQUIP;

void create()
{
        set_name("麒麟腰带",({"kylin belt","belt"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","抽取血麒麟的筋脉与其皮革混织而成的腰带 , 可增强身体的防御度 .\n");
        set("unit","条");
        set("value",50000);
        set("material","leather");
        set("armor_type","waist");
        set("armor_prop/armor", 5);
        }
        setup();
}                        