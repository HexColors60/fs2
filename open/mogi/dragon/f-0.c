//by Casey
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
  seteuid(getuid());   
        set("short",MAG"地底牢笼"NOR);
        set("long", @LONG
你来到一间漆黑无比的房间，空气中全是弥漫着腐尸和脓血的味道
一不留神被地上的东西所拌倒，你点起火把一看却倒抽了好几口寒气
原来竟是一对龙爪，但它看起来一动也不动，不知道其死活...
LONG
        );       
  set("light_up", 1);
 set("evil", 1);
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"f-5",
 "east" : __DIR__"f-1",
 "west" : __DIR__"f-6",

]));
  set("no_transmit",1);
  set("no_auc",1);
 set("objects", ([ /* sizeof() == 1 */
  "/open/mogi/dragon/obj/dragon-1" : 1,
]));
  
  setup();
}
void init()
{
 add_action("free_dragon","free");
}

int free_dragon(string str)
{
  object ob,ob1;
  ob=this_player();
  if(!present("dragon",environment(ob)))
    return notify_fail("什么东西都没有，你想做什么。\n");
  if( str!="dragon")
    return notify_fail("你要释放啥呀。\n");
  if( ob->query("force") > 1500)
 {
  message_vision(HIW"$N运起全身内劲震碎"HIB"玄铁锁铐\n"NOR,ob);
ob->set("kill_dragon",1);
  write("\n");
     ob1=present("dragon",this_object());
  destruct(ob1);
  call_out("msg1",3,ob);
  return 1;
  }
  else
  {
   message_vision(HIW"$N运起内劲想要震碎"HIB"玄铁锁铐"HIW"，由于内力
不足反而被锁铐震伤!!\n"NOR,ob);
   ob->add("kee",-150);
   return 0;
  }
}
int msg1(object ob)
{
 message_vision("\n",ob);
 message_vision(HIM"\n只见黄金甲龙鳞片鼓张 ,早已死绝的眼神突然间爆射出精光\n"NOR,ob);
  call_out("msg2",3,ob);
  return 1;
}
int msg2(object ob)
{
  object ob1;
  message_vision(HIY"\n黄金甲龙狂吼了一声 ,缓缓的立起庞大的身躯\n"NOR,ob);
 
  
  ob1=new("/open/mogi/dragon/npc/dragon-gold");
  ob1->move("/open/mogi/dragon/f-0");
  ob1->set("kill_dragon",1);
  message("mud",HIB"\n\n  大地剧烈震动 ,海水翻腾不已 ,天劫来临了 ...\n\n\n\n"NOR,users());
  call_out("msg3",3,ob);
  return 1;
}
int msg3(object ob)
{
 message("mud",HIR"    自遥远"CYN"魔界"HIR"传来的阵阵惊人吼声 ,人们开始慌乱...\n
          地上的鸟兽到处流窜 ,世界当真已走到尽头了?!\n\n\n"NOR,users());
  call_out("msg4",3,ob);
  return 1;
 }
int msg4(object ob)
{
message("mud",HIW"\n  地上颳起了一阵阵的"+HIB+"狂风"+HIW+" ,空中一道道"+HIB+"电光"+HIW+"交加不息...\n
  家园被洪水冲走的人们正默默的祈导着 ,远赴魔界的"+HIY+"勇者"+HIW+"呀...\n"NOR,users());
  return 1;
}



