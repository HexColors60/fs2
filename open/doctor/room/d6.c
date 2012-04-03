// room ://open/doctor/room/d6.c made by adam

inherit ROOM;

void create ()
{
  set ("short", "诊疗室");
  set ("long", @LONG
走到这里，看到许多病人病厌厌地坐在椅子上，医生们
走来走去，只见原本病厌厌的病人，一下子就生龙活虎起来，
银针医术天下第一，果然名不虚传。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"d5",
  "south" : __DIR__"d9",
//  "north" : __DIR__"doctor_room",
  "east" : __DIR__"d7",
]));
  set("light_up", 1);
  

  setup();
}
