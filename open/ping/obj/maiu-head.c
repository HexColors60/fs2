inherit ITEM;

void create()
{
        set_name("苗王的人头", ({ "maiu-head" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
set("long","苗王的人头,看来怪恶心的.\n");
                set("value", 0);
        }
}

