// Room: /d/oldpine/epath2.c

inherit ROOM;

void create ()
{
  set ("short", "蜀山奇阵");
  set ("long", @LONG
    风,在此停了,空气里带着一丝寒意的寂静,一层淡淡的雾随地四散,
一株古松(pine)拔地而起,迎向苍蓝的天空,你听到有人在远方吟诗,
    诗曰:
[36m       
       蜀山奇阵列山隈,飕飕寒意扑面催,  片片祥光笼斗怲,纷纷淡雾透灵台,
       鱼龙此际分真伪,玉石从此尽脱胎,  多少修持遭此劫,三尸斩去五云开.
[2;37;0m        
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "pine" : "你发现古松上有人刻字:
蜀山奇阵奇中奇,五行相克变化千.
仙剑弟子随意过,长笑一声跃(fly up)龙门.
",
]));

  set("light_up", 1);
  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/gsword/room/mroom7.c",
  "east" : "/open/gsword/room/lake0.c",
]));

  setup();
}

void init()
{
	add_action("fly_up","fly");
}

int fly_up(string arg)
{
	if(arg!="up" ){
		return 0;}
	message_vision("一片祥光中陇罩着$N....\n",
		this_player());
	if((string)this_player()->query("family/family_name") == "仙剑派" ) {
		message_vision("\n只见到一阵烟雾,$N消失在祥光中...\n", this_player());
                this_player()->move(__DIR__"test");
	} else {
		message_vision("\n只见一阵烟雾,一颗鸡蛋掉在$N的头上....\n",
			this_player() );
	}
	return 1;
}

