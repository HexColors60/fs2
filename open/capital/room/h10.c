// Room: /open/capital/room/h10.c

inherit ROOM;

void create ()
{
  set ("short", "芝麻胡同");
  set ("long", @LONG
你可以看到两旁的民宿屋顶上不时冒出阵阵的炊烟，引的你肚子咕
噜咕噜的叫了起来，在你的北方有一家全国知名的食堂叫做王安食堂，
不过劝你身上钱不够千万别进去。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"h09",
  "north" : __DIR__"food",
  "east" : __DIR__"h11",
]));
  set("outdoors", "/open/capital");

  setup();
}
