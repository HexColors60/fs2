// Room: /u/d/dhk/questsfan/room9
inherit ROOM;

void create ()
{
  set ("short", "哨站小屋");
  set ("long", @LONG
这是一间很普通的木制房屋，但是四周摆放的家具，
令你认为这里并不像是一间住家。放眼四周只有四名壮汉
在此煮酒聊天，但是他们的一举一动再再显示他们并非普
通人，难道…
LONG);

  set("outdoors", "/u/d");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wooder.c" : 1,
  __DIR__"npc/hunter.c" : 1,
  __DIR__"npc/farmer.c" : 1,
]));
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"qroom/room5",
]));

  setup();
}
