//open/killer/island/npc/son.c
inherit NPC;     //鲁寻
#include <ansi.h>
#include </open/open.h>
inherit F_MASTER;
string father_dream();
string island();

void think(object);
void create()
{
set_name("鲁寻",({"lu"}));
set("long","
年纪轻轻就是往返东瀛的贸易商人. 除了东瀛之外, 他也时常出海到其他外邦
进行贸易, 是一位十分有能力的年轻人.
\n");
  set("gender","男性"); 
  set("class","killer");
  set("title","贸易商");
  set("attitude","heroism");
  set("age",31);
  set("max_kee",1500);
  set("kee",1500);
  set("max_force",1000);
  set("force",1000);
  set("force_factor",10);
  set("combat_exp",700000);
  set_skill("dodge",70);
  set_skill("move",70);
  set_skill("force",70);
  set_skill("parry",60);
  set_skill("shade-steps",60);
  set_skill("blackforce",60);
  map_skill("move","shade-steps");
  map_skill("dodge","shade-steps");
  map_skill("force","blackforce");
  set("inquiry",([
"父亲的梦想" : (: father_dream :),
"东瀛岛" : (: island :),
]));

setup();
add_money("gold",10);
}
void init()
{
        add_action("do_nod","nod");
}

string island()
{
 object ob,obj;
 object me;
 ob=this_object();
 me=this_player();
 
if (me->query("class") != "killer"|| !me->query_temp("firstpart") )
{
  command("?");
  return "....你说什么？....我...不知道";
}
  command("grin");
  command("say 你靠近我，我小声的告诉你......");
  set_name("东瀛杀手",({"Japan killer","killer"}));
  this_object()->set("combat_exp",1500000);
  this_object()->set("max_force",3800);
  this_object()->set("gin",2000);
  this_object()->set("sen",2000);
  this_object()->set("max_kee",8000);
  this_object()->set("kee",8000);
  this_object()->set("eff_kee",8000);
  this_object()->set("force",3800);
  set_skill("dodge",80);
  set_skill("move",80);
  set_skill("parry",80);
  set_skill("throwing",80);
  set_skill("rain-throwing",70);
  set_skill("shade-steps",85);
  obj=carry_object("/open/killer/obj/lustar");
  obj->add_amount(1000); 
  obj->wield();
  ob->kill_ob(me);
  message_vision(HIR"$N突然对$n发动攻势!!!!!\n"NOR,ob,me);
  return "就凭你也想到东瀛岛去，就让你死在我的手下吧......";
}

string father_dream()
{
 object ob;
 object me;
 ob=this_object();
 me=this_player();
if (me->query("class") != "killer"|| me->query("quest/island") > 0)
{
  command("?");
  return "我父亲怎么了吗?";
}
  command("scream");
  return "咦? 你怎么会知道这件事? 我父亲给你的护身符能让我看一下吗?";
}
int accept_object( object me , object ob ,object obj )
{

if (me->query_temp("get_luamulet") == 1 && ob->query("id") =="luton's amulet")
{
 new("/open/killer/island/obj/luamulet")->move(me);
 command("say 真是麻烦你了,我从十几年前就开始从东瀛往来,希望能继承父亲的梦想.");
 command("say 但是他始终不肯再告诉我其他的线索....");
 command("say 如今有了这护身符及人名,我一定要找回父亲当年所失去的一切!!");
 command("say 你愿意助我一臂之力吗??");
 me->delete_temp("get_luamulet");
 me->set_temp("nod",1);
 return 1;
}
if (me->query_temp("get_note") == 1 && base_name(ob)=="/open/killer/island/obj/note")
{
 command("hmm");
 command("think");
 command("原来如此....");
 tell_object(me,"鲁寻慢慢将纸条的内容翻译给我听....\n");
 call_out("think",3,me);
 return 1;
}
else
{
 command("angry");
 command("gozila");
 command("dandan "+me->query("id"));
 command("say 不要乱拿东西给我啦!!我的身上是要放钱的!!");
 return 1;
}
}
int do_nod()
{
  object me=this_player();
  if (me->query_temp("nod") != 1)
{
 return 0;
}
  if (me->query_temp("nod") == 1)
{
 command("jump");
 command("say 太好了, 我们走吧!!");
 me->delete_temp("nod");
 tell_object(me,HIC"\n当一切准备就绪后,我与鲁寻及一些船员,一同前往东瀛.\n\n"NOR);
 me->move("/open/killer/island/ship");
 return 1;
}
return 1;
}
void think(object me)
{
tell_object(me,HIY"\n
原来,丽子并不是商人的女儿,而是海盗首领的女儿,由于跟着父亲到处闯荡,所以能到各
地探索未知的事物变成了她的心愿,可是因为无法忍受父亲及其手下凶残的行为,毅然决
定离开他们而过着自己的冒险生涯,直到遇到了鲁仝,终于发现长久以来的梦想终于有人
能跟她一起努力与分享.但是这心愿终究无打达成,当鲁仝被攻击时 ,是丽子以回到父亲
身为条件而换取海贼的撤退.事隔多年,丽子终于因为东瀛政府对海贼的扫荡而死于这座
小岛上.最后在信中留下了一句:我将你给我的定情物以及我们的梦想藏在属于我们的歌
曲之中.

然而, 将梦想藏在属于我们的歌曲之中??这句话是什么意思呢??
\n"NOR);
call_out("t1",1,me);
return ;
}
int t1(object me)
{
command("giggle");
command("say 稍微休息一下吧, 船只大概明天就能修好了.");
call_out("t2",1,me);
return 1;
}
int t2(object me)
{
tell_object(me,"\n经过一天的忙碌, 也该趁现在好好睡一下了....\n\n");
me->move("/open/killer/island/tent.c");
call_out("t3",5,me);
return 1;
}
int t3(object me)
{
tell_object(me,HIY"
不之过了多久, 天也快亮了, 在你心中总觉得有些事情不对劲, 但是又说不上来...
睡了一段时间, 你想也差不多该起来看看船只修复进度了. \n"NOR);
call_out("t4",2,me);
return 1;
}
int t4(object me)
{
me->move("/open/killer/island/is4.c");
command("hi");
command("say 起得真早, 天还没亮就起来了.");
command("say 船只快修好了, 你去准备一下吧, 等船只修好就可以离开了.");
me->set_temp("can_search",1);
return 1;
}

void die()
{
	string head;
	object winner = query_temp("last_damage_from");
	int j;
	if(!winner){
      		::die();
      		return ;
    	}
	
	if ( winner->query_temp("firstpart")==1 )
	{
	  message_vision(HIM"\n$N仔细端详了尸体，发现此人居然带着人皮面具？\n"NOR,winner);
	  message_vision(HIM"\n$N心念一转，莫非鲁寻遭到意外？\n"NOR,winner);
          message_vision(HIM"\n$N找了尸体，并没有发现任何异样.....\n"NOR,winner);
          message_vision(HIM"\n$N陷入沉思.........................\n"NOR,winner);
          message_vision(HIM"\n$N.................................\n"NOR,winner);
          message_vision(HIM"\n$N东瀛杀手...以前在哪里出现过呢？.......\n"NOR,winner);
          winner->set_temp("firstpart",2);
	}
      :: die();
}

