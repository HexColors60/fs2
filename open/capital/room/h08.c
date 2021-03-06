// Room: /open/capital/room/h08.c

inherit ROOM;

void create ()
{
  set ("short", "扁鹊胡同");
  set ("long", @LONG
一代神医扁鹊曾在此地悬壶，故后人为纪念他的善行，便将此胡同
取名为扁鹊。当时扁鹊在此曾收了许多的弟子，后经代代相传，弟子日
渐众多，便在此成立了银针门，为医界之大宗, 许多的医者都是在此地
接受基础医术的训练, 东面那间房舍就是银针门。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"h06",
  "east" : __DIR__"CUR",
]));
  set("outdoors", "/open/capital");

  setup();
}
