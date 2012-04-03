#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit BLADE;
object ob=this_object();
void create()
{
	set_name("妖刀‘村雨’",({"evil-mblade","blade"}));
	set_weight(300);
set("mblade-mark",1);
        set("no_sell",1);
      set("no_get",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_auc",1);
        if( clonep() )
          set_default_object(__FILE__);
        else 
        {
          set("unit","把");
set("long","妖刀‘村雨’，刀锋透明，刀身绯蓝，像透明的雨点镶在绯蓝色的骨脊，刀略长，刀弯处有突出的小尖刃，临阵杀敌有种莫名快感。\n");
          set("value", 100);
          set("material","crimsonsteel");
	}
	init_blade(1);
  	setup();
}	
void init()
{
        add_action("do_blood","blood");
        add_action("do_power","power");
}

int do_blood(string str)
{  	
	object me=this_player();
        string name=ob->query("name");
        if( str != ob->query("id") )
	   return notify_fail("请键入武器全名。\n");
	if( ob->query("blooded") )
	  return notify_fail("这把武器已得到你的牺牲。\n");
	if( ob->query("equipped") == "wielded" )
	  return notify_fail("请先将武器卸下。\n");
	message_vision("[31m$N缓缓的用"+name+"往手腕处一划, 鲜血如泉涌般淋遍整把"+name+"。\n
一会儿, 鲜血已被"+name+"吸干殆尽,而"+name+"也旦然的发出一阵耀眼的[1;5;33m光芒[0;31m。[0m\n",me);
set_name("[1;34m□[0;34m□[1;34m□[0;34mM[1;31m‘[1;37m□[1;32m□[1;37m□[1;32mB[1;31m’[0m",({"evil-mblade","blade"}));
set("wield_msg","\n$N手上忽然多了一把$n，刀光漾映一片沁蓝，刀挥动时还带着一种像阴灵般的呻吟。\n\n");
set("unwield_msg","\n$N手上的$n像七月半猛鬼出关，忽然自手上消失无踪。\n\n");
	set("weapon_prop/damage",100);
	set("value", 100);
	set("blooded",1);
set("mblade-mark",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
     set("no_get",1);
        set("no_drop",1);
        set("no_auc",1);
        me->set("kee",1);
        me->set("gin",1);
        me->set("sen",1);
        setup();
	return 1;
}

int do_power(string str)
{
        object weapon,me;
        me=this_player();
        if(me->query("evil-mblade") != 1)
        return notify_fail("你无法驾御此刀。\n");
        if(!objectp(weapon=me->query_temp("weapon"))
        || (string)weapon->query("skill_type")!="blade")
          return notify_fail("要有刀才能用聚魂术。\n");
   if(ob->query("blooded")!=1)
   return notify_fail("要先用血(blood)喂你的刀唷！\n");
        if(weapon->query_temp("evil-mblade")==1)
          return notify_fail("你已经在用了。\n");
        message_vision(
  HIR "$N以刀祭天，顿时阴灵凝聚于$n"+HIR+"。\n"NOR,me,weapon);
me->add_temp("apply/damage",100);
me->add_temp("apply/attack",100);
me->add_temp("apply/armor",100);
me->add_temp("apply/defense",100);
        weapon->set_temp("evil-mblade",1);
me->start_call_out((:call_other,__FILE__,"remove_effect",weapon,me:),me->query_skill("blade",1));
        return 1;
}
void remove_effect(object weapon,object me)
{
me->add_temp("apply/damage",-100);
me->add_temp("apply/attack",-100);
me->add_temp("apply/armor",-100);
me->add_temp("apply/defense",-100);
weapon->delete_temp("evil-mblade");
message_vision(HIW"阴风徐徐的阴灵，顿时从$n"+HIW+"飞散开来。\n"NOR,me,weapon);
}
int query_autoload()
{
	return 1;
}
