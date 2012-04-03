//written by acelan...../u/a/acelan/room/wood15.c

inherit ROOM;

void create()
{
        set("short", "小径的尽头");
        set("long", @LONG
咦! 小径到此来到了尽头, 在一片空地中有一棵参天古木(tree),
四周横生了许多的枝丫与周围的树叶连成一片, 密不透风, 仿佛太阳在
一瞬之间下山了。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "south" : "/open/killer/mon/room/wood11.c",
   ]));

   set("item_desc", ([
       "tree" : "你仔细的看过这棵古木之后, 发现它是空心的, 而且在隐密处\n还有个门(door)\n",
   ]));

        set("no_clean_up", 0);

        setup();
}

void init()
{
   add_action("do_search", "search");
}

int do_search( string str)
{
   object me;
   me= this_player();
   if( str== "door")
   {
      tell_object( me, "果然, 在打开门后你发现了古木之中有一条向上的楼梯。\n");
      set("exits/up", "/open/killer/mon/room/wood22.c");
      return 1;
   }
   return notify_fail("什么..你在找小度的小裤裤...\n");
}

int valid_leave(object me, string dir)
{
  if (dir != "up")
  {
     this_object()->delete("exits/up");
     return 1;
  }
  return 1;
}
