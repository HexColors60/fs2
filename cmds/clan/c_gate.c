// c_gate.c

#include <ansi.h>

int help( object me );

int main( object me , string arg )
{
	int n;

	if( !me->query("clan") ) return 0;
	if( me->query("clan/rank") > 2 )
		return notify_fail( "您无权使用此指令。\n" );
	if( !CLAN_D->is_clan_room(me) )
		return notify_fail( "此处并非贵帮之地盘。\n" );
	if( !arg )
		return help(me);
	if( sscanf( arg, "%d", n )!=1 || n<1 || n>4 )
		return notify_fail( "状态只能输入(1~4)。\n" );

	switch( n ) {
	case 1:
		CHANNEL_D->do_channel( me, "ct",
			"\n\t我 -「"HIW+me->query("clan/title")+HIY"”郑重的宣布……\n\t" +
			"将本帮闸门警戒层级设为"HIC"[关闭]"HIY"，以防闲杂人等随意进入。"NOR );
		break;
	case 2:
		CHANNEL_D->do_channel( me, "ct",
			"\n\t我 -「"HIW + me->query("clan/title") + HIY"”郑重的宣布……\n\t" +
			"将本帮闸门警戒层级设为"HIC"[帮众]"HIY"，只准许本帮帮众进出。"NOR );
		break;
	case 3:
		CHANNEL_D->do_channel( me, "ct",
			"\n\t我 -「"HIW + me->query("clan/title") + HIY"”郑重的宣布……\n\t" +
			"将本帮闸门警戒层级设为"HIC"[盟友]"HIY"，让盟友可自由进出，以便交流互通有无。\n"NOR );
		break;
	case 4:
		CHANNEL_D->do_channel( me, "ct",
			"\n\t我 -「"HIW + me->query("clan/title") + HIY"”郑重的宣布……\n\t" +
			"将本帮闸门警戒层级设为"HIC"[开放]"HIY"，让各帮各派可自由进出，以便交流互通有无。\n"NOR);
		break;
	default :
	}

	CLAN_D->clan_set( me->query("clan/id"), "gate_level", n );

	return 1;
}

int help( object me )
{
	write("
	c_gate <状态>: 设定帮派闸门状态。

	[状态１] 关闭
	[状态２] 帮众
	[状态３] 盟友
	[状态４] 开放

					by ACKY 2000/03/28
");
        return 1;
}
