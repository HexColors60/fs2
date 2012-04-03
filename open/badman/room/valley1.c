// Room: /open/badman/room/valley1.c
// written by powell 96.4.26@FS

inherit ROOM;

void create ()
{
  set ("short", "神秘山谷");
  set ("long", @LONG
从密道钻出来后，居然来到了这个山谷，谷中林木茂盛，鸟语
花香，可真是个人间仙境。耳中不时传来″吱吱″叫的声音，听起
来好像是猴子的叫声，看来这山谷可是这群猴子们的天下。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"lake5",
  "east" : __DIR__"valley2",
]));
  set("outdoors", "/open/badman");

  setup();
}
