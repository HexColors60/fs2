
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
void create () {
set ("short","七色回路");
        set ("long","一步踏入此地, 立觉阴冷刺骨, 此处乃是妖魔古堡中最阴最寒之地. 尽管
两边的墙壁上挂着两列烛台, 却不透一丝丝暖意, 冷光落壁, 邪氲雰雰, 
魔气呼啸, 掠影幢幢, 你顿时发现听觉与视觉已经不能作出正确的判断. 
突来阵阵杀气掀起了紫黑色的火线, 血腥的战斗将随时发生. 

");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "south" : __DIR__"room90",
            "west" : __DIR__"room86",
            "north" : __DIR__"room91",          
      ]));
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
   if( random(500) > obj->query_skill("parry")+obj->query_skill("dodge") ) {
   message_vision(HIR"嗤嗤声响处，几枚毒蒺菱快速射出，$N闪躲不及被毒蒺菱给射中！\n"NOR,obj);
   obj->add("eff_kee",-kee1/30);
   obj->apply_condition("dark_poison",random(20));
                                                  }                                              
  else  message_vision(HIW"嗤嗤声响处，几枚毒蒺菱快速射出，$N连忙窜高伏低，并挥手击落射来的暗器\n"NOR,obj);   
       }
}

