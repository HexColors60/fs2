#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"独孤嵊的人头"NOR, ({ "sa-head" }));
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "个");
        set("long","武天至圣‘独孤嵊’的人头。\n");
        set("value", 0);
        }
}

