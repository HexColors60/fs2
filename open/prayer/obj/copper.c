//黄铜()
#include <command.h>
inherit ITEM;

void create()
{
        set_name("黄铜", ({ "copper" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "块");
          set("long",@LONG
	这是一块黄铜!!黄铜的物理性质较生铁稳定, 是最早被使用
	的金属!!你可以将这块黄铜拿去打造成武器或是防具!!不过
	黄铜的硬度较铁小, 所以做成的武器可能会很容易就断掉了
	!!
LONG);
          set("value", 800);
          set("material", "copper");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}


