// Room: /u/o/onion/workroom.c~
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "洋葱的小窝");
	set("long", @LONG
	
	一个小小的房间,随意的堆着一些东西,你最感到兴趣的是房间角落放着
	一张大桌子,上面摆着各式各样的书(book),另外你还闻到了一阵阵的香
	味从窗边传来,仔细一看却赫然发现一盆[1m【天山雪葱】[0m(onions),白色的
	花瓣传来扑鼻的香味..
	
LONG
	);

	set ("item_desc", 
	(["book" : "
	你看到这些厚厚的书包括了电子学,工数,线控..等密密麻麻的原文书,不
	禁由衷的佩服起[Onion]来了...\n",
          "onions" : "
        神秘的至宝,传闻中的仙物--[1m【天山雪葱】[0m,竟然在这出现了,透体白如玉
        有如雪般,因微风还轻轻的颤抖着,清淡的香味使你忍不住想要好好的品嗅
        (sniff)一番...\n"]));
      
        set("objects", ([
        "/u/o/onion/npc/noname": 1,
//      "/u/o/onion/npc/vendor": 1,
	 ]));	
        set("exits", ([ 
		"up" : "/open/ping/room/p1",
		"down" : __DIR__"fightroom",
		"north" : "/open/capital/room/SCH",
        	"west" : "/open/biau/room0",
		"south" : "/open/capital/room/D03",

        	"east" : "/open/wiz/hall1",
         ]));
        set("no_clean_up", 0);
        set("valid_startroom", 1);
                             
        setup();
                  }                                    
                                                              	 
	void init()
	{
	 add_action("do_sniff","sniff");
	}
	int do_sniff(string str)
	{
                object me = this_player();
                int max;
                
                    write("你走上前去, 用力的吸了一大口气,哇...口气清新... \n"
                    +"吸入的香气在你身体的奇经八脉之内窜动,你感到一切状况都复原了...\n");
		    me->reincarnate();
		    max = me->query("max_s_kee");
		    me->set("s_kee",max);		
                    max = me->query("max_gin");
                    me->set("eff_gin",max);
                    me->set("gin",max);
                    max = me->query("max_kee");
                    me->set("eff_kee",max);
                    me->set("kee",max);
                    max = me->query("max_sen");
                    me->set("eff_sen",max);
                    me->set("sen",max);
		    max = me->query("max_force");
		    me->set("force",max);
		    max = me->query("max_mana");
		    me->set("mana",max);	
                    max = me->max_food_capacity();
                    me->set("food",max);
                    max = me->max_water_capacity();
                    me->set("water",max);
                    me->clear_condition();
                     
                    tell_room(environment(me),(string)me->query("name")+
                    "走近[1m【天山雪葱】[0m,闻了一闻,脸上露出幸福的笑容.\n",({this_object(), me}));
                    return 1;
        }
