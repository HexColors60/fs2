
#include <ansi.h>
#include <room.h>

inherit ITEM;

void create()
{
        set_name("鲜花",({"flower"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","这是一束很漂亮的花, 如果拿去送女友一定很棒喔。\n");
        set("unit","束");
        set("value",1000);
        }
        setup();
}
