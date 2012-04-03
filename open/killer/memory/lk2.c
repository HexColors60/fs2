inherit ROOM;
void create()
{
set("short", "莫塔湖东北东");
set("long", @LONG
	在你眼前的是一大片深不可测的湖水，传说此湖水表面平静
	但是内部暗潮汹涌，就连泳技高超的高手也不敢轻易尝试
	这时你已经来到湖边了，藉着定水珠的功效，你并没有太大的困扰
	然而，这里真的会有那只大鱼吗？看来你得四处找找...........

LONG
);
set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lk1.c",
  "east" : __DIR__"lk3.c",
]));
setup();
}

void init()
{
  add_action("do_search", "search");
}

int do_search(string arg)
{
  object me=this_player();
  int max;

  if (arg)
  	return 0;
  if (me->query_temp("memory")  < 4 )
  {
    message_vision("$N哇勒....你是怎么来到这里的，作弊呀？？  可恶........。\n", me);
    message_vision("一瞬间一阵机关鸣动声............\n",me);
    max=me->query("kee");
    max= (int) (max/2);
    me->add("kee",-max);
    tell_object(me,"一阵冲撞力将你弹飞，落入陷阱之中一直坠落。。。。。\n");
    me->move("/open/killer/room/firstrm.c");
    return 0;
  }
   if (me->query_temp("find_fish")  == 5 )  //因为是要依序寻找所以用等于检查
  {
    message_vision("$N利用定水珠的力量，在水中仔细的寻找大鱼的身影。\n", me);
    message_vision("$N因为并没有拖延时间便追到这里，所以大鱼并没有逃远\n",me);
    message_vision("看来大鱼在劫难逃时，大鱼一个翻身击中$N，并往东南方逃去\n",me);
    me->set_temp("find_fish",6);
    return 1;
  }
   tell_object(me,"你在湖中，四处寻找，不过并没有看到什么东西，\n看来需要到其他地方找找\n");
   return 0;
 }
