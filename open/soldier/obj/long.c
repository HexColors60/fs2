
#include <weapon.h>
#include <ansi.h>
inherit LANCE;
void create()
{
        seteuid(getuid());
set_name("长枪",({"long lance","lance"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
    set("long","这把枪身和枪间都是用铁所打铸的,尤其他的枪身比木枪长一点.\n");
                set("value",3000);
                set("material", "iron");
 }
        init_lance(20);
        setup();
}

