#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIC"狂想空间小秘技天地"NOR);
  set ("long","这房间是介绍一些狂想的在玩时的一些小秘技!!
  提供给新玩家参考之用!!!
  秘技五：指令简化
  狂想空间的系统会自动搜寻最有可能的指令....
  如你打surrender(投降的指令)..要打全名打完时也许就被打死了...
  所以你可以只打surr 系统会自动帮你执行surrender的指令!!!!

  另外还有许多练功的秘技...及增加属性的秘技..及谜..
  那要玩家自己去发掘!!!!!
\n");
  set("exits", ([
  "north" : __DIR__"newhand4-1",
  "south" : __DIR__"newhand",
               ]));
  set("light_up", 1);
  setup();
}

