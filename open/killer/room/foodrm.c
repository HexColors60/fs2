#include </open/open.h>
inherit ROOM;
void create ()
{
  set ("short", "杀手餐厅");
	set( "build", 65 );
  set ("long", @LONG
    这里是杀手们练习后，用餐的好地方。四周已经有不少人在吃饭了。
由他们愉悦的神情与狼吞虎咽的样子，看来这里的食物还蛮好吃的。
墙上贴着一份价目表(table)我想你还是先看看的好。
看完之后，想吃什么可以用(forder)叫餐
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/killer/island/npc/luton.c" : 1,
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "table" : "如果想叫餐，请用forder XXXX决定既可，老板会尽快服务的。

             A : 阳春面          30  coins

             B : 香肉炉          70  coins

             C : 温州大馄饨     100  coins

             D : 海陆大餐     150  coins

            ",
]));
  set("search_desc", ([ /* sizeof() == 1 */
  "table" : "干嘛！多看两眼也不会比较便宜呀！
",
]));
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"leerm",
  "west" : __DIR__"r18",
  "east" : __DIR__"sr0",
]));
  set("light", 10);

  setup();
}
void init()
{
	add_action("do_order","forder");
}
int do_order(string str)
{
 object me;

        me=this_player();
	if( str == "" )
	  return notify_fail("喂。。你想叫什么东西呀？\n");
        switch(str)
        {
         case "A":
         {
          if ((int)me->query("food") >= (int)me->max_food_capacity())
          {
            tell_object(me,"你想撑死吗？会饿才来吧！.......\n");
            return 1;
          }
          if(!me->can_afford(30))
          {
           tell_object(me,"想吃霸王餐吗？带点钱来吧。\n");
           return 0;
          }
          me->add("food",40);
          me->add("water",50);
          me->pay_money(30);
          tell_object(me,"一碗热腾腾的阳春面端了上来，令你吃的不亦乐乎。\n");
          return 1;
         }
         case "B":
         {
          if ((int)me->query("food") >= (int)me->max_food_capacity())
          {
            tell_object(me,"你想撑死吗？会饿才来吧！.......\n");
            return 1;
          }
          if(!me->can_afford(70))
          {
           tell_object(me,"想吃霸王餐吗？带点钱来吧。\n");
           return 0;
          }
          me->add("food",90);
          me->add("water",50);
          me->pay_money(70);
          tell_object(me,"一炉热腾腾的香肉端了上来，令你吃的不亦乐乎。\n");
          return 1;
         }
         case "C":
         {
          if ((int)me->query("food") >= (int)me->max_food_capacity())
          {
            tell_object(me,"你想撑死吗？会饿才来吧！.......\n");
            return 1;
          }
          if(!me->can_afford(100))
          {
           tell_object(me,"想吃霸王餐吗？带点钱来吧。\n");
           return 0;
          }
          me->add("food",100);
          me->add("water",110);
          me->pay_money(100);
          tell_object(me,"一碗热腾腾的温州大馄饨端了上来，令你吃的不亦乐乎。\n");
          return 1;
         }
         case "D":
         {
          if ((int)me->query("food") >= (int)me->max_food_capacity())
          {
            tell_object(me,"你想撑死吗？会饿才来吧！.......\n");
            return 1;
          }
          if(!me->can_afford(150))
          {
           tell_object(me,"想吃霸王餐吗？带点钱来吧。\n");
           return 0;
          }
          me->add("food",150);
          me->add("water",150);
          me->pay_money(150);
          tell_object(me,"一整套的海陆大餐端了上来，令你吃的不亦乐乎。\n");
          return 1;
         }
        }
       return notify_fail("喂。。你想叫什么东西呀？\n");
}


