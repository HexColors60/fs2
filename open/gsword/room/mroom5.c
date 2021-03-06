// Room: /d/oldpine/pine1.c

inherit ROOM;

void create ()
{
  set ("short", "蜀山奇阵之五行");
  set ("long", @LONG
你看到一阵妖火漫天而来,你的四周只是一片: 火 !! 火 !! 火
 !! 熊熊烈火像似燃烧着你的身体,却又不对你造成任何损伤,幻像?
? 是的幻像,这一定只是幻像 !! 只要你能勘破幻像,必能破解这奇阵
...
LONG);

  set("light_up", 1);
  set("outdoors", "/open/gsword/room");
  set("exits", ([ /* sizeof() == 4 */
  "wood" : __DIR__"mroom1",
  "gold" : __DIR__"mcenter",
  "land" : __DIR__"mroom2",
  "water" : __DIR__"mroom2",
]));

  setup();
}

void reset()
{
	::reset();
	set("exits", ([ 
	  "wood" : __DIR__"mroom" + (random(4)),
	  "gold" : __DIR__"mcenter",
	  "water" :  __DIR__"mroom" + (random(4)),
	  "land" :  __DIR__"mroom" + (random(4)),
	]));
}

int valid_leave(object me, string dir)
{
	write("一阵妖火卷袭着你....\n");
	switch(dir) {
		case "wood":	write("你往木相离开.....\n");	break;
		case "land":	write("你往土相离开.....\n");	break;
		case "water":	write("你往水相离开.....\n");	break;
		case "gold":	write("你往金相离开.....\n");	break;
		default:
			write("你通过一道火焰....");
	}
	return 1;
}
