// by ACKY 04/03/00

#include <ansi.h>
inherit F_CLEAN_UP;
int help( object me );
int main( object me,string str )
{
	int num,value,num1;
	if( !str )
		return notify_fail("指令格式：cset_gatetax <黄金>\n");
	if( me->query("clan/rank") > 3 )
		return notify_fail("您无权使用此指令。\n");
    num = atoi(str);
    if( num < 0 )
		return notify_fail("关税不能是负的。\n");
	CLAN_D->clan_set(me->query("clan/id"),"gatetax",num);
	CHANNEL_D->do_channel(me, "ct",
		"\n\t我 -「"HIW+me->query("clan/title")+HIY"”郑重的宣布……\n\t本帮关税调为"+
		CHINESE_D->chinese_number(num)+"两黄金，\n\t税收将收入帮派钱庄，作为壮大本帮之用。"NOR);
    return 1;
}

int help( object me )

{
    write(@HELP

	cset_gatetax <黄金>

	设定帮派关税，收取过关所需之费用，以壮大帮派。
	
HELP
    );
 return 1;
}

