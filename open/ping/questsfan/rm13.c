// Room: /u/d/dhk/questsfan/rm13
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", ""HIC+BLINK"分别天地"NOR"");
  set ("long", "
此地是松山的最高处，站立于此自有一股清新脱俗，超然自得
之感，而且人立至高致极，一瞰江河之广阔，万兽奔驰大地的那种
快感真是舒坦呀！所以此地有一雅称，曰：分别天地。其意在于，
好像你以一介平民确用以超然之力将天与地狂妄的分开，而身置其
中，上不及天、下不及地的孤寂。似在嘲笑天地的无能，唯我独尊
的感觉。
  ～～～"HIR"哈哈哈"NOR"～～～"HIY"啊！哈哈哈哈！！！"NOR"～～～"HIR"哈哈哈"NOR"～～～

");

  set("exits", ([ /* sizeof() == 3 */
  "southdown" : __DIR__"rm19",
  "westdown" : __DIR__"rm14",
  "eastdown" : __DIR__"rm12",
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
  int linpo=(int)(who->query_skill("linpo-steps",1));
  int move=(int)(who->query_skill("move",1));
  int dodge=(int)(who->query_skill("dodge",1));
  int exp=(int)(who->query("combat_exp")); 
  object mime=new("/open/ping/questsfan/npc/mime.c");  if(who->query_temp("run_over")!=1 && who->query_temp("run")==7)
  {
   if(linpo>=100 && move>=70 && dodge>= 70 && exp>=2000000)
   {
   tell_object(who,""HIR"忽然间他停下来了。"NOR"\n");
if(!present("mime duan",environment(who)))
{
   mime->move(__DIR__"rm13.c");
}
   tell_object(who,"段霾说道:阁下对我紧追不舍，是为何故呢。"NOR"\n");
   who->set_temp("run_over",1); 
   who->set_temp("run",0);   }
else
{
   tell_object(who,"\n"WHT"这道黑色的人影又快速往东边山下离去，还边说:你的修为还不足以追上我。"NOR"\n");
tell_object(who,""WHT"哈哈哈!!!"NOR"\n");
   who->set_temp("run",8);
}
   remove_call_out("dhk");
  }
}

