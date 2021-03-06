/************************************************************
*  clan_war_officer.c by ACKY 06.22.00                      *
************************************************************/

/*
	MUD 时间	现实时间
	  6 分钟	  1 秒钟
*/

#include <ansi.h>

inherit NPC;
void	multipk_start();
void	multipk_timeout();
void	multipk_win( object ob );
void	multipk_lose( object ob );
void	multipk_round( object win, object lose );
void	multipk_over();
int	war_score( int exp );
string	where( object ob );

#define	AREA_PK	"/open/clan/area/pk/"

int	multipk_now    = 0,	// 战争是否开始
	multipk_time   = 0,	// 战争经过时间
	multipk_point1 = 0,	// 宣战帮派战绩
	multipk_point2 = 0,	// 接战帮派战绩
	multipk_money1 = 0,	// 宣战帮派所得金钱
	multipk_money2 = 0;	// 接战帮派所得金钱
mapping multipk = ([
	"十三吉祥"	: ([
		"十三吉祥"	: ([ "war" : 0 ]),
		"嗜血八岐"	: ([ "war" : 0 ]),
		"邪武天境"	: ([ "war" : 0 ]),
		"红莲教"	: ([ "war" : 0 ]),
		"日月神教"	: ([ "war" : 0 ]),
		"苍龙圣域"	: ([ "war" : 0 ]),
		"封神界"	: ([ "war" : 0 ]),
		"侠客岛"	: ([ "war" : 0 ]),
		"烟雨江南"	: ([ "war" : 0 ])
			]),
	"嗜血八岐"	: ([
		"十三吉祥"	: ([ "war" : 0 ]),
		"嗜血八岐"	: ([ "war" : 0 ]),
		"邪武天境"	: ([ "war" : 0 ]),
		"红莲教"	: ([ "war" : 0 ]),
		"日月神教"	: ([ "war" : 0 ]),
		"苍龙圣域"	: ([ "war" : 0 ]),
		"封神界"	: ([ "war" : 0 ]),
		"侠客岛"	: ([ "war" : 0 ]),
		"烟雨江南"	: ([ "war" : 0 ])
			]),
	"邪武天境"	: ([
		"十三吉祥"	: ([ "war" : 0 ]),
		"嗜血八岐"	: ([ "war" : 0 ]),
		"邪武天境"	: ([ "war" : 0 ]),
		"红莲教"	: ([ "war" : 0 ]),
		"日月神教"	: ([ "war" : 0 ]),
		"苍龙圣域"	: ([ "war" : 0 ]),
		"封神界"	: ([ "war" : 0 ]),
		"侠客岛"	: ([ "war" : 0 ]),
		"烟雨江南"	: ([ "war" : 0 ])
			]),
	"红莲教"	: ([
		"十三吉祥"	: ([ "war" : 0 ]),
		"嗜血八岐"	: ([ "war" : 0 ]),
		"邪武天境"	: ([ "war" : 0 ]),
		"红莲教"	: ([ "war" : 0 ]),
		"日月神教"	: ([ "war" : 0 ]),
		"苍龙圣域"	: ([ "war" : 0 ]),
		"封神界"	: ([ "war" : 0 ]),
		"侠客岛"	: ([ "war" : 0 ]),
		"烟雨江南"	: ([ "war" : 0 ])
			]),
	"日月神教"	: ([
		"十三吉祥"	: ([ "war" : 0 ]),
		"嗜血八岐"	: ([ "war" : 0 ]),
		"邪武天境"	: ([ "war" : 0 ]),
		"红莲教"	: ([ "war" : 0 ]),
		"日月神教"	: ([ "war" : 0 ]),
		"苍龙圣域"	: ([ "war" : 0 ]),
		"封神界"	: ([ "war" : 0 ]),
		"侠客岛"	: ([ "war" : 0 ]),
		"烟雨江南"	: ([ "war" : 0 ])
			]),
	"苍龙圣域"	: ([
		"十三吉祥"	: ([ "war" : 0 ]),
		"嗜血八岐"	: ([ "war" : 0 ]),
		"邪武天境"	: ([ "war" : 0 ]),
		"红莲教"	: ([ "war" : 0 ]),
		"日月神教"	: ([ "war" : 0 ]),
		"苍龙圣域"	: ([ "war" : 0 ]),
		"封神界"	: ([ "war" : 0 ]),
		"侠客岛"	: ([ "war" : 0 ]),
		"烟雨江南"	: ([ "war" : 0 ])
			]),
	"封神界"	: ([
		"十三吉祥"	: ([ "war" : 0 ]),
		"嗜血八岐"	: ([ "war" : 0 ]),
		"邪武天境"	: ([ "war" : 0 ]),
		"红莲教"	: ([ "war" : 0 ]),
		"日月神教"	: ([ "war" : 0 ]),
		"苍龙圣域"	: ([ "war" : 0 ]),
		"封神界"	: ([ "war" : 0 ]),
		"侠客岛"	: ([ "war" : 0 ]),
		"烟雨江南"	: ([ "war" : 0 ])
			]),
	"侠客岛"	: ([
		"十三吉祥"	: ([ "war" : 0 ]),
		"嗜血八岐"	: ([ "war" : 0 ]),
		"邪武天境"	: ([ "war" : 0 ]),
		"红莲教"	: ([ "war" : 0 ]),
		"日月神教"	: ([ "war" : 0 ]),
		"苍龙圣域"	: ([ "war" : 0 ]),
		"封神界"	: ([ "war" : 0 ]),
		"侠客岛"	: ([ "war" : 0 ]),
		"烟雨江南"	: ([ "war" : 0 ])
			]),
	"烟雨江南"	: ([
		"十三吉祥"	: ([ "war" : 0 ]),
		"嗜血八岐"	: ([ "war" : 0 ]),
		"邪武天境"	: ([ "war" : 0 ]),
		"红莲教"	: ([ "war" : 0 ]),
		"日月神教"	: ([ "war" : 0 ]),
		"苍龙圣域"	: ([ "war" : 0 ]),
		"封神界"	: ([ "war" : 0 ]),
		"侠客岛"	: ([ "war" : 0 ]),
		"烟雨江南"	: ([ "war" : 0 ])
			]),
		]);

mapping pk_map = ([
	0	: "thunder",
	1	: "wind",
	2	: "ice",
	3	: "fire",
	4	: "land",
	]);

mapping pk_nmap = ([
	"thunder"	: 0,
	"wind"		: 1,
	"ice"		: 2,
	"fire"		: 3,
	"land"		: 4,
	]);

mapping pk_cmap = ([
	"thunder"	: "迅雷峰",
	"wind"		: "疾风崖",
	"ice"		: "玄冰岛",
	"fire"		: "烈焰谷",
	"land"		: "震天原",
	]);

string	multipk_clan1, multipk_clan2;		// 帮派ID 
object	*multipk_player1, *multipk_player2;	// 参战名单 1.宣战者 2.接战者

void create()
{
//	string *clan_id = CLANV_D->fs_clan();
	set( "title", "帮派战争区域主持人");
	set_name( "郑总管", ({ "clan_war officer", "officer" }) );
	set( "long", "\n他是帮派战争区域的主持人。\n" );      
	set( "clan/name", " 朝  廷 " );
	set( "race", "人类" );
	set( "gender", "男性" );
	set( "attitude", "friendly" );
	set( "no_kill", 1 );
	setup();
//	clan_id = fs_clan();
	multipk["烟雨江南"]["侠客岛"]["player1"]= "acky";
}

void init()
{
	if( !query_heart_beat( this_object() ) )
		set_heart_beat(1);
	::init();
}

int do_exchange( object me )
{
	if( me->query("clan/exchange") >= (me->query("clan/war")/1000) ) {
		tell_object(me, HIY"郑总管说道: 您目前战绩为 "+me->query("clan/war")+" 点, 还不到奖励的标准。\n"NOR);
		return 1;
	}
	me->add( "clan/exchange", 1 );
	me->add( "standby", 1 );
	tell_object(me, HIY"郑总管说道: 恭喜您获得替身一个, 在紧要关头他会替您游地府, 代您走一趟的。\n"NOR);
	return 1;
}

int do_list( object me )
{
	string	*clan;
	int	i, j, clan_sum, count;
	
	clan = keys(multipk);
	clan_sum  = sizeof(clan);

	for( i=0; i<clan_sum; i++ )
		for( j=0; j<clan_sum; j++ )
			if( multipk[clan[j]][clan[i]]["war"] == 1 ) {
				printf( "%|10s 向 %|10s 宣战。\n", clan[i], clan[j] );
				count++;
			}
	if( count==0 )		
		printf( HIC"无任何帮派发起战争, 狂想空间弥漫着祥和之气。\n"NOR );
	else
		printf( HIR"你察觉到%s股浓烈的杀气...\n"NOR, CHINESE_D->chinese_number(count) );

	return 1;
}

int do_multipk( string clan2, string *player )
{
	int	n;
	object	me, ob;
	string	clan1, clan1_id;
 multipk_player1=({});multipk_player2=({}); 
	
	// clan1 发动战争的帮派 (主动者)
	// clan2 发动战争的对象 (被动者)

	me       = find_player( player[0] );
	clan1    = me->query( "clan/name" );
	clan1_id = me->query( "clan/id"   );
	
        if( CLAN_D->clan_query( clan1_id, "gold" ) < 1000000 )
		return notify_fail( "帮派存款不足一百万两黄金。\n" );
	
	if( multipk_now ) {
		tell_object( me, "目前帮派战争区域正有帮派对战中, 请稍待。\n");
		return 1;
	}

	// multipk[被动帮派][主动帮派]
	//	["war"]		1: 愿意参战 0: 不愿意参战
	//	["player(1~5)"] 主动帮派参战名单
         
	if( multipk[clan1][clan2]["war"] ) {

		// 接战资料处理 clan1 接战帮派 clan2 宣战帮派
		CHANNEL_D->do_channel( me, "war", "我 -「"+me->query("clan/title")+"”接受"+clan2+"的战书。\n"NOR);

		if( !ob = find_player(multipk[clan1][clan2]["player1"]) ) {
			CHANNEL_D->do_channel( this_object(), "war", clan2 + "惧怕与" + clan1 + "对战, 逃走了。\n"NOR );
			multipk[clan1][clan2]["war"] = 0;
			return 1;
		}	
	}
	else { // 宣战资料处理 clan1 宣战帮派 clan2 接战帮派
		CHANNEL_D->do_channel( me, "war", "我 -「"+me->query("clan/title")+"”向"+clan2+"宣战。\n"NOR);
		multipk[clan2][clan1]["war"] = 1;
		for( n=1; n<6; n++ )
			multipk[clan2][clan1]["player"+n] = player[n];
		return 1;
	}

	// 开战资料处理 multipk1 宣战帮派 multipk2 接战帮派
	multipk_clan1 = ob->query("id");
	multipk_clan2 = me->query("id");

     for( n=1; n<6; n++ ){
tell_object(find_player("avgirl"),sprintf("%O",multipk[clan1][clan2]["player"+n]));
		if( find_player(multipk[clan1][clan2]["player"+n]) )
multipk_player1 += ({ find_player(multipk[clan1][clan2][sprintf("player%d",n)]) }) ;
  tell_object(find_player("avgirl"),sprintf("asdsad:%O",multipk_player1));
}
	for( n=1; n<6; n++ )
		if( find_player(player[n]) )
			multipk_player2[n-1] = find_player(player[n]);

	CHANNEL_D->do_channel( this_object(), "war", "【"+clan2+"】与【"+clan1+"】双方将于六小时后开战。\n"NOR); // MUD 6hr = REAL 1min

	multipk_now    = 1;
	multipk_time   = 1;

	return 1;
}

// 撤回宣战
int do_end( object me, string type, string clan2 )
{
	// clan1 宣布投降帮派 clan2 胜利帮派
	string	clan1;
	
	clan1 = me->query("clan/name");

	if( type == "multipk" ) {
		if( multipk[clan2][clan1]["war"] != 1 )
			tell_object( me, "贵帮并没有对此帮派宣战。\n");
		else {			
			tell_object( users(),
				HIW"\n【"+clan1+"】「"+me->query("clan/title")+"”"+me->query("name")+
				"("+me->query("id")+")送给【"+clan2+"】一封和平协议书。\n\n"NOR );
			multipk[clan2][clan1]["war"] = 0;
			return 1;
		}
	}
	return 1;
}

void heart_beat()
{
	// *multipk_player1, *multipk_player2; 参战名单 1.宣战者 2.接战者

	if( multipk_now ) {
		if( multipk_time == 50 )
			CHANNEL_D->do_channel( this_object(), "war", "【" +
				CLAN_D->clan_query( multipk_clan1, "name" ) + "】与【" +
				CLAN_D->clan_query( multipk_clan2, "name" ) + "】之战, 即将开始, 请双方赶紧做好最后的准备。" );
		if( multipk_time == 60 )
			multipk_start();
		if( multipk_time > 300 ) // MUD 24hr = REAL 4min
			multipk_timeout();
	}
	
	multipk_time++;	
}

void multipk_judge( object ob )
{
	int n;
	string area;

	area = where(ob);

	if( ob->query("war/clan") == 1 )
		if( where(multipk_player2[pk_nmap[area]]) == area ) {
			tell_object( ob, "郑总管说道: 尚未分出胜负。\n" );
			return;
		}
		else
			multipk_win( ob );

	else if( ob->query("war/clan") == 2 )
		if( where(multipk_player1[pk_nmap[area]]) == area ) {
			tell_object( ob, "郑总管说道: 尚未分出胜负。\n" );
			return;
		}
		else
			multipk_win( ob );
}

void multipk_win( object ob )
{
	int	score;
	object	vs;
	
	tell_object( ob, HIC"郑总管说道: 恭喜, 您获胜了。\n"NOR );
	score = ob->query( "clan/war" ) + ob->query_temp( "war/score" );
	ob->set( "clan/war", score );
	tell_object( ob, "您的战绩升为 " + score + " 点。\n" );

	if( ob->query("war/clan")==1 ) {
		multipk_point1++;
		multipk_money1 += ob->query_temp("war/score")/10;
	}
	else if( ob->query("war/clan")==2 ) {
		multipk_point2++;
		multipk_money2 += ob->query_temp("war/score")/10;
	}
	
	if( vs = find_player(ob->query_temp("war/vs")) )
		multipk_round( ob, vs );
	else
		multipk_round( ob, ob );
        ob->remove_all_killer();
	ob->move( ob->query( "war/from" ) );
	ob->delete_temp( "war" );
}

void multipk_lose( object ob )
{
	int	score;
	object	vs; 

	tell_object( ob, HIC"郑总管说道: 胜负已定, 您输了。\n"NOR );
	score = ob->query( "clan/war" ) - war_score(ob->query("combat_exp"));
	ob->set( "clan/war", score );
	tell_object( ob, "您的战绩降为 " + score + " 点。\n" );

	vs = find_player(ob->query_temp("war/vs"));
	ob->remove_all_killer();
	ob->move( ob->query( "war/from" ) );
	ob->delete_temp( "war" );
	multipk_win( vs );
}

void multipk_round( object win, object lose )
{
	if( win->query_temp("war/clan")==1 )
		multipk_point1++;
	else
		multipk_point2++;
		
	if( win == lose )
		CHANNEL_D->do_channel( this_object(), "war", "【" + pk_cmap[win->query_temp("war/area")] + "】胜负已分, 胜者"HIW + win->query("name") + HIR"!" );
	else
		CHANNEL_D->do_channel( this_object(), "war", "【" + pk_cmap[win->query_temp("war/area")] + "】胜负已分,"HIW +
			lose->query("name") + HIR"惨遭屠戮, 胜者"HIW + win->query("name") + HIR"!" );
	
	if( (multipk_point1+multipk_point2)==5 )
		multipk_over();
}

void multipk_start()
{
	int n;
	object ob;

	multipk_point1 = 0;
	multipk_point2 = 0;

	CHANNEL_D->do_channel( this_object(), "war", "时辰已到,【" +
		CLAN_D->clan_query( multipk_clan1, "name" ) + "】与【" +
		CLAN_D->clan_query( multipk_clan2, "name" ) + "】之战开始。" );

	for( n=0; n<5; n++ ) {
		if( multipk_player1[n] ) {
			ob->set_temp( "war/type", "multipk" );
			ob->set_temp( "war/clan", 1 );
			ob->set_temp( "war/area", pk_map[n] );
			ob->set_temp( "war/from", file_name(environment(ob)) );
			ob->set_temp( "war/vs", multipk_player2[n]->query("id") );
			if( multipk_player2[n] ) {
				ob->set_temp( "war/score", war_score(multipk_player2[n]->query("combat_exp")) );
				ob->set_temp( "war/vs", multipk_player2[n]->query("id") );
			}
			else {
				ob->set_temp( "war/score", 0 );
				ob->set_temp( "war/vs", "NONE" );
			}
			ob->move(AREA_PK+pk_map[n]+"_"+(random(9)+1));
		}
	}

	for( n=0; n<5; n++ ) {
		if( multipk_player2[n] ) {
			ob->set_temp( "war/type", "multipk" );
			ob->set_temp( "war/clan", 2 );
			ob->set_temp( "war/area", pk_map[n] );
			ob->set_temp( "war/from", file_name(environment(ob)) );
			if( multipk_player1[n] ) {
				ob->set_temp( "war/score", war_score(multipk_player1[n]->query("combat_exp")) );
				ob->set_temp( "war/vs", multipk_player1[n]->query("id") );
			}
			else {
				ob->set_temp( "war/score", 0 );
				ob->set_temp( "war/vs", "NONE" );
			}
			ob->move(AREA_PK+pk_map[n]+"_"+(random(9)+1));
		}
	}

}

void multipk_over()
{
	string clan_win, clan_lose;
	int point;

	if( multipk_point1 > multipk_point2 ) {
		clan_win  = multipk_clan1;
		clan_lose = multipk_clan2;
		point     = multipk_money1; 
	}
	else {
		clan_win  = multipk_clan2;						
		clan_lose = multipk_clan1;
		point     = multipk_money2;
	}

	CHANNEL_D->do_channel( this_object(), "war", "轰动武林, 惊动万教的【" +
		CLAN_D->clan_query( multipk_clan1, "name" ) + " VS " +
		CLAN_D->clan_query( multipk_clan2, "name" ) + "】之战终于结束。" );
	CHANNEL_D->do_channel( this_object(), "war", HIW +
		CLAN_D->clan_query( clan_win, "name" ) + HIR"战胜"HIW +
		CLAN_D->clan_query( clan_lose, "name" ) + HIR"。" );
	CHANNEL_D->do_channel( this_object(), "war", HIW +
		CLAN_D->clan_query( clan_lose, "name" ) + HIR"需赔"HIW +
		CLAN_D->clan_query( clan_win, "name" ) + HIY"黄金" +CHINESE_D->chinese_number(point)+ "万两"HIR"。" );

	point *= 10000;
	CLAN_D->add_money  ( clan_win ,  point );
	CLAN_D->add_money  ( clan_lose, -point );
	CLAN_D->add_clanset( clan_lose, "develop", -point/10000 );

	log_file("clan/"+clan_win+"/WAR-"+ctime(time())[4..6], sprintf("%s 战胜%|12s获得黄金 %5d 万两\n",
		ctime(time())[0..15], CLAN_D->clan_query(clan_lose,"name"), point ));
	log_file("clan/"+clan_lose+"/WAR-"+ctime(time())[4..6], sprintf("%s 败给%|12s赔款黄金 %5d 万两\n",
		ctime(time())[0..15], CLAN_D->clan_query(clan_win,"name"), point ));

	multipk_now    = 0;
	multipk_time   = 0;
	multipk_point1 = 0;
	multipk_point2 = 0;
	multipk_money1 = 0;
	multipk_money2 = 0;
}

void multipk_timeout()
{
	int	n;
	object	ob;
		
	CHANNEL_D->do_channel( this_object(), "war", "【" +
		CLAN_D->clan_query( multipk_clan1, "name" ) + " VS " +
		CLAN_D->clan_query( multipk_clan2, "name" ) + "】双方已激战整整一日。" );
	for( n=0; n<5; n++ ) {
		if( multipk_player1[n] )
			if( pk_cmap[where(ob)] ) {
				ob->remove_all_killer();
				ob->move( ob->query( "war/from" ) );
				ob->delete_temp( "war" );
			}
	}
	for( n=0; n<5; n++ ) {
		if( multipk_player2[n] )
			if( pk_cmap[where(ob)] ) {
				ob->remove_all_killer();
				ob->move( ob->query( "war/from" ) );
				ob->delete_temp( "war" );
			}
	}
	multipk_over();
}

string where( object ob )
{
	int	i;
	string	area;

	i = 24;
	area = file_name(environment(ob));

	if( area[16..22] == "multipk" )
		while( i++ )
			if( area[i] == '_' )
				return area[24..i-1];
	return "NONE";
}

int war_score( int exp )
{
	int level, i;

	i = exp-3000000;
	for( level=0; i>0; level++ )
		i-= (level)*1500;

	return level;
}

