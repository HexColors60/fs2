#include <ansi.h>
#include "/open/open.h"
inherit NPC;

void create()
{
        set("name","分身");
        setup();
}
void heart_beat()
{
        if(!this_object()->is_fighting()){
      message_vision(HIY"$N身影渐渐模糊不清,分身开始消失了!\n"NOR,this_object());  
           destruct(this_object());}
::heart_beat();           
}
