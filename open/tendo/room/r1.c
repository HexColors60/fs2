// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short",HIY"八卦游龙迷阵"NOR);

long = "\n"+
"                         "+BCYN"                      \n"NOR+
"                       "+BYEL"                      "+BCYN"    \n"NOR+
"                     "+BYEL"                          "+BCYN"    \n"NOR+
"                    "+BYEL"                            "+BCYN"    \n"NOR+
"                   "+BYEL"                              "+BCYN"    \n"NOR+
"                  "+BYEL"             "+HIY"六断"+HIW"(n)"+"            "+BCYN"   \n"NOR+
"                  "+BYEL"            "+HIY" ＿＿＿"+"             "+BCYN"   \n"NOR+
"                  "+BYEL"     "+HIY"中虚"+HIW"(w)"+HIY" ＿＿＿"+" 中满"HIW"(e)"
+"     "+BCYN"   \n"NOR+
"                  "+BYEL"            "+HIY" ＿＿＿"+"             "+BCYN"   \n"NOR+
"                  "+BYEL"                                "+BCYN"   \n"NOR+
"                  "+BYEL"             "+HIY"三连"+HIW"(s)"+"            "+BCYN"   \n"NOR+
"                   "+BYEL"                              "+BCYN"   \n"NOR+
"                    "+BYEL"                            "+BCYN"   \n"NOR+
"                     "+BYEL"                          "+BCYN"   \n"NOR+
"                       "+BYEL"                      \n"NOR+
"\n";

set("long", long);
set("exits", ([
      "east"  : __DIR__"r0",
      "west"  : __DIR__"r0",
      "south" : __DIR__"r2",
       "north" : __DIR__"r0",
  ]));
  set("light_up", 1);
  set("no_fanset",1);
  set("no_magic", 1);
  set("no_fight", 1);
  set("no_clean_up", 1);
  setup();
}
void init()
{
        add_action("no_fanset","fanset");
}

int no_fanset()
{
        object who;
        who = this_player();
        tell_object(who,"由于此处磁场过强，你的唤云扇无法设定。\n");

        return 1;
}
