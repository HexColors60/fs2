// Room: /open/badman/room/forest16.c
// written by powell 96.4.26@FS

inherit ROOM;

void create ()
{
  set ("short", "湖边竹林");
  set ("long", @LONG
这儿也有着一大片的竹林，是由东边的竹林绵延过来，只不过
这儿的竹子(bamboo)比东边的稀疏了点，也因此这里较先前的地方
明亮了许多，这个竹林的西边是个明亮清澈的湖泊。
 
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lake0",
  "east" : __DIR__"forest15",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "bamboo" : "一根根细长的竹子。
",
]));
  set("outdoors", "/open/badman");

  setup();
}
