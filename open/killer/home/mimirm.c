#include <room.h>

inherit ROOM;

void create()
{
           set("short","密室");
         set("long",@LONG
这里到底是哪里呢？黑暗的让人难以看清四周，不禁起了一阵鸡皮疙瘩。
不过，隐隐约约之中似乎看到有人在那里。不知道是不是自己眼花了？
来时的密道已经封闭，四周似乎没有出路，但往上似乎还有通道耶。。。。。
一旁的碑石刻着：
      「再回首,已是百年身”
 
LONG);
        set("exits", ([
          "up":__DIR__"rbd",
        ]) );
        set("objects",([
          "/open/killer/npc/doctor.c":1,]));
        setup();
}

void init()
{
      add_action("do_look","look");
      add_action("do_write","write");
}
int do_look(string str)
{
      if(str!="碑石") return 0;
      tell_object(this_player(),"碑石上还有一行空行(table)。\n");
       return 1;
}
int do_write(string str)
{
  object me;

  me=this_player();
  if( str != "一失足,成千古恨 on table" )   return 0;
  tell_object(me,"你用匕首在空行刻下‘一失足,成千古恨。’\n");
  tell_object(this_player(),"突然出现了陷阱，你掉入陷阱中。。\n");
  me->move(__DIR__"boxrm.c");
  return 1;
}