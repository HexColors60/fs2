// Room: /open/capital/room/lake2
inherit ROOM;

void create ()
{
  set ("short", "芙蓉湖畔");
  set ("long", @LONG
更靠近湖了。有几条小舟闲散得荡在湖心，非常惬意。这湖不大，
却非常秀丽，像是世外桃源，和京城里的吵杂喧闹完全格格不入。你不
尽感谢大自然的鬼斧神工。北边有座精巧的凉亭。

LONG);


  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lake1",
]));
  set("outdoors", "/open/capital");
  set ("资源/液体", ([
       "种类" : "水",
       "名称" : "清水",
       "止渴" : 30
  ]) );

  setup();
}
