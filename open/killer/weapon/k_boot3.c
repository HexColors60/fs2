#include <ansi.h>
inherit EQUIP;
void create()
{
        set_name(HIY "龙飞鞋" NOR,({"boots"}) );
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else{
                set("long","
这是叶秀杀专用的神奇鞋子，相传为诸冈渡所赠的八头大蛇皮所制，内含草雉剑的灵气
相传更有不可思议之效。\n");
                set("unit","双");
                set("value",20000);
                set("armor_prop/armor",5);
                set("armor_prop/dodge",2);
                set("armor_prop/move",3);
                set("material","leather");
                set("armor_type","boots");
            set("wear_msg", "$N穿上$n忽然感到身子轻盈了起来，好似要飞一般。\n");
            set("remove_msg", "$N将$n脱了下来，感到身体一沉，又恢复原状了。\n");
                setup();
        }
}