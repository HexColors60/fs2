// Room: /u/d/devils/school11.c

inherit ROOM;

void create()
{
	set("short", "藏宝库");
	set("long", @LONG
这是一间仓库，堆满了杂七杂八的物品，你放眼望去似乎没有任何
稍有价值的东西，这里的地板很干净，不像一般仓库满地灰尘，左边角
落放着一个不起眼的箱子......
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "door" : "一个没有把手的暗门，你可以推推看。
",
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"school8",
]));

	setup();
}
