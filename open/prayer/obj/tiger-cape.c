inherit EQUIP;

void create()
{
        set_name("虎头肩",({"tiger cape","cape"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","以邪虎的虎头做为装饰的护肩, 能增强身体上的防御度 .\n");
        set("unit","件");
        set("value",6000);
        set("material","leather");
        set("armor_type","cape");
        set("armor_prop/armor", 1);
        }
        setup();
}                        