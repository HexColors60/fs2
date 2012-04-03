// Room: /u/m/moner/room/room26.c
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
  set ("short", "卧房");
  set ("long", @LONG

刚至此处，便有一股淡淡的细香，沁人心肺，向壁上望去，有唐伯虎画的
「海堂春睡图”，一旁卦着一把蓝狿刀，另一方着有宋太学士写的对联，案
上摆着一幅水晶镜，轻罗百蝶被上一丝凌乱，私忽有人刚睡过，东方萤珀石
屏风(screen)后，仿佛有黑影在摇动。

LONG);

  set("item_desc", ([ /* sizeof() == 2 */
"screen" : "由萤珀石所做成的屏风，光可照人。\n",
  "east" : (: look_door,     "east" :),
]));
  set("exits", ([ /* sizeof() == 2 */
"west":"/open/gblade/mroom/room17.c",
"east":__DIR__"r2.c",
]));
  set("objects", ([ /* sizeof() == 1 */
 "/daemon/class/blademan/npc/m1.c" :1,
]));
  set("light_up", 1);
  create_door("east", "萤珀石屏风","west",DOOR_CLOSED);
  setup();
}
int valid_leave(object me, string dir)
  {
if(dir=="east"&&(doors["east"]["status"]==DOOR_CLOSED) )
    return notify_fail("你必须先把萤珀石屏风打开！\n");
     if(dir=="east")
  {
          message_vision(HIW+"$N一踏入浴室，哇～～
美女入浴图ㄟ，在$N来不及反应时，美女一个旋身，一件浴袍轻轻的
披上身子，一柄篮色的兵刃架在$N的颈上。\n"+NOR,me);
    }
    return 1;
   }
