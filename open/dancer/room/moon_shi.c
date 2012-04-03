// Room: /open/dancer/room/moon_ship
inherit ROOM;

void create ()
{
  set ("short", "弯月舫");
  set ("long", @LONG
雕饰着云女玩月图的弯月舫, 船体是由千年神木所輮制而成, 
是当今京城首富赠与双月姊妹的礼物, 只为能够欣赏一次她们媲美
天仙的技艺. 姊妹偶尔会乘着弯月舫游湖赏景, 但通常都是让弟子
们外出购物用.
LONG);

  set("light_up", 1);
  set("no_magic", 1);
  set("outdoors", "/open/dancer");
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road_m",
]));
  set("no_fight", 1);

  setup();
}
