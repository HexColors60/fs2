#include <weapon.h>
#include <ansi.h>

inherit BOW;

void create()
{

set_name("广寒弓",({"cold bow","bow"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long","一把由李广所持有的弓。\n");
 
set("material","steel");
        }
init_bow(60);
set("value",0);
setup();
}
