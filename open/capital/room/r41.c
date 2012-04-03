// Room: /open/capital/room/r41.c

inherit ROOM;

void create ()
{
  set ("short", "永福胡同");
  set ("long", @LONG
杂草丛生的石板路。往东北去是日升驰道。南边远远看到几座烽火
台。这些烽火台是京城遭袭时向镇守各边关的大将求援用的。这几年天
下太平，烽火台的狼烟已经好久没有燃过了。
    这里有禁卫军四处的巡逻着，所以你还是不要在城内惹事的好。

LONG);

  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"r42",
  "west" : __DIR__"r39",
]));
  set("gopath", "west");

  setup();
}
