#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
  set_name("仙剑的老长工", ({ "an old worker", "worker" }) );
        set("long","瞧他一副熟练的样子 ,好像从小就已经在这打扫至今了\n");
        set("gender", "男性" );
        set("class","swordsman");
        set("age", 75);
                set("str", 44);
                set("cor", 24);
                set("cps", 18);
                set("per", 24);
                set("int", 42);
	set("force",100);
        set("max_gin",100);
        set("force_factor",3 );
        set("gin",100);
        set("max_kee",2000);
        set("kee",2000);
        set("max_mana",100);
        set("mana",100);
        set_skill("force",40);
        set_skill("dodge",60);
        map_skill("dodge","sha-steps");
        set_skill("sword",60);
        map_skill("force","shaforce"); 
        set_skill("unarmed",90);
        setup();
        }
 void init()
  { 
   add_action("do_search","search");
   add_action("do_answer","answer");
   }
  int do_search(string arg)
  {
   object who;
    who=this_player();
    if( !who->query_temp("allow_read",1))
       return notify_fail("你尚未经过掌门与许 ,怎可擅自进来藏经阁翻阅密笈 ,快出去!!\n");
    if( arg!="shelf")
      return 0;
    else
     {
     message_vision("长工问道 : 你在找什么 ?? 可以告诉(answer)我吗 ??说不定我
       可以帮上忙.\n",who);
      who->set_temp("have_search",1);
      return 1;      
     }
    }
  int do_answer(string arg)
   {
  object who;
    who=this_player();
    
    if(!who->query_temp("have_search",1))
      return notify_fail("你在作什么??\n");
    if( arg!="仙剑密笈")
     return notify_fail("长工说道 : 我不能帮上忙 ,真是抱歉了\n");
    else
     {
      message_vision("长工说...听说当初绿毛老祖大闹仙剑之后,这本秘笈也就跟着失踪了,
             而在老祖被逍遥子制伏之后,只得到一把赤麟之剑,而秘笈也不知所踪了.\n",who);
   return 1;
      who->delete_temp("have_search",1);
      who->set_temp("have_answer",1);
      } 
    }          
