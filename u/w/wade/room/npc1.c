inherit ROOM;

void create ()
{
  set ("short", "基本的生物写作");
  set("long", @LONG_DESC
有一只很重要的范例的 npc, 请用 more 指令, 它的位置是在:
	/u/w/wade/npc/test.c
也就是说用 more /u/w/wade/npc/test.c 指令查看该档内容.
里头说了一大堆资料, 如果你有看没有懂, 请去巫师的房间:
	巫师程式设计心得讨论室
去读 post, 或者 post 问一下, 要是您有特殊心得, 
也请 post 出来与别人分享
//
// 请继续往东走...
LONG_DESC);

  setup();
}

void init()
{
  add_action("e", "e");
  add_action("e", "east");
  add_action("go", "go");
}

int e()
{
  this_player()->move(this_player()->query("startroom"));
  return 1;
}

int go(string str)
{
  if (str == "e" || str == "east")
    this_player()->move(this_player()->query("startroom"));
  return 1;
}
