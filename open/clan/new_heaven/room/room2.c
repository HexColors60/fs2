// Room : /open/clan/new_heaven/room/room2.c
 inherit "/open/clan/std/act.c";

void create()
{
        seteuid(getuid());
	set( "short", "云道" );
	set( "objects", ([ /* sizeof() == 1 */
  "/open/clan/new_heaven/npc/npc3" : 1,
]) );
	set( "exits", ([ /* sizeof() == 2 */
  "south" : "/open/clan/new_heaven/room/hall",
  "north" : "/open/clan/new_heaven/room/room4.c",
]) );
	set( "outdoors", "/open/clan" );
	set( "cmkroom", 1 );
	set( "no_transmit", 1 );
	set( "light_up", 1 );
	set( "clan_room", 0 );
	set( "long", @LONG
这是用云做成的走道, 走的时候小心点, 别摔下去了
LONG);
	set( "action", ([ /* sizeof() == 1 */
  "nod" : ([ /* sizeof() == 7 */
      "filename" : "",
      "later_msg" : "",
      "before_msg" : "",
      "msg" : "",
      "keyword" : "",
      "err_msg" : "",
      "type" : "action_move",
    ]),
]) );
	set( "item_desc", ([ ]) );
	set( "no_clean_up", 0 );
	setup();

	}
