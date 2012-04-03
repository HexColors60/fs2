inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "沙滩");
  set ("long", @LONG
遍地的白沙, 除了一棵枯树与一块大岩之外, 并没有其他事物. 你虽觉得枯
树与岩石的感觉十分怪异, 但是经过仔细的寻找并没有找到什么奇怪的地方. 此
地除了东边是海之外, 其他方向放眼望去都是白蔼蔼的沙滩, 在西北方能见到一
座高耸的岩壁.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"is7.c",
  "north" : __DIR__"is13.c",
  "south" : __DIR__"is5",
]));
  set("outdoors", "/u/u");

  setup();
}
void init()
{
add_action("do_closebox", "close");
add_action("do_search", "search");
add_action("do_look", "look");
add_action("do_get", "get");
add_action("do_put", "put");
}
int do_search()
{
object me=this_player();
if (me->query_temp("can_search")==1)
{
tell_object(me,HIC"你赫然发现岩石的树旁可以看到因退潮而呈现的沙岸上有一块扁平的大岩石(stone).\n"NOR);
tell_object(me,HIY"原来黎明时是这座岛退潮的时间 .\n"NOR);
new(__DIR__"obj/stone.c")->move(environment(me));
me->delete_temp("can_search");
me->set_temp("can_back",1);
return 1;
}
else
{
return 0;
}
}
int do_look(string arg)
{
object me,ob;
me=this_player();
   if( !arg )
       return 0;
   if(arg!="box")
       return 0;
   if(me->query_temp("openbox")!=1)
       return 0;
else
{
tell_object(me,"里面有:\n");
tell_object(me,HIW"      一万粒钻石"NOR"(Diamond)\n"NOR);
tell_object(me,HIB"      忍术秘笈"NOR"(Ninja book)\n"NOR);
return 1;
}
}
int do_get(string arg)
{
object me,ob;
me=this_player();
   if(me->query_temp("openbox")!=1)
       return 0;
   if( !arg )
       return 0;
   if(me->query_temp("can_close")==1)
       return 0;
   if(me->query_temp("care")==1)
{
tell_object(me,"你决定伸手拿取宝物,但是宝物一碰到你的手就变成烟雾消失了!!\n");
me->set_temp("care",2);
ob=present("box",this_object());
destruct(ob);
me->delete_temp("openbox");
return 1;
}
   if(arg=="all from box")
{tell_object(me,"你的良心呼吁你不要贪小便宜!!\n");me->set_temp("care",1);return 1;}
   if(arg!="daemond from box")
{tell_object(me,"你的良心呼吁你不要贪小便宜!!\n");me->set_temp("care",1);return 1;}
   if(arg!="book from box")
{tell_object(me,"你的良心呼吁你不要贪小便宜!!\n");me->set_temp("care",1);return 1;}
else
{
return 0;
}
}
int do_put(string arg)
{
object me,ob;
me=this_player();
   if( !arg )
       return 0;
   if(me->query_temp("openbox")!=1)
       return 0;
   if(arg!="card in box")
       return 0;
   if(me->query_temp("care")==2)
       return 0;
   if(me->query_temp("can_close")==1)
       return 0;
else
{
tell_object(me,"你将令牌放进金属箱里, 应该顺手将盒子盖\上(close)会比较好!!\n");
me->set_temp("can_close",1);
ob=present("card",me);
destruct(ob);
return 1;
}
}
int do_closebox(string arg)
{
object me,ob;
me=this_player();
   if( !arg )
       return 0;
   if(me->query_temp("openbox")!=1)
       return 0;
   if(arg!="box")
       return 0;
   if(me->query_temp("can_close")!=1)
       return 0;
else
{
tell_object(me,HIW"你将盒子盖\上!!\n");
tell_object(me,HIM"突然间强烈的紫光从盒子射出!!\n");
tell_object(me,HIW"强光过后只见盒子已经消失, 只留下一把生锈的铁匕首在地上!!\n");
new(__DIR__"obj/old_dag.c")->move(environment(me));
me->delete_temp("can_close");
ob=present("box",environment(me));
destruct(ob);
me->delete_temp("openbox");
if (me->query_temp("care")!=1) {me->set_temp("complete",1);return 1;}
return 1;
}
}

