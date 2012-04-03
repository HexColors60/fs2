// Room: /open/main/room/cloister.c

inherit ROOM;

void create()
{
	set("valid_startroom",1);
	set("short", "玉矶道观");
	set("light_up",1);
	set("long", @LONG
	这座道观供奉着太上老君，老君雕像前的香炉冒着
	缕缕的清烟，似有似无的檀香飘散在空气中，令人
	倍觉舒畅。


LONG
	);
	set("no_fight",1);
	set("no_magic",1);
	set("objects",([
	"/daemon/class/taoist/master" : 1,
		]) );
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"M14",
]));

	setup();

}
