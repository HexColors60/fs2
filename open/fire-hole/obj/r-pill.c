inherit COMBINED_ITEM;
#include <ansi.h>
void create()
{
set_name(HIR"红龙精元"NOR, ({"red-dragon pill","pill"}) );
set("long","红龙身上取得的精元, 传闻中可暂时增加闪躲的能力!!\n");
set("base_unit", "粒");
set("unit", "粒");
set("no_sell",1);
set("no_steal",1);
set("value",99000);
set_amount(1);
setup();
}
void init()
{
add_action("eat_pill", "eat");
}
int eat_pill(string arg)
{
object ob,me=this_player();
if( !arg )                     
return 0;
if( !ob = present(arg,me) )     
return 0;
if( ob != this_object() )       
return 0;
if (me->query_condition("dodge_pill") > 0)
return notify_fail("药效未除无法再吃!!\n");
message_vision(HIR"$N吃下红龙精元, 能力突增!!\n"NOR, me);
me->add_temp("apply/dodge",100);
me->apply_condition("dodge_pill",20);
add_amount(-1);
return 1;
}
