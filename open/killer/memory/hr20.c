#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "莫塔湖瀑布");
  set ("long", @LONG
	
	高山上，银龙直泄，在你眼前的是万丈飞瀑，奔腾而下！！
	有如千军万马之势，隆隆之声，震荡澎湃，只听的令人心神舒畅，
	豪气千里，爽朗异常，舒服已极，令你不禁想放声狂啸！！！！
	如此巨大的瀑布，自然不可能纵身而下，必定粉身碎骨。
	所以一旁有高人依山壁所筑的立足点，你可以踏那些立足点往下而去。

LONG);

  set("exits", ([ /* sizeof() == 3   */
     "north" : __DIR__"hr19.c",   
     "down" : __DIR__"lk1.c",   
]));

  setup();
}
