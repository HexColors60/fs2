//weaponmap......  by dhk 2000.5.12
#include <ansi.h>
#include </open/open.h>

inherit BOOK;

#define BOOK_PATH "/open/ping/questsfan/obj/"
#define BOOK_NAME "weaponmap"
#define BOOK_NAME1 "weaponmap1"
#define C_BOOK_NAME ""HIC"飘阳扇武器设计图"NOR""

void create()
{
  seteuid(getuid());
  ::create();
  set_name( C_BOOK_NAME, ({ "weaponmap" }) );
  set( "long", "这是一张由前辈高手北胜天用尽心血所书写的飘阳扇设计图，你可以用(read)来观看。\n");
  set ( "value", ({ 10, "silver" }) );   //价值
  set ( "book_path", BOOK_PATH + BOOK_NAME );
  setup();
}
int do_read( string arg )
{
       object me = this_player();
       int level=(int)(me->query_skill("literate",1));
        if(me->query("family/family_name")=="段家" && level >= 120)
       {
       cat( sprintf("/open/ping/questsfan/obj/weaponmap1") );
       return 1;
       }
       else
       tell_object(me,"上面的文字写的太深奥，你根本看不懂。\n");
       return 1;
}

void init()
{
  add_action("do_make","make_sun_cloud_fan");
  add_action("do_read","read");
}
int do_make()
{
  object me = this_player();
  object fan=new("/data/autoload/scholar/finger_fan.c");
  string record,file;
  int sun=(int)(me->query_skill("sunforce",1));
  int force=(int)(me->query_skill("force",1));
if (!present("finger fan"))
{
  if ( me->query("family/family_name") =="段家" && sun >= 120 && force >=80 && me->query("combat_exp") >= 2000000 && present("hon diamond stone"))
  {
  tell_object(me,""HIY"你花了数个时辰，终于把飘阳扇造出来了。"NOR"\n");
  tell_object(me,""HIC"‘我一定要把飘阳扇给段云鉴赏一下﹝show_fan_to_duan﹞，嗯!!!一定要这么做’"NOR"\n");
  me->set("marks/fan-finger",1);
  fan->move(me);
  record=me->query("name")+"("+getuid(me)+")取得飘阳扇于"+ctime(time())+"!!!\n";
  file="/open/ping/questsfan/fan_record";
  CBIP_D->record(record,file);

  destruct(present("hon diamond stone"));
  destruct(present("weaponmap"));
  }
  else
    return notify_fail("你根本做不出来。\n");
}
else
  return notify_fail(""HIM"你打算造几把???????"NOR"\n");
  return 1;
}

