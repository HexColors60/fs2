inherit EQUIP;

void create()
{
        set_name("缎带", ({ "head-belt", "belt" }) );
        set_weight(1000);
                if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "系在头上的防护用具。\n");
                set("unit", "条");
                set("value",10000);
                set("material", "fur");
                set("armor_type", "head");
                set("armor_prop/armor", 5);
                
        }
        setup();
}                 