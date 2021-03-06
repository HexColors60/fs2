//made by fund//change and organization by Urd 女神

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
string to_kill();
string to_hurt();
string to_miss();
string ask_blade();

void create()
{
object ob;
set_name("叶秀杀",({"master yar","yar","master"}));
set("long","他是名震江湖的一代杀手，黑牙联的头目。\n");
set("gender","男性");
set("class","killer");
set("nickname","杀眼无情");
set("combat_exp",1000000);
set("attitude","heroism");
set("age",26);
set("str", 44);
set("cor", 34);
set("cps", 18);
set("per", 24);
set("int", 42);
set("kee",3000);
set("max_kee",3000);
set("gin",1600);
set("max_gin",1600);
set("atman",1200);
set("max_atman",1200);
set("mana",1000);
set("max_mana",1000);
set("force",3500);
set("max_force",3500);
set_skill("rain-throwing",100);
set_skill("blade",50);
set_skill("cure",50);
set_skill("literate",40);
set_skill("dodge",90);
set_skill("force",80);
set_skill("move",100);
set_skill("parry",80);
set_skill("dagger",90);
set_skill("poison",60);
set_skill("sword",50);
set_skill("throwing",100);
set_skill("shade-steps",100);
set_skill("blackforce",95);
map_skill("throwing","rain-throwing");
map_skill("dodge","shade-steps");
map_skill("force","blackforce");
set("force_factor",10);
set_temp("apply/armor",70);
set("inquiry",([
"追杀令" : (: to_kill :),
"魔气杀之伤" : (: to_hurt :),
"任务" : (: to_miss :),
"幽灵魔刀" : (: ask_blade :),
]));
set("force_factor",10);
set("chat_chance_combat",40);
set("chat_msg_combat",({
(:perform_action,"throwing.rain":)
}));
setup();
create_family("黑牙联",2,"主席");
ob=carry_object("/open/killer/obj/hate_knife");
ob->set_amount(100);
ob->wield();
carry_object("/open/killer/weapon/k_cloth3.c")->wear();
carry_object("/open/killer/weapon/k_boot3.c")->wear();
carry_object("/open/killer/weapon/k_arm3.c")->wear();
carry_object("/open/killer/weapon/k_head3.c")->wear();
}
void init()
{
add_action("do_join","join");
}
string to_kill()
{
object ob;
if( this_player()->query("quests/to-kill") ) {
command("?");
return "$N想帮我杀谁啊......";
}
if( present("letter",this_player() ) ){
command("?");
return "$N已经拿到密函了...不是吗??";
}
command("look "+this_player()->query("id"));
command("hmm");
ob = new(__DIR__"letter");
ob->move( this_player() );
message_vision("$N递给$n一封密函。\n",this_object(),this_player());
return "这里面写着被追杀的人........";
}

string to_hurt()
{
 object ob;
 object me;

 me=this_player();
 if( me->query_temp("hurt") !=1 )
 {
   command("?");
   return "$N在说什么呀？";
 }
 tell_object(me,HIY"唉。。。看来她还是找上门来了，这是六年前的事情\n");
 tell_object(me,"当年柴荣受了说法大长老之托，假装背叛而忍痛离开了庄静柔\n");
 tell_object(me,"并且为了避免庄静柔因恨而走火入魔，而将天魔解体大法取走\n");
 tell_object(me,"并且来到了黑牙联，在前代主席叶孤城的指导下创出了霸雨式\n");
 tell_object(me,"当时，师父他原本要将主席之位传给柴荣，但是因为庄静柔的缘故\n");
 tell_object(me,"为了杀手的安全，师父他便将主席之位传给了我，而与柴荣联袂离开，钻研更上层的武学\n");
 tell_object(me,"但是柴荣他心中一直挂念着静柔，而拜托了当时的兵器使完颜宏烈\n");
 tell_object(me,"将天魔解体大法，交给庄静柔并且解释清楚\n");
 tell_object(me,"岂知，完颜宏烈心生贪念，将天魔解体大法独吞，并且连杀了好几位魔教徒\n");
 tell_object(me,"嫁祸给柴荣，而引起了庄静柔的全面追杀令，逼使柴荣只好宣布脱离黑牙联\n");
 tell_object(me,"以免引起黑牙联与冥蛊魔教的全面对决，才使事件平静了下来\n");
 tell_object(me,"但是，静柔她并不原谅柴荣，因为她的心已死\n");
 tell_object(me,"或许你将他们的定情信物-灭神匕首。交给静柔她，也许她会想起当时的甜蜜\n");
 tell_object(me,"你中的不是魔气杀，而是天魔解体大法的阴性气指，目前只有静柔她会。\n");
 tell_object(me,"因此，我想天魔解体大法被她拿走了吧\n");
 tell_object(me,"灭神匕首在三楼的北边房间，我派了一个尸魂人守住，杀了他就可以得到\n"NOR);
 me->set_temp("god",1);
 return "$N在三楼调查一下，可以找到进去的开关";
}
string to_miss()
{
 object ob;
 object me;

 me=this_player();
 if( me->query("quest/rain") !=1 )
 {
   command("sm");
   return "$N连魔气杀都还不会，还想出什么任务？";
 }
 tell_object(me,"据说，红叶组有东瀛伊贺派的忍者潜入，只有独自一人\n");
 tell_object(me,"你去把他杀了，装备在三楼，自己去拿\n");
  me->set_temp("mission1",1);
 return "人头自己拿去换钱";
}

void attempt_apprentice(object ob)
{
command("l "+ob->query("id"));
if(this_player()->query("cor")<20)
{
command("sigh "+ob->query("id"));
command("say 你的胆识不够, 我不能收。\n");
return;
}
command("smile");
command("nod");
command("say 好！！");
command("recruit "+ob->query("id"));
}
int accept_fight(object ob)
{
command("say 真有骨气！！好, 我接受挑战！！");
message_vision( this_object()->name()+"脸上露出高兴的样子。\n",ob);
this_object()->set("bellicosity",1000);
command("cmd bellup");
return 1;
}
int accept_kill(object ob)
{
command("say 没想到居然有人敢来这撒野！！");
message_vision( this_object()->name()+"突然变脸，脸上出现杀气。\n",ob);
this_object()->set("bellicosity",3000);
command("cmd bellup");
return 1;
}
int do_join()
{
object ob=this_player();
if(!ob->query("class"))
{
ob->set("class","killer");
command("nod "+ob->query("id"));
}
else
{
command("say 志不同道不合, 另找明师去吧。\n");
return 1;
}
message("system",
HIB "纷乱动荡的武林中～～\n\n又出现一名恐怖的杀手～～\n" NOR,users());
return 1;
}
int accept_object( object me , object ob )
{
object obj;
if( !ob->query("true-corpse") )
{
command("say 甚么东西啊?");
return 0;
}
if( me->query("quests/to-kill") ) return 0;
command("nod");
obj = new("/open/snow/obj/ghost-blade");
obj->move(this_player());
message_vision("$N给$n一把"+obj->name()+"。\n",this_object(),
this_player());
me->set("quests/to-kill",1);
}
string ask_blade()
{
object ob;
if( present("ghost blade",this_player()) ) return "想要甚么 ?";
if( !this_player()->query("quests/to-kill") ) return "想要甚么 ?";
ob = new("/open/snow/obj/ghost-blade");
ob->move(this_player());
message_vision("$N给$n一把幽灵魔刀。\n",this_object(),this_player());
return "不要再弄掉了...";
}