///open/prayer/room/hole/2.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	走到洞口，一阵金铁交击之声，在耳际铿锵作响，震的你心头直打
	寒颤，听说里头魔兽肆孽，能够进来，未必能出的去，想想大好将
	来，是否该淌这趟浑水...........

LONG);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"1",
  "east":__DIR__"3",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}