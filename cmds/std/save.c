// save.c
// 增加备份档的储存
// by wade (1996 6 6)
inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string arg)
{
    string id, src, dst ,room_name;
	// object link_ob, env=environment(me);
	object link_ob, env;

	seteuid(getuid());
	env = environment(me);

	if(env) room_name=file_name(env);
	if( !objectp(link_ob = me->query_temp("link_ob")) ) {
		// return notify_fail("你不是经由正常连线进入，不能储存。\n");
		me->set_temp( "link_ob", me );
		link_ob = me;
	}
	if( me->save() ) {
		if( env->query("valid_startroom") ) {
			me->set( "startroom", base_name(env) );
			write( HIW"当你下次连线进来时，将从此处进入狂想空间。\n"NOR );
		}
		else if( me->query("clan") )
			if( base_name(env) == CLAN_D->clan_query( me->query("clan/id"), "home" ) ) {
				me->set( "startroom", base_name(env) );
				write( HIW"当你下次连线进来时，将从此处进入狂想空间。\n"NOR );
			}
		write( HIY"档案储存完毕。\n请记得以 save -1 或 save -2 备份档案。\n"HIC"请随时以 help news 来观看狂想之任何最新异动。:)\n"NOR );
	}
	else return notify_fail( "\n\t存档失败...\n\n" );
	if( me != link_ob )
		link_ob->save();
	id = me->query("id");
	seteuid(ROOT_UID);
	src = sprintf( "/data/user/%s/%s.o", id[0..0], id );
	dst = sprintf( "/data/backup/user/%s", id[0..0] );
	if( file_size(dst) != -2 ) // 目录传回 -2，空档或不在传回 -1
	mkdirs(dst); // 新增的，会自动一层一层 mkdir
	dst += "/" + id + ".o";
	if( !cp( src, dst ) )
		return notify_fail( "无法备份您的资料档.\n" );
	src = sprintf( "/data/login/%s/%s.o", id[0..0], id );
	dst = sprintf( "/data/backup/login/%s", id[0..0] );
	if( file_size(dst) != -2 )
	mkdirs(dst);
	dst += "/"+id+".o";
	if (!cp (src, dst))
	  return notify_fail("无法备份您的资料档.\n");

	if (arg == "-1" || arg == "-2") {
	if( me->query("mud_age") < 10800 ) {
	  return notify_fail("你的年纪太小无法备份喔");}
	  src = sprintf ("/data/user/%s/%s.o", id[0..0], id);
	  dst = sprintf ("/data/backup2/user/%s", id[0..0]);
	  if (file_size(dst) != -2)
	    mkdirs(dst);
	  dst += "/"+id+".o";
	  if (!cp (src, dst))
	    return notify_fail("无法备份您的资料档.\n");
	}

	if (arg == "-1" || arg == "-2") {
	  src = sprintf ("/data/login/%s/%s.o", id[0..0], id);
	  dst = sprintf ("/data/backup2/login/%s", id[0..0]);
	  if (file_size(dst) != -2)
	    mkdirs(dst);
	  dst += "/"+id+".o";
	  if (!cp (src, dst))
	    return notify_fail("无法备份您的资料档.\n");
	}
	write (HIW"备份资料 ok.\n"NOR);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : save [-1|-2]

使用说明 :
	现在系统会不定期帮玩家存基本资料，正如死亡
    的时候会存档一样，但是要另外存备份档的话，现在
    修正为: save -1 会多增加一份备份档，而 save -2
    则会多第二份备份档。
	也就是，平常系统会帮你存档，称为基本档，这
    份基本档常常会发生意外而流失。save -1 则除了基
    本档之外，还会另存一份备份档，也就是一次存了两
    份，而 save -2  则会存成三份。由于读写档案是造
    成 lag  的主要原因之一，因此如非必要，最好别常
    用 save -1，save -2。
	通常，在你一天的最后一次玩的时候才储存备份
    档，普通的 save 目前会自动储存，以免不正常当机
    会造成一天的心血损毁。此外，在 bug  造成损失的
    时候，可以要求用备份档救回来。也就是说 :
        如果你发现怪怪的时候，请勿使用 save -1，更
    不要使用 save -2 来盖过资料。否则会把备份档弄
    坏掉。
HELP
	);
	return 1;
}
