// Room: /open/hall/way2.c

inherit ROOM;

void create()
{
        set("short", "厅旁走道");
        set("long", @LONG
这儿是一条铺了石子的走道，走道两旁各有一个花圃，里头杂草丛
生，似乎很久没人整理啰......
LONG);
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"way3",
  "east" : __DIR__"hall.c",
]));

        setup();
}
