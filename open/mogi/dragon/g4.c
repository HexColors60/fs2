// Room: /u/p/poloer/dragon/g4
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>

void create ()
{
  set ("short", "魔王殿一楼");
  set ("long", @LONG
这里是魔王殿的一楼，里面一片乌黑黑的，伸手不见五指，怪恐怖
的。不时还传来怪物的叫声。

           ～嘿 ～嘿　～

LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"g5",
  "east" : __DIR__"g3",
]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}
void init()
{
      call_out("do_damage",1,this_player());
}
void do_damage(object ob){
 mixed all;
 object obj,who,room;
 int kee1,i,j;


        room = environment(ob);
        all = all_inventory(room);
        for( i = 0 ; i < sizeof(all) ; i++)
        {
   obj = all[i];
   kee1=obj->query("eff_kee");
   if( random(300) > obj->query_skill("dodge") ) {
   message_vision(HIR"突然间谷主用千里夺命手向$N伸去，$N闪躲不及,只听一声哀嚎$N已被吸去精力！\n"NOR,obj);
   obj->add("kee",-kee1/10);
                                                  }

  else  message_vision(HIW"突然间谷主用千里夺命手向$N伸去,但$N不\慌\不\忙\的\闪\过\n"NOR,obj);
       }
}
