// 金风细雨楼信物--风雨令
//roger && taifar
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIY"风雨令"NOR, ({"wind_rain mark","wind_rain" }));
	set_weight(5);
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1);
        set("no_give",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long","
   风雨令，传说中的神秘帮会「金风细雨楼”的信物，一向为各代楼主所有。
   此令足以号令武林，并可调度风雨楼中"HIY"「金风细雨”"NOR"四辈护卫，持此令者一
   向就是公认的武林盟主。改朝换代时一度下落不明，如今重出江湖，代表着
   和平盛世已经走到了尽头，楼中风雨欲来。

   细看此令，两面分别书着"HIC"「风”"HIW"「雨”"NOR"两大字，另外有两行小字:

              "HIC"不见风雨，治世有明  风雨骤遇，乱世荼灵"NOR"

\n");
		set("value", 100);
		set("material", "paper");
	}
        setup();
}
int query_autoload()
{
if(this_player()->query("mark/武林盟主",1)==1)
return 1;
}
