#include <ansi.h>
inherit NPC;
string ask_test();
void create()
{
        set_name(HIW"第三试炼者"NOR, ({ "testman"}) );
        set("gender", "男性" );
        set("age", 63);
        set("int", 26);
set("long","传说中专门锻炼仙剑派门人的守护者..你可以问他有关试炼的事。\n");
        set("inquiry",([
        "试炼":(:ask_test:),
        ]));
        set("combat_exp",50000);
        set("max_kee",500);
        set("max_gin",500);
                set_skill("unarmed",50);
        set_skill("parry",50);
        set_skill("force",50);
        setup();
   }
string ask_test()
{

tell_object(this_player(),HIW"第三试验的目的在于考验你的武力..\n"NOR);
 return (HIW"所以你往北方走去找试炼者吧\n"NOR);
 
}
