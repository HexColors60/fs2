#include <ansi.h>

inherit ROOM;

int leave( object me );

void create()
{
	set( "short", HIB"世界的角落"NOR );
	set( "long", "
    这里是世界的角落, 流浪于此地的人, 几乎都是无恶不作的大坏蛋, 或是
被朝廷放逐的罪人, 通常如果尚未服满刑期的话, 是不会释放的。\n
	"HIR"[check] 可以查询是否能回到中原。\n\n"NOR
	);

	set( "no_kill",  1 );
	set( "no_fight", 1 );
	set( "no_lyssa", 1 );
	set( "light_up", 1 );

	setup();
}

void init()
{
	int i;
	object *inv;

	add_action( "block_cmd", "" );
	if(!inv=all_inventory(environment(this_player())))
		return;
	for( i=0; i<sizeof(inv); i++ ) {
		if(userp(inv[i])) continue;
		message_vision( HIM"～～地底冒出阵阵浓烟～～\n"NOR, inv[i] );
		destruct(inv[i]);
	}
}

int block_cmd( string arg )
{
	if( (string)query_verb() == "check" )
		return leave(this_player());
    if(wizardp(this_player())) return 0;
	if( (string)query_verb() == "look"	||
	    (string)query_verb() == "ans"	||
	    (string)query_verb() == "say"	||
	    (string)query_verb() == "chat"	||
	    (string)query_verb() == "tell"	||
	    (string)query_verb() == "quit"	||
	    (string)query_verb() == "home"	||
	    (string)query_verb() == "msg_filter"||
	    (string)query_verb() == "summon" )
		return 0;
	write( "叫你不要随便乱动, 还乱动...\n" );
	return 1;
}

int leave( object me )
{
        int outtime;
        string msg="";

	if( me->query("mud_age") > me->query("jail_time") ) {
		write( HIY"\n请好好重新作人, 别再犯啰。\n\n"NOR );
// 新增 变回原先的title...
// by avgirl
      if(me->query("tmp_title")){
      me->set("title",me->query("tmp_title"));
      me->delete("tmp_title");
}
		me->delete("jail_time");
		me->move( "/open/common/room/inn.c" );
		tell_object( users(), HIW"\n" + me->query("name") + "从世界的角落返回中原了。\n\n"NOR );
		return 1;
	}
	outtime = me->query("jail_time")-me->query("mud_age");
	if( outtime/3600 ) {
		msg += HIR + outtime/3600 + HIW" 时 ";
		outtime %= 3600;
       	}
	if( outtime/60 )
		msg += HIR + outtime/60 + HIW" 分 ";
	if( outtime%60 )
		msg += HIR + outtime%60 + HIW" 秒";
	write( HIW"你还要服刑 " + msg + NOR"。\n" );

	return 1;
}
