// Room: /u/d/devils/school7.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是馆主考较徒弟武功的地方,但由于徒弟日益增多,馆主不再一一指
导,所有弟子需在此比武,获胜弟子才能得到馆主的亲自指导．
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"school2",
  "south" : __DIR__"school6",
  "north" : __DIR__"school4",
  "east" : __DIR__"school8",
]));

        set("outdoors", "/open/wu");
        setup();
}
