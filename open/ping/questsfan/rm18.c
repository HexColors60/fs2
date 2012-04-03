// Room: /u/d/dhk/questsfan/rm10
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", ""HIY"日日"HIG"甘霖"NOR"");
  set ("long", @LONG
这儿是一座树种繁杂，高大的树林。但是这座树林最大的特色
确是没有一刻停止的小雨，所以这座树林的别称就叫＂日日甘霖″
。传说这儿日日不停的雨是因为雨神有一次在此地休息，因为太热
所以让此地下一场小雨，但是他休息完却匆匆离去，竟没有让这场
雨停止。所以从此这里的雨便没停过。

LONG);

  set("exits", ([ /* sizeof() == 5 */
  "westup" : __DIR__"rm19",
  "east" : __DIR__"rm11",
  "southdown" : __DIR__"rm10",
  "westdown" : __DIR__"rm17",
  "northup" : __DIR__"rm12",
]));
  set("outdoors", "/u/d");

  setup();
}
void init()
{
    call_out("dhk",1,this_player());
}
void dhk(object who)
{
  if(who->query_temp("run")!=3 && who->query_temp("run")==2)
  {
   tell_object(who,""WHT"这道黑色的人影又快速往西边山下离去，身形虽快却似曾相识。"NOR"\n");
   who->set_temp("run",3);
   remove_call_out("dhk");
  }
}

