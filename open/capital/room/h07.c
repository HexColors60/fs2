// Room: /open/capital/room/h07.c

inherit ROOM;

void create ()
{
  set ("short", "扁鹊胡同");
  set ("long", @LONG
这里的街道依然干净, 唯一不同的是路旁群聚着一群人, 原来是有
人在一旁说书, 听他口中滔滔不绝, 似乎是在回顾以前的历史, 一代兴
起, 一朝衰弱, 当然围观的民众是听的兴趣盎然。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/capital/room/h06",
  "east" : "/open/capital/room/h08",
]));

  set("outdoors", "/open/capital");


  setup();
}
