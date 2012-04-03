#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "森林");
  set ("long", @LONG
这里一望无际的森林，东边黑压压的一片密林，看来是人烟稀少
的地方，这里有一株相当高大的榕树，看起来似乎年代已经相当久远
了，应该是颗年余百岁的老树了，这里的土地似乎相当的松软，应该
蛮好挖(dig)的...
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"f3",
  "south" : __DIR__"f6",
  "north" : __DIR__"f2",
  "east" : __DIR__"F4",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/squirt" : 1,
]));

  setup();
}
void init()
{
    add_action("do_dig","dig");
}
int do_dig(string arg)
{
    object me=this_player();
    object ob=new("/open/doctor/obj/root");

    if(me->query_temp("sos_tor")==1 && !me->query_temp("get_root") && arg == "土地")
{
	write("你把这松软的泥土给挖开，并摘取了几条榕树根...\n"NOR);
	ob->move(me);
	me->set_temp("get_root",1);
	return 1;
}
    else
{
	write("你挖ㄚ挖的，老半天也没挖到啥东西！\n"NOR);
	return 1;
  }
}