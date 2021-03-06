// go.c

#include <ansi.h>

inherit DIR_D;

varargs int main(object me, string arg, int repeat)
{
        string mout, min, dir,array_use, go="走", path, player1, player2;
        object env, obj, horse, rider, who;
        mapping exit;
        object *member,*enemy;
        int i, brief,exit_number,j,mob_number=0, rank,flag;

        seteuid(getuid(me));

	if( !arg )
		return notify_fail( "你要往哪个方向走?\n" );
	if( arg == "look" )
		return 0;

	env = environment(me);
/*	if( !env ) {
		write( "你身在虚无漂渺间, 哪里也去不了。\n" );
		return 1;
	}
*/
        arg = abbrdir(arg);
        dir = cdir(arg);
    if(!env->query("exits")) 
      return notify_fail("你要去哪里??\n");
    if ( !mapp(exit = env->query("exits"))){
		if (repeat>=1) me->force_me("look");
		return 0;
	}
	if ( me->query_temp("不准走") )
          return notify_fail("你现在不可以移动。\n");

    if (undefinedp(exit[arg])){
        if (repeat>=1) me->force_me("look");
        return 0;
    }
	if(exit[arg][sizeof(exit[arg])-2..sizeof(exit[arg])-1]!=".c")
		exit[arg]+=".c";
//        if(geteuid(me)=="bss") printf("%s\t%d\n",exit[arg],file_size(exit[arg]));
    if( file_size(exit[arg]) < 1 && !wizardp(me) )
    {
        printf("%s\t%d\n",exit[arg],file_size(exit[arg]));
		return notify_fail( arg + " 这个方向云雾深锁, 无法进入, 请通知 wiz!!\n" );
    }


	if( !obj=load_object(exit[arg]) )
		error( "该区域有问题, 请找巫师解决。\n" );
/*
        if(base_name(obj)[0..10]=="/open/clan/" &&
           base_name(obj)[11..14]!="area")
          return notify_fail("正当你想要往"+arg+"这个方向前进时，
忽然感到一阵阻力，似乎是大神不想让你进去那边!!\n");
*/
	if( !env->valid_leave( me, arg ) )
		return 0;
	if( me->over_encumbranced() )
		return notify_fail( "你的负荷过重，动弹不得。\n" );

/* 改到该区域做判断较佳
	enemy = all_inventory( env );
	if( env->query("evil") || env->query("god") )
		if(sizeof(enemy) > 6 ) {
			for( j=0; j<sizeof(enemy); j++ )
				if( !enemy[j]->is_fighting() && !userp(enemy[j]) && !enemy[j]->is_corpse() && enemy[j]->is_character() )
					mob_number++;
		}
		if( mob_number > 5 && !wizardp(me) )
		return notify_fail("妖魔发出的邪魔之气过大,使你无法移动\n");
*/
	if( obj->query("owner") ) {
		who = find_player(obj->query("owner"));
		if(!who) who = FINGER_D->acquire_login_ob(obj->query("owner"));
	        if(!who);
	     	else if( who->query("clan/id") == me->query("clan/id") &&
	     		who->query("clan/rank") < me->query("clan/rank") )
			return notify_fail( "无权进入此区域。\n" );
	}

        exit_number=sizeof(env->query("exits"));
        if( me->is_fighting() && !me->query_temp("follow-succeed") ){
//段家凌波微步加强功能，逃跑比别人容易
          flag=0;
          if((me->query("family/family_name")=="段家") && me->query("marks/linpo-steps"))
            flag=SKILL_D("linpo-steps")->can_flee(me,exit_number);
          if(flag) {
            mout = HIY"使出凌波微步的精微步法，向"+dir+"逸去。\n"NOR;
            min = HIG"翩然的落在地上。\n"NOR;
            me->set_temp("flee_go",1);
            if ( me->query_temp("join_pk") )
                    me->add_temp( "go_away", 1 );
          }
          else{
            if(me->is_busy()) return 0;
                if ( me->can_flee(exit_number) ) {
                     mout = "突破封锁往" + dir + "落荒而逃了。\n";
                     min = "跌跌撞撞地跑了过来，模样有些狼狈。\n";
                     if ( me->query_temp("join_pk") )
                        me->add_temp( "go_away", 1 );
                }
                else {
                        // 干扰 tin
                        switch(random(4)) {
                                case 0: message_vision( HIW"$N尝试逃跑, 但被敌人所阻, 逃跑失败。\n"NOR, me ); break;
                                case 1: message_vision( HIW"$N尝试逃跑, 但被敌人封锁, 逃跑失败。\n"NOR, me ); break;
                                case 2: message_vision( HIW"$N试着逃跑, 但被敌人所阻。\n"NOR, me ); break;
                                case 3: message_vision( HIW"$N试着逃跑, 但被敌人封锁。\n"NOR, me ); break;
                        }
                        return 1;
                }
          }
        }
        else {
            if(me->is_busy()) return 0;
if( me->query_temp("is_riding") && me->query_temp("horse") ) { 
                        horse = find_living( me->query_temp("horse") );
                         if(!horse) horse=this_player();
                        mout = "骑着"+horse->query("name")+"往" + dir + "走了过去。\n";
                        min = "骑着"+horse->query("name")+"走了过来。\n";
                }
                // 将行动的方式设在 temp("go") by ACKY
                else {
                if( !go = (string)me->query_temp("go") ) 
                        go = "走";
                mout = "往" + dir + go + NOR"了过去。\n";
                min  = go + NOR"了过来。\n";
        }
        }
            if(me->is_busy() && !me->query_temp("flee_go")) return 0;
        me->delete_temp("flee_go");
        // 这是阵法部份
        //roger 修改于 98/5/25
        //目前只适合sha-array
        if (me->query_temp("leader")){
          array_use=me->query_skill_mapped("array");
          member = me->query_team();
          for (i=0; i<sizeof(member); i++)
          if(member[i])
          if (member[i]->query_temp("use_form")==1){
          tell_object(member[i],"你们所排的阵形被破坏了。\n");
          if(find_object(SKILL_D(array_use)))
          return SKILL_D(array_use)->remove_array(member,me,me->query_temp("form_mean",1),me->query_temp("form_number",1));
                                                   }
                                    }

	if( userp(me) && !wizardp(me) && me->query("food") < 1 && !me->query("ghost") ) {
		me->do_command("hungry");
		write( "该吃点食物了。(eat)\n" );
		me->add( "gin", -me->query("age") );
		if( me->query("gin") < 1 ) {
			write( "饿得眼冒金星...@_@\n" );
			me->unconcious();
			return 1;
		}
	}
	else
		me->add( "food", -1 );

        if (me->visible(me) && !me->query("env/隐身") )
          message( "vision", me->name() + mout, environment(me), ({me}) );
        if( me->query_temp("invis") ) me->delete_temp("invis");
        if( me->query_temp("see-wait") ) me->delete_temp("see-wait");


        repeat--;
        if ( me->move(obj, repeat) ) {
          all_inventory(env)->follow_me(me, arg);
          me->remove_all_enemy();
          if (me->visible(me) && !me->query("env/隐身") )
            message( "vision", me->name() + min, environment(me), ({me}) );
          me->set_temp("pending", 0);

// 这里是用来将无用的房间从记忆体上拿掉, 请不要把这段删掉
//        if( !sizeof(all_inventory(env)) && ( !env->query("objects")
// 因为all_inventory(env)若无会传回错误值,故做此修正.Chun 09.22.96
          if ( !all_inventory(env) && ( !env->query("objects")
              || !sizeof(env->query("objects")) ) ) destruct(env);

          if (repeat > 0)
            main (me, arg, repeat);
          return 1;
        }
        return 0;
}

void do_flee(object me)
{
        mapping exits;
        string *directions, dir;

        if( !environment(me) || !living(me) ) return;
        exits = environment(me)->query("exits");
        if( !mapp(exits) || !sizeof(exits) ) {
          write ("你想逃跑，可是找不到出口。\n");
          return;
        }
        else
          directions = keys(exits);
        if (!dir = me->query("env/wimpydir"))
          dir = directions[random(sizeof(directions))];
        else {
          dir = abbrdir(dir);
          if (member_array(dir, directions) == -1)
            dir = directions[random(sizeof(directions))];
        }
        tell_object(me, "看来该找机会逃跑了...\n");
        tell_object(me, "你尝试往"+cdir(dir)+"逃跑。\n");
        main(me, dir);
}

int help(object me)
{
        write(@HELP
指令格式 : go <方向>
指令说明 :
           让你往指定的方向移动。
其他参考 :
           flee，wimpy，wimpydir
HELP
    );
    return 1;
}

