// opem/killer/island/npc/louton.c
inherit NPC;     //鲁仝
#include <ansi.h>
#include </open/open.h>
inherit F_MASTER;
string song1();
string song2();
string dream();
string breakmethod();

void create()
{
set_name("鲁先生",({"lu ton","lu","ton"}));
set("long","
鲁先生原名鲁仝 ,年纪很轻加入黑牙联 ,听说当年跟叶孤城十分教好 ,曾一同前往东
瀛听说其实力不亚于叶孤城 .与叶孤城从东瀛回来之后就封刀不再出任务 ,却到这里
掌厨,口中常常哼着一些奇怪的(歌曲) .
\n");
  set("gender","男性");
  set("class","killer");
  set("title","老厨师");
  set("attitude","heroism");
  set("age",61);
  set("max_kee",3500);
  set("kee",3500);
  set("max_force",2000);
  set("force",2000);
  set("force_factor",10);
  set("combat_exp",1500000);
  set_skill("dodge",100);
  set_skill("move",100);
  set_skill("force",100);
  set_skill("parry",90);
  set_skill("shade-steps",100);
  set_skill("blackforce",100);
  map_skill("move","shade-steps");
  map_skill("dodge","shade-steps");
  map_skill("force","blackforce");
  set("chat_chance",10);
  set("chat_msg", ({
            ""+HIY+"鲁先生低声哼着: 天刚破晓 ,妳和我倚偎在树旁的岩石边 ,欣赏这美丽的黎明美景~~"+NOR+"\n",
            ""+HIY+"鲁先生说道: 来来来....要来点什么吗?"+NOR+"\n",
               }));
  set("inquiry",([
"歌曲" : (: song1 :),
"歌" : (: song2 :),
"梦想" : (: dream :),
"破浪的方法" : (: breakmethod :),
]));

setup();
add_money("gold",10);
}
void init()
{
add_action("do_report","report");
add_action("do_verify","verify");
}

int accept_kill(object who)
{
  command("say 唉....干麻欺负老先生呢....");
  return 1;
}
string song1()
{
 object ob;
 object me;
 ob=this_object();
 me=this_player();
if (me->query("class") != "killer" || me->query("quest/island") > 0)
{
  command("?");
  return "你说什么??";
}
  command("look "+me->query("id"));
  command("say 原来是"+me->query("name")+"啊....自从我到厨房以来,你是第一个问我这个问题的人呢.");
  return "这首(歌)....";
}
string song2()
{
 object ob;
 object me;
 ob=this_object();
 me=this_player();
if (me->query("class") != "killer" || me->query("quest/island") > 0)
{
  command("?");
  return "你说什么??";
}
tell_object(me,HIY"
鲁先生偷偷对你说 :
啊....这首个的背景,已经几十年没有人再提起了,没想到今天再度提起,还是令我感到无比的遗憾.
你们都知道当年我跟叶孤城一同到东瀛吧,这首歌是我跟一位东瀛女子所作的.当年在东瀛,因为任务
的关系,认识了一位东瀛女子.她是一位很有才华又很有见识的女子.当时后的我十分的欣赏她.她是
当地一位海外商人的女儿,由于父亲工作的关系,她常常到各地去.我们去东瀛所乘的船,就是他们父
女的商船.当时,我常常跟她一同聊天.你该知道,我们杀手不管在何时,都不该与外人有太多的沟通,
但是,面对她我却不自主的会想跟她谈话.听她叙述其他国家的特色以及传说,真是让当年年轻的我感
到十分的有趣.杀手除了杀戮技巧,还知道其他事物吗?!从那时候我就觉得...可能我不适合当杀手吧
,因为我并没有足够的定性压抑自己的感情与好奇.老叶了解我的想法,于是就同意我在东瀛的任务完
成之后,离开黑牙联,让我到世界各地探索新的事物.
\n"NOR);
 command("sigh");
tell_object(me,HIY"
我们完成任务之后,当我要送老叶离开东瀛时,在海上却遇到了东瀛的海贼,他们盯上了这艘商船,于
是我们在海上发生了激战,当时船上只有少数黑牙联的高手,寡不敌众,我在那时失去了我的右眼,也
失去了我的最爱,我的(梦想)....
\n"NOR);
 command("inn");
return "当时若不是老叶施展满天花雨掷金针杀了很多海贼,我看我们早就被剁成肉泥啦,呵呵呵呵....";
}

string breakmethod()
{
 object me= this_player();

  if (me->query("class") != "killer"|| me->query_temp("firstpart") !=3 )
  {
  	command("?");
  	return "你说什么??";
  }

  tell_object(me,HIY"
‘破浪方法？我是不清楚啦，但传说中，杀手有个(特殊身法)  据说可以操控风吧....
    或许可以利用他来突破神风吧.....但是除了杀手里面资历够老的杀手之外\n
  好像没有人知道这一个身法的真相，你去找找资历够老的杀手问问吧......’\n"NOR);
  me->set_temp("firstpart",4);
  return "杀手的老字号不过就那几个人，总有人知道(特殊身法)吧.....";
}

string dream()
{
 object ob;
 object me;
 ob=new("/open/killer/island/obj/luamulet");
 me=this_player();
if (me->query("class") != "killer"|| me->query("quest/island") > 0)
{
  command("?");
  return "你说什么??";
}
if (me->query_temp("get_luamulet") == 1)
  return "还没找到我儿子吗??";
  command("sigh");
tell_object(me,HIY"
鲁先生缓缓的唱着 : 天刚破晓,妳和我倚偎在树旁的岩石边,欣赏这美丽的黎明美景~~
\n"NOR);
tell_object(me,"一曲唱完,鲁先生给了我一个护身符,上面写着怪怪的文字,似乎是东瀛文字.旁边写着石田丽子四个汉字.\n\n");
ob->move( this_player() );
me->set_temp("get_luamulet",1);
return "这是当年她送我的定情之物,是一对的....她身上的有写着我的
            名字,麻烦你拿给枫林港的鲁寻,他是我养子,希望他能以此物寻
            回(父亲的梦想)!!";
}
int do_report()
{
object me=this_player();
if (me->query("quest/island") > 0)
{
command("smile");
return 1;
}
if (me->query_temp("care") == 1 || me->query_temp("complete")==1 )
{
 tell_object(me,HIW"\n你将事情经过的一切告诉鲁仝....\n"NOR);
 command("hmm");
 command("say 快将匕首拿给我看看!!");
 return 1;
}
if (me->query_temp("care") == 2 )
{
 tell_object(me,HIW"\n你将事情经过的一切告诉鲁仝....\n"NOR);
 command("sigh");
 command("say 年轻人无法忍受物质的诱惑也是正常的....");
 command("say 不过为了感激你, 我传授你一些暗器方面的技巧好了!!");
 me->set("quest/island",1);
 me->delete_temp("care");
 command("say 这技巧当你使用千古恨时, 便可以将霸雨螫魂的功力发挥到淋漓尽致!!");
 return 1;
}
command("?");
return 1;
}
int accept_object( object me , object ob ,object obj )
{
if (me->query_temp("complete") == 1 && ob->query("id") =="old dagger")
{
tell_object(me,HIY"鲁仝一见到匕首, 便老泪纵衡激动的说道:\n"NOR);
tell_object(me,HIY"事隔几十年, 我终于得到了我长年来的梦想!!年轻人, 真是谢谢你了!!\n\n"NOR);
tell_object(me,HIC"这把匕首, 原来是鲁仝最珍惜的随身武器, 当年鲁仝承诺丽子将来愿意\n"NOR);
tell_object(me,HIC"舍弃杀戮而与她自由自在遨游世界时, 便是以这把匕首为信物. 鲁仝与\n"NOR);
tell_object(me,HIC"丽子当时年轻的共同梦想完全寄托在这把匕首上. 如今鲁仝虽老, 丽子\n"NOR);
tell_object(me,HIC"虽亡, 但是他们的梦想与对彼此的爱, 却寄托在这把破旧的匕首里, 直\n"NOR);
tell_object(me,HIC"到永远....\n"NOR);
command("say 为了感谢你, 我将我所有关于暗器的技巧传授给你好了!!");
command("say 这技巧当你使用千古恨时, 便可以将霸雨螫魂的功力发挥到淋漓尽致!!");
command("say 当你需要千古恨时, 可以来跟我索取(verify)!!");
me->set("quest/island",3);
me->delete_temp("complete");
return 1;
}
if (me->query_temp("care") == 1 && ob->query("id") =="old dagger")
{
tell_object(me,HIY"鲁仝一见到匕首, 便老泪纵衡激动的说道:\n"NOR);
tell_object(me,HIY"事隔几十年, 我终于得到了我长年来的梦想!!年轻人, 真是谢谢你了!!\n\n"NOR);
tell_object(me,HIC"这把匕首, 原来是鲁仝最珍惜的随身武器, 当年鲁仝承诺丽子将来愿意\n"NOR);
tell_object(me,HIC"舍弃杀戮而与她自由自在遨游世界时, 便是以这把匕首为信物. 鲁仝与\n"NOR);
tell_object(me,HIC"丽子当时年轻的共同梦想完全寄托在这把匕首上. 如今鲁仝虽老, 丽子\n"NOR);
tell_object(me,HIC"虽亡, 但是他们的梦想与对彼此的爱, 却寄托在这把破旧的匕首里, 直\n"NOR);
tell_object(me,HIC"到永远....\n"NOR);
command("say 为了感谢你, 我将我所有关于暗器的技巧传授给你好了!!");
command("say 这技巧当你使用千古恨时, 便可以将霸雨螫魂的功力发挥到淋漓尽致!!");
command("say 当你需要千古恨时, 可以来跟我索取(verify)!!");
me->set("quest/island",2);
me->delete_temp("care");
return 1;
}
command("?");
return 1;
}
int do_verify()
{
object me,ob;
me=this_player();
if (me->query("quest/island") < 2)
{
command("say 我没什么东西可以给你!!");
return 1;
}
if (present("hate knife",me))
{
command("say 千古恨用完再跟我要吧!!");
return 1;
}
if (me->query("quest/island")==3)
{
ob=new("/open/killer/obj/hate_knife");
ob->set_amount(1000);
ob->set("no_drop",1);
ob->set("no_give",1);
ob->set("no_sell",1);
ob->move(me);
command("say 千古恨用完啦??那我再给你吧!!");
return 1;
}
if (me->query("quest/island")==2)
{
ob=new("/open/killer/obj/hate_knife");
ob->set_amount(500);
ob->set("no_drop",1);
ob->set("no_give",1);
ob->set("no_sell",1);
ob->move(me);
command("say 千古恨用完啦??那我再给你吧!!");
return 1;
}
}
