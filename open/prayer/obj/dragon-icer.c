#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
     set_name( "龙之冰焰菱",({"dragon-icer","icer"}) );
     set_weight(12000);
     if( clonep() ) 
            set_default_object(__FILE__);
     else {
            set("long","徒手型武器，系以埋在万年不化雪石下的精钢打造而成，套在手上除
	    了增强攻击力之外，更可以使你在战斗中冷静地判断敌人的攻势。\n");
            set("unit", "把");             
            set("value",20000);
            set("material","steel");
            }
            init_unarmed(75);
 
          setup();
}                   