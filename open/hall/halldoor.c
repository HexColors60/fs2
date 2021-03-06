// Room: /open/capital/room/halldoor
inherit ROOM;

void create ()
{
  set ("short", "衙门大门口");
  set ("long", @LONG
你看到的是京都总理衙门，掌管一切非法事项，由于前朝有个大公
无私的铁面包拯，遗风仍在，因此一切诬告在此乃事所必行。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/capital/room/r33",
  "enter" : __DIR__"hall",
]));
  set("item_desc", ([ /* sizeof() == 2 */
  "sign" : "有怨抱怨，有仇报仇。",
  "door" : "京都总理衙门大门口",
]));
  set("outdoors", "/open/capital");

  setup();
}
