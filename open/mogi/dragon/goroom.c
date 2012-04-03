// Room: /u/p/poloer/dragon/goroom
inherit ROOM;

#include <ansi.h>
void create ()
{
  set ("short", "柳家宝库");
	set( "build", 56 );
  set ("long", @LONG
一间建筑在谷旁隐密的地方，四周都没有东西，只有一个破烂的灵位
上面隐约看到"柳..."似乎可以膜拜(pray)看看。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/status.c" : 1,
]));

  setup();
}
void init()

{
    add_action("do_pray","pray");
    add_action("search_here", "search");
    add_action("do_enter","enter");
    add_action("do_see","see");
}

int do_pray(string str){
   object me,obj;
   object key;
   string bluekey;
   me = this_player();
if(!str || str !="liu"){
                return notify_fail("你向谁膜拜？\n");
                           return 1;
                                 }
else{
message_vision(HIW"柳淳风说:哈!哈!我终于报仇了。谢谢了。\n"NOR,this_player());
message_vision(HIW"柳淳风说:为了报达你就送你三件礼物吧。\n"NOR,this_player());
message_vision(HIW"柳淳风说:老夫送你一程吧。\n"NOR,this_player());
  if( !me->query("mogi-pray-liu") ) {
   me->set("mogi-pray-liu",1);
        new(__DIR__"obj/sunblade")->move(this_player());
        new(__DIR__"obj/dragonar")->move(this_player());
        new(__DIR__"obj/hounghe")->move(this_player());
}
this_player()->move(__DIR__"enterroo");
        if (!key) key = present("bluekey", me);
        if (!key) key = present("bluekey", environment(me));
        if (!key) key = find_object( resolve_path(me->query("cwd"), bluekey) );
             if(key)
                  destruct(key);
     return 1;
}

           }

int search_here(string arg)

{
   if (this_player()->query_temp("find_tesin7")>=1)
tell_room(this_object(),"你找啊找的,发现墙有留字，可以探索(see). \n");
  else if(this_player()->query_temp("find_tesin8")>=1)
    {
    tell_room(this_object(),"找着找着...你忽然发现到一个密道..看样子你可以钻的进去(enter).\n");
    }
return 1;
}

int do_see(string str)
{
  if(!this_player()->query_temp("find_tesin7")) tell_room(this_object(),"你找了半天，可是看不出有任何特殊之处。\n");
  else 
  {
   tell_room(this_object(),"墙上写着..'剑师龙铁心到此一游'.\n");
   if (this_player()->query_temp("find_tesin7")==1)
   {
   this_player()->set_temp("find_tesin8",1);
   this_player()->delete_temp("find_tesin7");
   }
   else if (this_player()->query_temp("find_tesin7")==2)
   {
   this_player()->set_temp("find_tesin8",2);
this_player()->delete_temp("find_tesin7");
   }
   else if (this_player()->query_temp("find_tesin7")==3)
   {
   this_player()->set_temp("find_tesin8",3);
this_player()->delete_temp("find_tesin7");
   }
  }
}
int do_enter(string str)
{
if (!this_player()->query_temp("find_tesin8"))
   tell_room(this_player(),"你想去哪???\n");
else
{ 
   tell_room(this_player(),"你顺这密道..滑向未知的地方...\n");
   tell_room(this_player(),"你渐渐地看到眼前有光线出现...\n");
   this_player()->move("/open/gsword/room2/road1.c");
  this_player()->unconcious();
}
}

