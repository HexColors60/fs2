// Room: /open/capital/room/king/kr4-4-3.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "朝圣殿大殿");
  set ("long", @LONG
这里就是朝圣殿最重要的地方--朝圣大殿,皇帝正坐在龙椅上,你看到皇帝的
目光向你扫来,不禁打了一个寒颤,大殿的两旁有许多火把正燃烧着,大殿的后
方通往内殿,但内殿不是普通人可以随便进去的,树立的牌子(sign)写得非常
清楚明白!!
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kr4-4-2",
  "north" : __DIR__"kr4-4-4",
]));
        set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/ksoldier" : 3,
]));
  set("light_up", 1);

  setup();
}

int valid_leave(object who,string dir)
{
  if(dir && present("soldier",environment(who)))
  {
        if((who->query("class")=="officer" && who->query_temp("can_in")==1) || (who->query("class")=="taigan"))
        {
        return :: valid_leave(who,dir);
        }
        else
        {
  return notify_fail("皇城禁卫军说道:你想跑?!跑得掉吗?\n");
        }
  }
        return :: valid_leave(who,dir);
}
void init()
{
        add_action("do_exert","exert");
}
int do_exert(string str)
{
 object me;
 me=this_player();
 if(str=="roar"){
 message_vision(HIC"皇宫守卫大声的对你说:皇城禁地岂容你大声喧哗，还不快滚!!!\n"NOR,me);
 return 1;
                }
 else
 {
 return 0;
 }
}
