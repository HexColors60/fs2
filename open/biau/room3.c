// Room: /u/o/onion/room/w_room1.c

inherit ROOM;

void create()
{
	set("short", "镳局内堂走廊");
	set("long", @LONG
走廊的灯火依然明亮,在两旁还摆设了一些精美的花瓶,似乎价值不菲,空气中也传来
清淡的香味.你注意到瓶子上清一色插的都是纯白的花,只有在角落的一个花瓶里插着一朵
淡黄的茶花,有点儿奇怪...
    在走廊的两旁各有一间客间.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"guestroom1",
  "north" : __DIR__"guestroom0",
  "west" : __DIR__"room1",
  "east" : __DIR__"room4",
]));
        set("item_desc", ([ /* sizeof() == 1 */
          "bottle" : "    一个釉彩的花瓶,插上鲜花实在是相得亦彰,更添风采...\n"
          ]));
          
	set("valid_startroom", "1");

	setup();
}

void init()
{
      	        add_action("do_search","search");
        	add_action("do_move","move");
}
        
        int do_search(string str)
        {
        	
        	if(str!="bottle")
		{
        	write("你四处搜查,但是好像没有可疑的地方...唉~~白费工夫\n");	
        	return 1;
        	}
        	else
        	{
        	write("经过一番查看,你发现这瓶子似乎可以移动(move).\n");
        	tell_room(environment(this_player()),(string)this_player()->query("name")+
      	        "专心的观察着花瓶,你正起意想吓吓他时,他却突然转身对你诡异的一笑,\n"
      	        +"反而让你自己吓的半死...\n",({this_object(), this_player()}));              
      	        return 1;
      	        }
	}

	int do_move(string str)
	{
		if(str!="bottle")
		write("你在五鬼搬运吗?在搬啥东东啊...\n");
		else
		{
		write("你慢慢的将花瓶移动开来,只听到～咿～~的一声...\n"
		"哇!!...你站的地板突然裂了一个大洞,你像自由落体般掉了下去...\n");
		tell_room(environment(this_player()),(string)this_player()->query("name")+
		"所站的地方裂了一个大洞,你看到他掉了下去之后,地板马上恢复原状."+
		"只听见一阵阵有如杀猪的声音隐隐约约的传过来...\n",
		({this_object(),this_player()}));
                this_player()->reincarnate();
                this_player()->move(__DIR__"jail");
		write("碰～的一声,你终于掉到地了...\n");
		tell_room(environment(this_player()),"碰～的一声,你看到"+
		(string)this_player()->query("name")+"像死猪般的掉了下来...\n",
                ({this_object(),this_player()}));
		return 1;
		}
	}		
		     	      	           	
