inherit ROOM;
void create()
{
  set ("short", "走廊");
  set ("long", @LONG
由于杀手们长年追杀他人，导致仇家不少，总坛自然成了最佳的避风港。
为了方便长期躲藏，属于杀手的休息处与吃饭的地方可少不了。
东方是杀手们吃饭的大餐厅与宿舍。没事不要大声喧哗哦。
LONG);
   set("exits", ([
   "east"   : __DIR__"foodrm.c",
   "west"   : __DIR__"floorm.c",
   "north"  : __DIR__"shoprm.c",
  ]));
   set("no_fight", 1);
  set("no_magic", 1);
  set("no_transmit", 2);
  set("light_up", 1);
  setup();
} 
