/*.
1.移动: 作了这个动作后,移动到某些房间去.
2.出现一条路:作了这一些以后,出现了一条路.
3.出现一只mob:作了动作以后,跑出一只mob 出来.
4.找到东西:作了这些动作以后,身上多了一个东西.
                    make by avgirl 00/06/28
*/
/*增加捡查帮派的功能                  *
 *               by avgirl 00/09/06   */

inherit ROOM;

int action_move(string,string);
int link_way(string arg,string opt);
int type(string verb,string ftype);
int add_mob(string arg,string opt);
int find_obj(string arg,string opt);
object env;
void init()
{
int dof;
mapping dom;

     env = environment(this_player());
        dof = sizeof(env->query("action"));

        if(dof != 0) {
                dom = env->query("action");
                add_action("action", keys(dom));
        }
}
int action(string arg)
{
        string keyword,verb,type,err_msg,check_ob,clan,*ally;
        object obj;
        int check_clan;


        verb = query_verb();
        keyword = env->query("action/"+verb+"/keyword");
        type = env->query("action/"+verb+"/type");
        err_msg = env->query("action/"+verb+"/err_msg");
        check_ob = env->query("action/"+verb+"/check_ob");
        check_clan = env->query("action/"+verb+"/check_clan");
        sscanf(base_name(env),"/open/clan/%s/%*s",clan);
        ally = CLAN_D->clan_query( this_player()->query("clan/id"), "ally" );

         if(!env->query("action/"+verb+"/filename")&& env->query("action/"+verb+"/filename")=="")
                return notify_fail("这个指令尚未完成。\n");
        if(!type) return notify_fail("这个指令尚未完成。\n");

// 这边是检查帮派的部份.
        switch(check_clan){
// 1时..就非本帮的不能使用...        
        case 1:
        if(this_player()->query("clan/id") != clan)
                return 0;
        break;
// 2.非同盟帮的不能使用.
        case 2:
        if(member_array( clan, ally ) == -1 && 
           this_player()->query("clan/id") != clan)
                return 0;
        default:
        }


        
        if(arg && keyword=="") return notify_fail(err_msg+"\n");  
        else if(keyword != "" && (!arg || arg != keyword)) return notify_fail(err_msg+"\n");
        if(check_ob && !obj=present(check_ob,this_player()))
                return notify_fail(err_msg+"\n");
        if(obj) destruct(obj);

        type(verb,"action");
return 1;
}

int type(string verb,string ftype)
{
        string type,filename,check;
        type = env->query(ftype+"/"+verb+"/type");
        filename  = env->query(ftype+"/"+verb+"/filename"); 
//下面是防作弊检查
// 只检查帮派的区域,帮派以外的区域不给inherit...
       if(filename!="" && sscanf(filename,"/open/clan/%s/%*s",check)!=2){
        log_file("clan/move_bug",sprintf("[%s] %s(%s)的房间 filename 为 %s\n",
            ctime(time()),
                        this_player()->name(),
                        getuid(this_player()),
filename,
        base_name(env)));
                return 0;
        }
// 以下是捡查该用那一种的移动,或招换..之类的..
// 并各自呼叫各字的fun...

        switch(type){

        case "action_move":
                action_move(ftype,verb);
        break;

        case "link_way":
                link_way(ftype,verb);
        break;

        case "add_mob":
                add_mob(ftype,verb);
        break;

        case "find_obj":
                find_obj(ftype,verb);
        break;

        }
        return 1;


}

int action_move(string arg,string opt)
{

/*
需要4个必要的叙述:
1.使用后本身看到叙述.(msg)
2.移动前这间房间看的到的叙述.(before_msg)
3.疑动后得房间所看到的叙述.(later_msg)
4.移动到的房间的档名.(filename)
*/
        string msg, before_msg, later_msg, filename;

        filename = env->query(arg+"/"+opt+"/filename");
        msg = env->query(arg+"/"+opt+"/msg");
        before_msg = env->query(arg+"/"+opt+"/before_msg");
        later_msg = env->query(arg+"/"+opt+"/later_msg");

//        seteuid(getuid());
        tell_object( this_player() , msg+"\n" );

// 显示讯息...
        message_vision( before_msg+"\n" , this_player() );

// 把你移到新房间...
        this_player()->move(filename);

// 显示讯息...
        message_vision( later_msg+"\n" , this_player() );
        return 1;
}
int link_way(string arg,string opt)
{
/*
需要5个必要的:
1.本身看到的叙述,(msg)
2.使用后,出现的叙述,(before_msg)
3.开启连结的方向,一定不会跟原有的方向重覆的.(path)
4.连结房间的file.(filename)
5.关闭连结时的叙述.(later_msg)
ps.这条路开启的时间是60秒.
*/
        string msg, before_msg, path, filename;
        filename = env->query(arg+"/"+opt+"/filename");
        msg = env->query(arg+"/"+opt+"/msg");
        before_msg = env->query(arg+"/"+opt+"/before_msg");
        path = env->query(arg+"/"+opt+"/path");

// 假如以经有这一条路了且还开过了,就不能开了..
        if(env->query("exits/"+path) &&
           env->query_temp("exits/"+path)) {
           write("路已经开了。\n");
           return 0;
           }

// 显示讯息
        tell_object( this_player() , msg+"\n" );
        message_vision( before_msg+"\n" , this_player() );

// 暂存房间计录..
        set_temp("exits/"+path,env->query("exits/"+path));

// 开始连接房间....
        set("exits/"+path,filename);

// 开启后60秒关闭这边出口..
        call_out("remove_link",60,arg,opt);
return 1;
}
int remove_link(string arg,string opt)
{
        string path, later_msg;

        later_msg = env->query(arg+"/"+opt+"/later_msg");
        path = env->query(arg+"/"+opt+"/path");

// 显示讯息
       tell_room(env,later_msg+"\n");

// 删掉新增的出口...
        delete("exits/"+path);

// 假如原先出口的话,恢复原先的出口...
        if(env->query_temp("exits/"+path)){
        env->set("exits/"+path,env->query_temp("exits/"+path));
        }

// 删掉计录
        delete_temp("exits/"+path);
        return 1;
}
int add_mob(string arg,string opt)
{
/*
需要以下几个参数:
1.本身看到的叙述,(msg)
2.使用后,这个房间所看到的叙述,(before_msg)
3.招唤mob 的档名,(filename)
4.招换后,可以看到的叙述(later_msg)
*/
        object mob;
        mapping ob_list;
        string msg, before_msg, later_msg, filename;

        ob_list=query_temp("clan_objects");
        filename = env->query(arg+"/"+opt+"/filename");
        msg = env->query(arg+"/"+opt+"/msg");
        before_msg = env->query(arg+"/"+opt+"/before_msg");
        later_msg = env->query(arg+"/"+opt+"/later_msg");

// 这边是设定如果被招唤过了,就不会在出来了.(ps.理论上可行.)
// 房间于重生后将会重新set_temp("object")所以重生后才能在叫.

        mob=new(filename);

// 设定不能重覆拿的部份..
        if(ob_list){
 if(ob_list[filename] || !objectp(ob_list[filename])){
        destruct(mob);
        write(env->query("action/"+opt+"/err_msg")+"\n");
                return 1;
        }
        ob_list +=  ([filename:mob]) ;
        } else ob_list =  ([filename:mob]) ;

// 显示讯息
        tell_object( this_player() , msg+"\n" );
        message_vision( before_msg+"\n" , this_player() ,mob);

// 把mob 移到你的房间去...
        mob->move(env);
        env->set_temp("clan_objects",ob_list);

// 显示讯息
        message_vision( later_msg+"\n" , this_player() ,mob);
        return 1;
}


int find_obj(string arg,string opt)
{
/*
需要以下几个参数:
1.本身看到的叙述,(msg)
2.下指令后,这个房间所看到的叙述,(before_msg)
3.拿到物品的档名,(filename)
4.拿到后,可以看到的叙述(later_msg)
*/
        object mob;
        mapping ob_list;
        string msg, before_msg, later_msg, filename;

        ob_list=query_temp("clan_objects");
        filename = env->query(arg+"/"+opt+"/filename");
        msg = env->query(arg+"/"+opt+"/msg");
        before_msg = env->query(arg+"/"+opt+"/before_msg");
        later_msg = env->query(arg+"/"+opt+"/later_msg");

// 这边是设定如果被拿过了,就不会在出来了.(ps.理论上可行.)
// 房间于重生后将会重新set_temp("object")所以重生后才能在叫.


// 设定不能重覆拿的部份..
        mob=new(filename);

        if(ob_list){
        if(ob_list[filename] || !objectp(ob_list[filename])){
                destruct(mob);
                        write(env->query("action/"+opt+"/err_msg")+"\n");
                return 1;
        }
                ob_list +=  ([filename:mob]) ;
        } else ob_list =  ([filename:mob]) ;


// 传出讯息...
        tell_object( this_player() , msg+"\n" );
        message_vision( before_msg+"\n" , this_player() ,mob);

// 把item 移到你的身上..

        mob->move(this_player());
        env->set_temp("clan_objects",ob_list);

// 显示讯息...
        message_vision( later_msg+"\n" , this_player() ,mob );
        return 1;
}
void reset()
{
::reset();
// 在重生的时候,删掉被人取过的temp...
   this_object()->delete_temp("clan_objects");
}
