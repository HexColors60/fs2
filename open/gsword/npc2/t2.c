#include <ansi.h>
inherit NPC;
string ask_test();
string ask_test1();

void create()
{
        set_name(HIW"第二试炼者"NOR, ({ "testman"}) );
        set("gender", "男性" );
        set("age", 158);
        set("int", 26);
set("long","传说中专门锻炼仙剑派门人的守护者..你可以问他有关试炼的事。\n");
        set("inquiry",([
        "试炼":(:ask_test:),
        "试炼印记":(:ask_test1:),

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
if (this_player()->query("quests/yantestmark1")==1&&this_player()->query("quests/yantestmark2")==1 &&this_player()->query("quests/yantestmark3")==1&& this_player()->query("quests/yan")==3)
 {
  this_player()->set("quests/yan",4);
  tell_object(this_player(),HIW"你已经通过第二试验了.所以我送你到第三试炼区去吧.\n"NOR);  
  message("system",this_player()->name()+HIW"通过仙剑第二试炼。\n"NOR,users());
  this_player()->delete("quests/yantestmark1");
  this_player()->set("title","[1;36m仙剑第二试炼剑侠[0m");
  this_player()->delete("quests/yantestmark2");
  this_player()->delete("quests/yantestmark3");  
  this_player()->delete("quests/2ndtest");
  this_player()->move("/open/gsword/room2/shab1.c"); 
}
else if (this_player()->query("quests/yan")>3)
{
  tell_object(this_player(),HIW"你已经通过第二试验了.所以我送你到第三试炼区去吧.\n"NOR); 
  this_player()->move("/open/gsword/room2/shab1.c"); 
}
else
 {
  tell_object(this_player(),HIW"第二试验的目的在于锻炼你的注意力.\n因此你由北方回到蜀山..并由蜀山附近找到三个试炼印记.之后才算过关\n"NOR);
  return (HIW"至于如何去找..这你就要多费心了...\n"NOR);
 }

}

string ask_test1()
{
  tell_object(this_player(),HIW"我只知道其中一个是好像在展伯承身上,另两个..你就要仔细的去找找了..\n"NOR); 
  return (HIW"不过我可以瞒着wiz 跟你说.主要的印记都在quest 人物的身上..你可以去跟他们问问试炼印记的事\n"NOR);
 }

