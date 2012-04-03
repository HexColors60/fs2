#include <room.h>
#include <ansi.h>
inherit ROOM;
 int done,done1,done2;
void create ()
{
    seteuid(getuid()); 
  set ("short",HIC"封印地"NOR);
  set ("long", @LONG
在通过密道之后，你眼前出现三座大雕像，地上满满的剑痕，隐约可
感觉到一股刚硬之气；除了三座雕像(statue)之外，还有一个极大的石门，门
上贴了数道古符….似乎在封印着极不祥的东西，门边有一石碑(stone)，
石碑上好似刻有东西…。

LONG);

 set("item_desc", ([ /* sizeof() == 2*/
  "stone" :"逍遥子封印天魔于此！\n",
  "statue" : "三座古雕像，其中包括了一位剑客(sworder)、刀客(blader)及书生(scholar)..，不过雕像上似乎都有个痕迹….不知是做什么用的…\n"]));
 set("exits", ([ /* sizeof() == 1 */
  "back":"/open/common/room/inn.c",
 ]));
 set("no_auc", 1);
 set("no_transmit", 1);
setup();
}
void init()
{
 add_action("do_search","search");
 add_action("do_enter","put");
}

int do_search(string str)
{
  object ob,ob1;

  ob=this_player();
  if( str != "statue" )
  return notify_fail("你完全寻找不出任何异状!!!\n");
  else
  message_vision("经过你明察暗访，发现每个雕像都有武器形的凹洞。\n",ob);
  return 1;
}

int do_enter(string str)
{
 mapping weapons = ([
  "sun_fire_sword in sworder" : 1,
  "liyu_pen in scholar" : 2,
  "bird_blade in blader" :3,
 ]);
 object ob=this_player();
 string stones,name,str1;
 if(ob->query("highsworder")==1)
  return notify_fail("你已开过封印了！！\n");
 if((weapons[str]==1)&& (ob->query("class")=="swordsman"))
  {
  ob->set_temp("qsword",1);
    if( done== 0 )
      {
      message_vision(HIW"你把灵器推入雕像，顿时雕像嘎嘎作响！\n"NOR,ob);
      message_vision(HIW"顿时，由凹洞处产生一个漩涡形的气漩,一个不小心$N以被极大的吸力将吸入…空洞内…。\n\n\n"NOR,ob);
      ob->move("/open/gsword/second/room/sword/s1.c");
      message_vision(HIW"$N被吸入后…气漩马上消失无踪…。\n"NOR,ob);
      }
   else
    message_vision("雕像毫无反应...\n",ob);
   done = 1;
  return 1;
  }
 if((weapons[str]==2) && (ob->query("class")=="scholar"))
 {
  ob->set_temp("qsword",1);
   if( done1== 0 )
      {
       message_vision(HIW"你把灵器推入雕像，顿时雕像嘎嘎作响！\n"NOR,ob);
       message_vision(HIW"顿时，由凹洞处产生一个漩涡形的气漩,一个不小心$N以被极大的吸力将吸入…空洞内…。\n\n\n"NOR,ob);
       ob->move("/open/gsword/second/room/sch/sc1.c");
       message_vision(HIW"$N被吸入后…气漩马上消失无踪…。\n"NOR,ob);
      }
    else
    message_vision("雕像毫无反应...\n",ob);
   done1=1;
  return 1;
  }
 if((weapons[str]==3) && (ob->query("class")=="blademan"))
  {
  ob->set_temp("qsword",1);
  if( done2== 0 )
      {
       message_vision(HIW"你把灵器推入雕像，顿时雕像嘎嘎作响！\n"NOR,ob);
       message_vision(HIW"顿时，由凹洞处产生一个漩涡形的气漩,一个不小心$N以被极大的吸力将吸入…空洞内…。\n\n\n"NOR,ob);
       ob->move("/open/gsword/second/room/blade/b1.c");
       message_vision(HIW"$N被吸入后…气漩马上消失无踪…。\n"NOR,ob);
      }
     else
    message_vision("雕像毫无反应...\n",ob);
   done2=1;
  return 1;
  }
 else
 {
  message_vision(HIR"误触机关…..遭封印反噬！\n"NOR,ob);
  ob->unconcious();
 }
return 1;
}
