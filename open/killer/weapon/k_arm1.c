inherit EQUIP;
void create()
{
        set_name("黑巾护手 ",({"black armband","armband"}) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","此乃杀手的基本装备，极为稀松平常的装备");
        set("unit","个");
        set("value",1750);
        set("material","silver");
        set("armor_type","armbands");
        set("armor_prop/armor", 2);
        set("armor_prop/parry", 2);
        }
        setup();
}