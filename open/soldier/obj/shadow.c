#include <weapon.h>                           
#include <ansi.h>

inherit LANCE;
void create()
{           
           seteuid(getuid());
  set_name("水影",({"Water-shadow","shadow"}));
           set_weight(15000);
           if( clonep() )
 set_default_object(__FILE__);
           else {
                   set("unit", "把");
           set("long","传说中水神为了打倒魔界头头的儿子,将自己的血做出一个
           强力魔法阵,他在结界里花了七七四九天塑造而成,造出来时他已身心俱疲
           无力再战,他使出全力把枪丢出去并大喊水影去找一位能打倒他的人吧..,
           ...\n");
                   set("value",3500);
                   set("material", "gold");
           set("wield_msg", "$N举起$n,你感觉你的力量被$n抽走了,枪身并发出强
           烈的光。  .\n");
           set("unwield_msg", "$N放下$n,$N感觉轻松多了。.\n");
           }
           init_lance(40);
           setup();
           }






