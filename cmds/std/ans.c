// 09.30.2K ACKY 修正

#include <ansi.h>

#include "/adm/daemons/word.c"

inherit F_CLEAN_UP;

int help( object );

int main( object me, string arg )
{
	string	respect;
	
	seteuid(getuid());

	respect	= RANK_D->query_respect(me);

	if( !me->query("robot/ans") )
		return 0;

	if( !arg ) {
		write(paper(me->query("robot/ans")));
		return 1;
	}

	if( me->query("robot/ans") != arg ) {
		write( "你是机器人吗? 这么简单都会答错?\n"+
		       "不想被 quit 的话就好好答吧!\n");
		me->add( "robot/wrong", 1 );
		if( me->query("robot/wrong")==5 )
			me->do_command("quit");
		return 1;
	}

	me->delete("robot");
    me->delete_temp("no_ans");
    new("/obj/money/silver")->move(me);
	write( HIC"原来" + respect + "不是机器人, 打扰您了, 这里有壹两银子, 请笑纳...\n"NOR );
	return 1;
}

int help( object me )
{
	write( @HELP

    当你正被系统审问时, 可以用 ans <答案> 来回答问题。
如果忘记题目, 可以直接用 ans 再显示一次题目。

HELP);
	return 1;
}
