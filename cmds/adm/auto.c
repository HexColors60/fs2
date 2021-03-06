// 清除太久没上线的玩家 by ACKY

inherit F_CLEAN_UP;

#define	DAY	365 // 超过 DAY 天没上线

int check( string arg );
int help( object me );
 
int main( object me, string arg )
{
	int o, sum;
	string *dir, *dir2;
	
        seteuid(getuid());       
        sum = 0;
               
        if( !arg )
        	return help(me);

        if( arg == "all" ) {
		dir = get_dir( "/data/login/" );
		for( o=0; o<sizeof(dir); o++ )
                	sum += check( dir[o] );
                write( "目前总共有 "+ sum +" 位玩家。\n" );
		return 1;
	}

	if( arg == "count" ) {
		dir = get_dir( "/data/login/" );
		for( o=0; o<sizeof(dir); o++ ) {
			dir2 = get_dir( "/data/login/"+ dir[o] +"/" );
                	sum += sizeof( dir2 );
                }
                write( "目前总共有 "+ sum +" 位玩家。\n" );
		return 1;
	}

	check( arg );

	return 1;	
}

int check( string arg )
{
	object ob;
	string *user, id, id_tmp;
	int i, j, k, sum, now, count;

	count = 0;
	now = time(); 
	user = get_dir( "/data/user/"+arg+"/" );
	sum = sizeof( user );

        printf( "处理中, 请稍后...\n" );
	for( i=0; i<sum; i++ ) {
                reset_eval_cost();
		id = user[i][0..sizeof(user[i])-3];
		if( find_player( id ) )
			continue;
                if( (string)SECURITY_D->get_status(id)!="(player)" )
			continue;
		if( !ob = FINGER_D->acquire_login_ob( id ) ) {
			printf( "档案 %s 有问题, 系统将其删除。\n", id );
			k=0;
			for( j=0; j<sizeof(id); j++ )
				if( id[j] == '.' ) {
					k++;
					if( k==2 )
						id_tmp = id[0..j] + "*";
				}
			write( "档案 "+ id_tmp +" 并非正常存档, 请检查。\n" );
			rm( "/data/user/"+arg+"/"+id+".o" );
			rm( "/data/login/"+arg+"/"+id+".o" );
			rm( "/data/backup/user/"+arg+"/"+id+".o" );
			rm( "/data/backup/login/"+arg+"/"+id+".o" );
			rm( "/data/backup2/user/"+arg+"/"+id+".o" );
			rm( "/data/backup2/login/"+arg+"/"+id+".o" );
			rm( "/data/sig/"+arg+"/"+id+".sig" );
 			rm( "/data/mail/"+arg+"/"+id+".o" );
			
 			count++;
		}
		if( objectp(ob) ) {
			if( ob->query("id")=="amandy" )
				ob->delete("ok_ip");
			if ( (now-ob->query("last_on"))/86400 > DAY )	{
				printf( "%s(%s) 已经超过 "+ DAY +" 天没上线, 系统将其资料删除。\n", ob->name(), ob->query("id"));
	 			if( ob->query("clan") )
	 				CLAN_D->clan_promote( ob->query("clan/id"), ob->query("id"), "banish", ob->query("clan/bank") );
				rm( "/data/user/"+arg+"/"+id+".*" );
	 			rm( "/data/login/"+arg+"/"+id+".*" );
	 			rm( "/data/backup/user/"+arg+"/"+id+".*" );
	 			rm( "/data/backup/login/"+arg+"/"+id+".*" );
	 			rm( "/data/backup2/user/"+arg+"/"+id+".*" );
	 			rm( "/data/backup2/login/"+arg+"/"+id+".*" );
	 			rm( "/data/sig/"+arg+"/"+id+".*" );
	 			rm( "/data/mail/"+arg+"/"+id+".*" );	 			
	 			count++;
			}
			destruct( ob );
		}
	}
	reclaim_objects();

        write( "\n\n原来 ID 以 " + arg + " 开头的玩家, 总共有 " + sum + " 位。\n" );
        write( "其中 "+ count +" 位超过 "+ DAY +" 天未上线的玩家, 已被系统清除掉了。\n" );
        write( "现在总共剩下 " + ( sum-count ) + " 位玩家。\n" );

	return sum-count;
}	

int help( object me )
{
	write(@TEXT

	auto [英文字母(a~z)]
	
	范例: auto c 		清查 ID 以 c 开头的玩家
	      auto all  	清查全部玩家
	      auto count	计算玩家资料总数

	清除 ID 以 (a~z) 开头, 且超过 365 天未上线的玩家。

	为了怕 wiz 使用不当, 便没有让 wiz 直接输入天数,
	以防 wiz 操作错误, 而不小心将玩家砍除...

						by ACKY
TEXT
	);
	return 1;
}

