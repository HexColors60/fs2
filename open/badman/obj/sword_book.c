//badsword-book.c
inherit ITEM;
void create()
{
        set_name("魔日剑谱",({"badsword book","book"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "魔日剑谱，记载着魔日剑法的运用法门．\n");
                set("value", 800);
                set("material", "paper");
                set("skill", ([
                        "name":        "badsword",
                        "sen_cost":     30,
                        "potential_cost":      1,
                        "difficulty":   20,
                        "max_skill":   100,
                ]) );
        }
        setup();
}
