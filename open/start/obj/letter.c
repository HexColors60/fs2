// /open/start/obj/letter.c by oda

#include <ansi.h>
#include <../start.h>
#include <room.h>

inherit ITEM;

void create()
{
	set_name("村长的信",({"sheik's letter", "letter"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long","这是凌云村长托你帮他送的信，里面不知道写了些什么。\n");
	set("unit","封");
	}
	setup();
}

void init()
{
	add_action("do_read", "read");
}

int do_read(string arg)
{
	object who;
	who = this_player();

	if( !arg || arg!="letter" )
		return notify_fail("你要读什么？\n");
	if( !who->query_temp("reading") ) {
		who->set_temp("reading", 1);
		return notify_fail("你突然想起村长交待的话，开始犹豫了起来。\n到底该不该看呢？....\n");
	}

/*
	if( who->query_temp("letter")==1 ) {

		switch( random(2) ) {
			case 0:
			write("\n
	老王：
	    我把钱都藏在村子南边的稻田里，你趁晚上没人的时候
	去偷偷把它挖出来，就不会被人发现了。记住，钱藏在一个
	稻草人附近，你去那里找一找(search)就知道了。\n\n");
			tell_object("为了避免村长他们发现信被偷看了，你小心翼翼的将信\n折好收了起来，准备先把信送去再回来拿钱。\n");
			who->set_temp("letter", 3);
			break;

			case 1:
*/
			write("\n
	老王：
	    我把钱都藏在....

你发现似乎这是一封藏宝图，正兴奋的准备往下读时....\n\n");
			call_out("do_read2", 3, who);
/*
			break;

		}
*/

		return 1;
/*
	}
	else if( who->query_temp("letter")==3 )
		return notify_fail("还看！不怕被发现啊？快去送信吧。\n");
	else
		return notify_fail("别人的信还不要乱看比较好吧。\n");
*/
}

int do_read2(object who)
{
	int i;

	tell_object(who,HIY"想活命的话就乖乖把信留下！\n\n"NOR);
	tell_object(who,"不知何时，你已经被一群凶神恶煞的土匪给团团围住了....\n\n");
	for(i=0; i<2; i++)
		new(S_NPC"bandit")->move(environment(who));
/*
	tell_object(who,CYN"山贼头子冷冷的说道：小子，我们注意凌云村那个老头已经很久了，今天总算给我逮到机会....哈哈哈哈哈！\n"NOR);
	tell_object(who,CYN"山贼头子看着你说：哼哼....交出你身上的钱跟信就饶你一命！\n"NOR);

	if( who->can_afford(1000)!=1 ) {
		tell_object(who,CYN"山贼头子破口大骂：臭小子，连点钱都没有。兄弟们，给我打！\n"NOR);
		who->set("gin", 20);
		who->set("kee", 20);
		who->set("sen", 20);
		tell_object(who,"\n你被山贼痛殴一顿以后，总算是保住了一条小命....不过信已经被抢走了。\n");
	}
	else {
		who->pay_money(1000);
		tell_object(who,"\n山贼抢了你的信和一千文钱以后便长扬而去了。\n");
	}

	tell_object(who,"你开始后悔自己不该偷看信的....\n");
	destruct( this_object() );
*/
	return 1;
}
