// Room: /open/gblade/port/room/p1-8.c
inherit ROOM;

void create()
{
  set ("short", "防具店");
  set ("long", @LONG
这是一家贩卖防具的商店 , 由于刀客擅长攻击 , 对于防
守并不那么注重 , 因此这里的生意就远不如武器店了 , 不过
买些东西来保护自己也是好的 , 你可以用 (list) 来得知老
板卖些什么东西 .

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"p1-7",
]));
	set("objects",([
	"/open/gblade/port/npc/lee":1,
	]));
  setup();
}
