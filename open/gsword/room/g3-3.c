// Room: /open/gsword/room/g3-3.c
inherit ROOM;

void create ()
{
  set ("short", "储藏室");
  set ("long", @LONG
这是仙剑派堆放杂物的储藏室 ,你看到一个个箱子整齐的排放在房
子四周 ,箱子及地上铺满了一层厚厚的灰尘 ,似乎甚少人来此 .

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/gsword/room/g3-2",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/obj/map1" : 1,
]));
	set("light_up",1);

  setup();
}
