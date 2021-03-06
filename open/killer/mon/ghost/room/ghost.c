//written by acelan...../u/a/acelan/ghost/room/ghost12.c

inherit ROOM;

void create()
{
        object me;
        me= this_player();
        set("short", me->query("name")+"之墓");
        set("long", @LONG
什么....这里竟是我的坟墓, 再仔细看看墓碑(gravestone), 上
面果然是写着「"+me->query("name")+"之墓”, 看得你吓出了一身冷汗, 只听见坟墓
内传来阵阵的哭声。哇....妈呀....还不快走。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"ghost19.c",
       "south" : __DIR__"ghost6.c",
       "east"  : __DIR__"ghost13.c",
   ]));
   set("item_desc", ([ /* sizeof() == 1 */
       "gravestone" : "上面写着几个大字「"+me->query("name")+"之墓”\n",
   ]));
   set("search_desc", ([ /* sizeof() == 1 */
       "gravestone" : "你仔细看过自己的墓碑后发现, 它的底部有摩擦过的痕迹, 看来似乎是可以推(pull)的。\n",
   ]));
   set("no_clean_up", 0);

   setup();
}

void init()
{
   add_action("do_pull", "pull");
}

int do_pull( string arg)
{
   object me;
   me= this_player();
   if( arg != "gravestone")
   {
      mission_vision("你要推什么.........\n", me);
      return 0;
   }
   mission_vision("你使劲的将你的墓碑推开后, 赫然发现在墓碑之后竟然还有个通道。\n", me);
   set("exits/west", __DIR__"ghost11.c");
}

int valid_leave(object me, string dir)
{
   if (dir != "west")
   {
      this_object()->delete("exits/down");
      return 1;
   }
   return 0;
}
