#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIW"跛脚老头的第二封信"NOR, ({"oldman letter2","letter2"}));
    set("long","第二封跛脚老头给华陀的信...\n");
    set_weight(10);
    set("unit","封");
    setup();
}
