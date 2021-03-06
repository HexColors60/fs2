#include <ansi.h>

inherit NPC;

void create()
{
      set_name("大灰狼",({"hyena"}));
      set("long",@LONG
一只相当少见的大灰狼，正在这翠郁的森林中觅食；偶而两道冷电般的目光
迅捷的在你身上转了一转，便足使你背后的冷汗直流。你不禁心想：此处并
不是个久留之地，还是快离开为妙。
LONG
      );

      set("race","野兽");
      set("gender","雄性");
      set("age", 6);
      set("attitude","peaceful");

      set("limbs",({"头部","腹部","前腿","尾巴","后腿"}));
      set("verbs",({"bite","claw"}));

      set_skill("dodge",50);
      set_temp("apply/armor",30);
      set_temp("apply/attack",50);
      set("combat_exp",3500);

      set("chat_chance",1);
      set("chat_msg",({
          (:random_move:),
          "大灰狼抬起头，嗅了嗅四周的味道。\n",
          "大灰狼往你的方向走了过来，在你的身旁绕了几圈。\n",
          "大灰狼仰起头来，望天空一声的长啸；吓的你一身的冷汗。\n",
      }));

      setup();
}

void init()
{
      object me=this_player();
      ::init();
      if( me->query_temp("blood")==1 )  {
      message_vision("大灰狼闻到$N身上的血腥味，一声狂啸、便扑向$N。\n",me);
      this_object()->kill_ob(me);
      }
}
