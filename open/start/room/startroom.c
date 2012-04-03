// Room: /open/start/startroom.c
// 本房间 rewrited by wade in 1/2/1996 for chfn 任务

#include "/open/open.h"
inherit ROOM;

string do_search();

void create ()
{
  set ("long", @LONG
这是你的家, 相传你祖宗十八代都在这儿生活, 祖先们的坟墓也都
就近葬在附近的山丘地上, 村长还劝人到那边耕种, 你的老祖先们似乎
在那附近种了不少地, 不过到了你这代, 已经没人愿意去种田了, 一来
是因为时局纷乱, 一来是据说有一代祖先找到了不少珍奇异宝, 附近居
民也趋之若骛, 你老爸更在你十四岁那年把你踢出去冒险, 为的就是希
望你能学得一身武功, 带回一堆宝物.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/start/room/s1",
]));
  set("objects", ([
	START_NPC"papa"		: 1,
  ]) );

  set("light_up", 1);
  set("no_clean_up", 1);
  set("valid_startroom", 1);

  setup();
}

string short()
{
  object	me=this_player();

  return sprintf ("%s的家", me->name());
}
