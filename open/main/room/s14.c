// Room: /open/main/room/s14.c

inherit ROOM;

void create ()
{
  set ("short", "草原");
  set ("long", @LONG
这里是一片草原，割人的野草凌乱的长着，高高低低的芒
穗随着风起伏，这里应该有不少动物躲藏，北方有座黑色的高
山，但山腰以上被云雾围绕着，似乎带着邪气.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"d14",
  "west" : __DIR__"s13",
  "south" : __DIR__"p6",
]));
  set("outdoors", "/open/main");

  setup();
  replace_program(ROOM);
}
