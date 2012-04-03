// Room: /open/dancer/room/roomse1.c :cgy

inherit ROOM;

void create ()
{
  set ("short", "花园小径");
  set ("long", @LONG
这是一条小径，两旁长满了各式的鲜花，令人目不暇给，
芬芳的花香令人流连忘返，美丽的鲜花令人不禁想近而亵玩焉
东边是喷水池而西边则是练舞场。


LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/dancer/room/rooms3.c",
  "east" : "/open/dancer/room/roomse2.c",
]));

  set("light_up", 0);

  setup();
}
