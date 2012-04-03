inherit ROOM;

void create ()
{
  set ("short", "不知名的空间");
  set ("long", @LONG
这是一个神秘的地方，四周不断的有人影在闪动
你能感觉到你来到一个未知的空间，并且被监视中，
或许讯速离开这个地方是你最好的选择。
LONG);

  set("exits", ([ /* sizeof() == 5 */
  "south" : __DIR__"s3.c",
  "up" : __DIR__"s1.c",
  "west" : __DIR__"s4.c",
  "down" : __DIR__"s2",
  "east" : __DIR__"s2.c",
]));

  setup();
}
