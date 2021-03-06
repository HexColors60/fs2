// one.c by oda

#include </open/open.h>
#include <ansi.h>

inherit NPC;

string do_cure();
string stop_bleed();
string cure_poison();
string do_ask();

void create()
{
	set_name("万春流", ({ "one tsun liu", "one", "liu" }) );
	set("title", "神医");
	set("gender", "男性");
	set("age", 49);
	set("attitude", "peaceful");
	set("combat_exp", 100000);
	set("no_kill", 1);
	set("long", "你看到一个中年男子，身着长袍黄冠，羽衣飘飘，潇然出尘，\n神情看来说不出的和平宁静。\n他是恶人谷中唯一的医生，所以在恶人谷中的人都靠他治病。\n");
	set("str", 22);
	set("cor", 20);
	set("int", 33);
	set("spi", 30);
	set("cps", 32);
	set("con", 28);

	set("chat_chance", 3);
	set("chat_msg", ({
		"万春流叹了口气，喃喃道：唉..不知道有谁能救得了他..\n",
		"万春流摇了摇头说：可真苦了小鱼儿这孩子。\n",
	}) );
	
	set("inquiry", ([
	//"他"	:	(: do_ask1 :),
	//"小鱼儿":	(: do_ask2 :),
    "恶人森林" : "你想去恶人森林.. ?我也只是听说而已 ,详细位置整个恶人谷也只有杜杀和轩辕三光那个烂赌鬼知道而已...\n",
	"疗伤"	:	(: do_cure :),
	"止血"	:	(: stop_bleed :),
	"解毒"	:	(: cure_poison :),
    "破庙"  :   (: do_ask :),
	]));

	setup();
}

int accept_fight(object me)
{
	return notify_fail("万春流笑着对你说：这位"+RANK_D->query_respect(me)+"别开玩笑了好吗?\n");
}

string do_cure()
{
	int kee, ekee, mkee;
	object who;
	who = this_player();
	ekee = who->query("eff_kee");
	mkee = who->query("max_kee");

	if( ekee==mkee ) return "你不是好好的？哪有受伤？";
	if( ekee>=mkee*8/10 ) return "你的伤势不算严重，自己多休息就好了。";
	kee = (mkee*8/10 - ekee);
	if( !who->can_afford(kee*100) )
		return "对不起，以你伤势而言，只有这点钱恐怕帮不了你。";
	who->pay_money(kee*100);
	who->set("eff_kee", mkee*8/10);
	message_vision("万春流检查了一下$N的伤势，并且拿了几帖外伤药敷在$N的伤口上。\n", who);
	tell_object(who, HIC"你感觉到身上的伤口好多了。\n"NOR);
	return "好了，这位"+RANK_D->query_respect(who)+"，以后记得小心一点喔。";
}

string stop_bleed()
{
	int bleed;
	object who = this_player();

	if( !bleed = who->query_condition("bleeding") )
		return "你哪里流血了？流鼻血我可不治。";
	if( !who->can_afford(500*bleed) )
		return "对不起，以你伤势而言，只有这点钱恐怕帮不了你。";
	who->pay_money(500*bleed);
	message_vision("你看到万春流以极熟练的手法迅速的帮$N敷药并包扎伤口。\n", who);
	who->apply_condition("bleeding", 0);
	tell_object(who, HIC"你的伤口停止流血了。\n"NOR);
	return "这样应该就可以了。";
}

string cure_poison()
{
	int snake, coldpoison;
	int dark, five, rose, fire;
	object who = this_player();
	coldpoison = 0;

	if( who->query_condition("spring") ) {
		command("grin");
		return "阴阳合和散是没有解药的，你自己爱偷吃，我也没办法啦。";
	}
	snake = who->query_condition("snake_poison");
	if( dark = who->query_condition("dark_poison") )
		coldpoison += dark;
	if( five = who->query_condition("five_poison") )
		coldpoison += five;
	if( rose = who->query_condition("rose_poison") )
		coldpoison += rose;
	if( fire = who->query_condition("fire_poison") )
		coldpoison += fire;

	if( !coldpoison && !snake )
		return "老夫实在是看不出你中的是什么毒。";
	if( coldpoison && coldpoison<=3 ) {
		tell_object(who,"万春流摇摇头说：你中的天冰奇毒已经没办法再减轻了。\n");
	} else if( coldpoison ) {
		tell_object(who,"万春流皱着眉头说道：你中了冥魔教的天冰奇毒，我只能试着帮你减轻毒性看看了。\n");
		if( !who->can_afford(coldpoison/2*20000) )
			return "对不起，你的钱买不起这么贵的解药。";
		who->pay_money(coldpoison/2*20000);
		if( dark ) who->apply_condition("dark_poison", dark/2);
		if( five ) who->apply_condition("five_poison", five/2);
		if( rose ) who->apply_condition("rose_poison", rose/2);
		if( fire ) who->apply_condition("fire_poison", fire/2);
	}
	if( snake ) {
		tell_object(who, "万春流看了看你说到：你中了蛇毒喔。\n");
		if( !who->can_afford(500*snake) )
			return "对不起，你身上的钱不够用来解你的蛇毒喔。";
		who->pay_money(500*snake);
		who->apply_condition("snake_poison", 0);
	}
	message_vision("万春流仔细的检查了一下$N的状况，便转身从橱柜上的一个罐子里\n拿了几颗黑色药丸，放在$N的口中。\n", who);
	tell_object(who, "一阵强烈的臭味从你嘴里传了出来，令人作呕，你只好捏住鼻子一\n口气把药丸吞了下去。\n");
	if( coldpoison )
		tell_object(who, HIC"你感觉到体内的毒性减弱不少。\n"NOR);
	else
		tell_object(who, HIC"你感觉到舒服多了。\n"NOR);
	return "良药苦口，你就忍忍吧。";
}

string do_ask()
{
  int me;
  object who = this_player();
  if(who->query_temp("marks/karup2")!=1)
  {
   return "什么破庙？恶人谷哪有这种东西？\n";
  }
  else
  {
   who->set_temp("marks/allow",1);
message_vision("[36m万春流说道：[1;33m唉，这两个该死的女人！啥都跟你说了！
好吧，这破庙可是在恶人森林的某个地方，去找轩辕三光吧。
但可别说是我让你去的啊！不然杜杀知道了，你我都麻烦！[0m\n",who);
  return "[1;37m可千万别讲啊！[0m\n";
  }
}
