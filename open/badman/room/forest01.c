// Room: /open/badman/room/forest01.c
// written by powell 96.4.26@FS

#include </open/open.h>

inherit ROOM;
string search_skeleton();

void create ()
{
  set ("short", "恶人森林");
  set ("long", @LONG
你走进了一大片森林之中，走着走着你才发现四周的景物似乎
一直都没变过，让你完全失去了方向。原来这里就是著名的恶人森
林，据说只有恶人谷的人知道如何顺利通过这片森林。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "树林" : "树林中有棵树特别其怪，好像常常受到摧残的样子；"+
           "你想不想也推(push)它一下啊？\n",
]));

  set("outdoors", "/open/badman");

  set("exits", ([ /* sizeof() == 4 */
  "west"  : __DIR__"forest01",
  "south" : __DIR__"forest01",
  "north" : __DIR__"forest01",
  "east"  : __DIR__"forest01",
]));

  set("search_desc", ([ /* sizeof() == 3 */
  "白骨" : (: search_skeleton :),
  "树林" : "你发现树林中的角落似忽有点奇怪, 你想再搜寻看看吗?\n",
  "角落" : "你走近角落一看，赫然发现一堆白骨，\n"+
               "看来这恶人谷可真有点可怕。\n",
]));

  setup();
}


int valid_leave(object who, string dir)
{
        if( random(10)<1 ) {
                who->move(__DIR__"forest02");
                return notify_fail("");
        }
        return 1;
}

void init()
{
        add_action("do_push_tree","push");
}

string search_skeleton()
{ 
        int i ;
        i = this_player()->query_temp("search_skeleton");
     
        if (this_player()->query_temp("b_bottle") == 1)
                return
                "你不是已经找到了个青色瓶子??\n";
        else if ( i > 1) {
                new(BAD_OBJ"b_bottle")->move(this_player());
                this_player()->set_temp("b_bottle",1); 
                return 
        "经过仔细地搜寻过这些白骨后，终于在白骨堆中找到了个青色小瓶子。\n";
        }       
        else {
              this_player()->set_temp("search_skeleton",++i);
              return "你找了找，结果甚也没找到。\n";
        } 
}

int do_push_tree(string arg)
{
        if( arg == "tree" ) {
  		new(BAD_NPC"snake-npc")->move(__DIR__"forest02");
                this_player()->move(__DIR__"forest02");
                tell_object(this_player(),
          "\n 你轻轻地向着这棵奇怪的树推去....\n"+
            " 哇哇哇! 没想到这树只是个晃子，想必是掉到这恶人谷中的陷阱来了。\n"+
            " 可得小心一点应付才是...\n");
        }
        else
		tell_object(this_player(),"推推推....疑..你要推甚?\n");
        return 1;
}
