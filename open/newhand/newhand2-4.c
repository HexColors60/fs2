#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIW"狂想空间新手入门"NOR);
  set ("long","当你选定要加入的门派(guild)之后,且看完 help 帮派简介 之后再来就是前往
  你所选定的门派加入公会,拜师学艺.....展开大侠的心路历程!!!!!!!
  目前来说有些门派并没有完全完成所以不建议加入,以免以后后悔!!!!
  2.完成的门派但不是很完整：
    【 舞  者 】    夜梦小筑        门派首领：月牙儿    (有属性限制)
    【朝廷命官】    朝庭命官        门派首领：陈知衡    (提供二次转派的门派)
    【 魔教徒 】    魔教            门派首领：庄静柔
    【 方  士 】    天道            门派首领：陆清风
    \n");
  set("exits", ([
  "west" : __DIR__"newhand2-3",
  "east" : __DIR__"newhand2-5",
               ]));
  set("light_up", 1);
  setup();
}

