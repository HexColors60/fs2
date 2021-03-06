// blade.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(RED "风林火山" NOR, ({ "nature blade","blade" }) );
	set_weight(24000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value",6000000);
		set("material", "steel");
		set("long", @LONG
这把刀看起来像是一把平凡无奇的木刀,但在刀身上可以隐隐约约的看出
「风林火山”四个小字,难道这就是传说中的远古神器？
LONG);
		set("wield_msg", "\
$N口中喃喃念着$n刀背上的咒语,瞬间天地变色! $n从$N背后的刀鞘中\n\
冲向天际吸取刀气,在空中回旋了几圈后慢慢的降在$N的手中,并且发出黯黯的红光。\n");
		set("unwield_msg", "\
$N将$n往空中抛去,$n在空中释放刀气后伴随着\n\
一阵强光,咻~~~一声$n回到$N背后的刀鞘中。\n");
	}
	init_blade(100);
   
        set("ski_type1","blade");
        set("ski_type2","spell");
        set("ski_level1",80);
        set("ski_level2",85);
	setup();
}

int wield()
{
  object ob;
  ob=this_player();
  message_vision(HIY"上古兵器「风林火山”受法主"+ob->name()+"的咒术招唤.....\n\n"
		"飞往空中吸收大地灵气,你可以看到一阵阵的绚丽耀眼\n\n"
                "的五彩光芒从四面八方飞往东方,宛如流星赶月一般的\n\n"
                "的消失在你的眼前。......\n\n"NOR,ob);
  ob->add("mana",-100);
  ::wield();
  return 1;
}
