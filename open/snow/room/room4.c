#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "雪苍山山腰");
  set ("long", @LONG
这里是雪苍山的山腰，远远往上望去，紫云宝殿就在不远的地方□听说山上的雪苍派是武者工会的所在地，在此常常可以看到来来往往
的武者及想成为武者的人们。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room5_out",
  "down" : __DIR__"room3",
  "west" : __DIR__"go7",
]));

   set("light_up",1);

  setup();
}
void init()
{
}
int do_search()
{
	if(this_player()->query("family/family_name")!="雪苍派")
		return 0;
	this_player()->set_temp("have_search_8",1);
	tell_object(this_player(),"你在此寻找，发现一个暗门(key)。\n");
	return 1;
}
int do_push(string str)
{
	if(str!="key") return notify_fail("你想推什么 ?\n");
	if(this_player()->query_temp("have_search_8")!=1)
		return notify_fail("你找不到八卦阵的暗门。\n");
	this_player()->delete_temp("have_search_8");
	tell_object(this_player(),"只听见「喀”的一声，出现一条密道，你从密道通到八卦阵的出口。\n");
	this_player()->move(__DIR__"room5_out");
	return 1;
}
