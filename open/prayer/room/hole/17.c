///open/prayer/room/hole/17.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	你慢慢拨开蜘蛛网来到这里，眼前这也比刚刚空旷多了，空气比较
	清新，周围也比较干净，你心中窃窃自喜，但还是不能大意，以免
	横尸荒野..

LONG	);
 
    set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/bird" : 1,		
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"3",
  "west":__DIR__"16",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}