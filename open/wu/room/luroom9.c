// Room: /open/wu/room/luroom9.c
// 泷山武馆的练武场
inherit ROOM;
string search();
void create ()
{
  set ("short", "练武场");
  set ("long", @LONG
这里是泷山派练武场地的中庭,一条由花岗石所铺成的道路向泷山派的
大厅而去,西边直行的话是通往泷山派的大门,你忽然发觉花岗石上有
许多的脚痕,看来在此练武的弟子其武学程度以经到达炉火纯青的地步
了。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"luroom8",
  "west" : __DIR__"luroom6",
  "south" : __DIR__"luroom10",
  "east" : __DIR__"luroom17",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/npc/e_trainee" : 2,
]));

 set("search_desc", ([ /* sizeof() == 1 */
  "花岗石" : (: search :),
]));
  setup();
}
string search()
{
if (this_player()->query_temp("shaswordtime")==1)
{
   message_vision("$N在花岗石中找来找去 , 摸出了一颗火法珠并收进口带中 \n",this_player() );
   this_player()->set_temp("quests/findball2",1);
   new("/open/gsword/obj1/fireball")->move(this_player());
   return "";
  }
        message_vision("$N在这翻来覆去 , 结果什么也没发现 \n",this_player());
        return "";
}
