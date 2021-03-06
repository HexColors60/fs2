// dragon_sword.c

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit SSERVER;

void create()
{
	set_name(HIY "穿龙剑" NOR,({"dragon sword","sword"}));
	set("灵气量",120);
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value",10000);
		set("material","steel");
		set("long",@LONG
这把是独孤世家世代相传的宝物之一，相传这把剑
不但有削铁如泥之能，还具有一种神奇的魔力，但是，
使用的方法只有独孤世家的人知道。
LONG);
		set("wield_msg",@LONG
只见$N抽出了$n之后寒光似射，一团团的剑气已包围在$n周围！
LONG);
	}
	init_sword(50);
	setup();
}
void init()
{
	add_action("do_cast","power");
}
int do_cast(string arg)
{
	object ob = offensive_target(this_player());
	if( !ob ) return 0;
	if( arg != "sword" ) return 0;
	if( query("灵气量") <= 0 ) {
		tell_object(this_player(),"你的穿龙剑已经失去了灵气，无法再使用。\n");
		return 1;
	}
	message_vision(
	HIR "$N一声大喝：手中穿龙剑发出一阵雷鸣，只见一条赤龙钻出！\n" NOR,
	this_player());
	message_vision(
	HIR "只见赤龙在$n身边穿过，$n血流如柱！\n" NOR,this_player(),ob);
	ob->receive_wound("kee",query("灵气量"));
	COMBAT_D->report_status(ob);
	add("灵气量",-random(20));
	this_player()->start_busy(3);
	return 1;
}
