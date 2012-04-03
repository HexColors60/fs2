// Room: /u/u/unfinished/room/is1.c
inherit ROOM;

void create ()
{
  set ("short", "石丘");
  set ("long", @LONG
位于小岛的西南角, 小岛上突起的小石丘, 石丘上草不不生, 只有遍地白沙
及碎岩石. 伫立此处可以看到这座小岛的大概地形. 北边是茂密的树林, 东边是
沿岸. 此地地高风劲, 站在此处不禁令人有"天地独我任逍遥"的感觉.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"is6.c",
  0 : __DIR__"quest",
  "east" : __DIR__"is2.c",
]));
  set("outdoors", "y");

  setup();
}
