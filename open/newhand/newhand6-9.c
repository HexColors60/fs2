#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIY"狂想空间历史发展馆"NOR);
  set( "long", "后来不知什么原因,狂想空间便停止了发展的脚步,那时我正在玩狂想空间
,同时在南部的狂想空间分站,一开始在架设时遭遇了很多的问题,如时间不会走
,Perform不能用..等,还好有大神Acelan及Konn的帮忙,他们都是之前在狂想空间
的巫师群中的高手,才使Anmy在南站的狂想空间能正常运作,同时间找到了Wataru
大大加入,使在狂想空间的杀手系统可以全部移植到南站来使用,在同时LEEI大大
也加入,使南站的巫师群实力更是大大的提升!!!!
" );
  set("exits", ([
  "north" : __DIR__"newhand6-8",
  "south" : __DIR__"newhand6-10",
               ]));
  set("light_up", 1);
  setup();
}

