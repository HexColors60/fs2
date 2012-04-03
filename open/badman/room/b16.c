// Room: /open/badman/room/b16
inherit ROOM;

void create ()
{
  set ("short", "恶人谷南街");
  set ("long", @LONG
这儿有几个小贩聚集在此地，不知道他们在卖些甚么，也许你
有兴趣问问看。此外，还有几只顽皮的小麻雀，在屋顶和地面间飞
来飞去，可爱的模样让你想好好亲近它们，或许正是因为你厌倦了
在恶人谷的那股似有若无的肃杀气息。

LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/badman/npc/sparrow" : 3,
  "/open/badman/npc/vendor" : 1,
]));
  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"b17",
  "east" : __DIR__"b15",
]));

	set("no_transmit",1);
  setup();
}
void init()
{
        object who=this_player();
        who->set_temp("can_feed",1);
}

int valid_leave(object who,string dir)
{
	who->delete_temp("can_feed");
        return ::valid_leave(who,dir);
}
