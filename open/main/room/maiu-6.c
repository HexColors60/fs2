// Room: /open/main/room/maiu-6
inherit ROOM;

void create()
{
  set ("short", "茅草屋");
  set ("long", @LONG
你走进一间茅草屋,简陋的摆设,破旧的家具,这就是苗人的
住所,完全无法跟中原民家的富丽相比,与平南连年的征战带来了
穷困与疾病,这难道是苗人命运的枷锁?
LONG);

  set("objects",([
      "/open/ping/npc/maiu-leader" : 1,
      ]));      
  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"maiu-4",
]));
  setup();
}
