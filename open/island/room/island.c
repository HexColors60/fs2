inherit ROOM;

void create()
{  
   
   set("short","神仙港渡口");
   set ("long", @LONG
在你眼前的是一望无际的沙滩，深蓝色天空横过
一道七彩的虹，四周的景色均是中原所难见到，地上
尽是奇花异草，在白色的莹莹沙粒中显得格外的艳丽
芬芳．                     
LONG);
   set("light_up", 1);
        set_heart_beat(1);
 set("exits", ([ /* sizeof() == 4 */
  
    "east" : "/open/island/room/i1",
  "southeast" : "/open/island/room/i5",
]));
   set("outdoors", "/open/main");

 setup();
}
 init()
{
       add_action("board_ship","board");
        do_start_ship();

}
void do_start_ship()
{
        object ob1;
        if(!find_object("boat man"))
        {
        ob1=new("/open/island/npc/bman1");
         ob1->move("/open/island/room/boat1");
        destruct(ob1);
        }
} 
int board_ship(string str)
{
object ob;
        if(!str)
        return notify_fail("你要搭什么?\n");
        if(!objectp(ob=present(str,environment(this_player()))))
        return notify_fail("看清楚点 , 有那种船吗 ?\n");
        if(str=="boat") 
        {
        message_vision("$N走到岸边 , 跳上了小船 !\n",this_player());
        this_player()->move("/open/island/room/boat1");
        return 1;
        }

return 0;
}



