inherit ITEM;
#include <ansi.h>
void create()
{
set_name("挑战晶片",({"fight_card","card"}));
set("long","一个全新的战斗晶片，在你通过考验后，会自动做下记录，
若要看最新的纪录，请记得要到售票大厅去更新。");
set("value",0);
set("unit","片");
set("base_unit","片");
setup();
}

void init ()
{
object me=this_player();
int i=me->query("quest/start_game");
int a=i-1;
int j=me->query("quest/lose_game");
if(me->query("quest/start_game"))
        {
        set_name(HIW"LV"+a+"  "+me->query("name")+"□战斗晶片"NOR,({"fight_card","card"}));
        set("long","
 
"HIW"▕▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▏
▕▕▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▏▏
▕▕                          火神舞  特制晶片                              ▏▏
▕▕▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▏▏
▕▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▏"NOR"


                   名字："HIW+me->query("name")+NOR"

                   帮派："NOR+me->query("clan/name")+NOR"

                   师傅："NOR+me->query("family/master_name")+NOR"

                   目前挑战楼层：第 "HIY+i+NOR" 楼

                   目前登记失败次数： "HIY+j+NOR" 次
        ");
        }
}
