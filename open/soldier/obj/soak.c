#include <weapon.h>                           
#include <ansi.h>

inherit LANCE;
void create()
{           
           seteuid(getuid());
           set_name("雨不沾",({"rainno-soak","soak","rainno"}));
           set_weight(5000);
           if( clonep() )
                   set_default_object(__FILE__);
           else {
                   set("unit", "把");
           set("long","这是皮古在一个风雨大作,雷电交加的夜晚,所打造而成的长枪 .\n");
                   set("value",10000);
                   set("material", "blacksteel");
           set("wield_msg", "$N手中握起$n,忽然雷雨大作,突然你觉得$n是一个不可多
           得的好兵器 。 .\n");
           set("unwield_msg", "$N将$n收了起来,$N感觉$n丝毫没有半滴血留在上面。.\n");
           }
           init_lance(75);
           setup();
           }






