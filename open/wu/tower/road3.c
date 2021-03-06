// Room: /u/p/pokai/room/wu/road3.c
inherit ROOM;

void create()
{
  set ("short", "武威七杀塔入口");
  set ("long", @LONG
    这儿是传说中的「武威七杀塔”，你仰头算了算，塔高正好七层，塔身漆着像
血渍般的暗红色，给人一种不寒而栗的感觉。  据说只有真正的武者，才够资格进
入这个塔，但也只有最强的武者，才有机会平安的走出这个塔，并且取得武者的证
明。  你看到塔的门口站着表情肃然的老人。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"guardian" : 1,
])); 

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road2",
  "enter" : __DIR__"tower1-1",
]));
  set("outdoors", "u");
  set("no_fight",1);
  set("no_magic",1);
  set("no_smash",1);
  set("no_dest",1);

  setup();
}

/* void init() {
	add_action("do_kill","kill");
}

int do_kill(object me , string str){
  if(present("tower older",environment(me)) && str == "older") {
    tell_object(this_player(),"守塔老人推了你一把说：去！去！去！别来闹事！\n");
    me->move(__DIR__"road2");
    return 0;
  }
  return 1;
} 
*/

  int valid_leave(object me, string dir)
 {
        if(dir=="enter"&&present("tower older",environment(me))) {
  if (me->query("class")=="fighter")
  return 1;
  else  return notify_fail("守塔老人发觉你不是武者，阻止你进入。\n");
  }
  tell_object(this_player(),"守塔老人拍拍你肩膀，对你笑了笑。\n");
  return 1;  
}
