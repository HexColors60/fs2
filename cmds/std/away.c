// away.c by ACKY

int help(object me);
int main( object me, string arg )
{
	int i;
	string msg;
	
    if(!arg && !me->query("away"))
        return help(me);
    if( !arg && (me->query("away")[0]=='1') ) {
		msg = me->query("away")[1..-1];
		me->set( "away", "0"+msg );
		write( "解除 away 状态。\n");
	}
	else if( !arg ) {
		msg = me->query("away")[1..-1];
		me->set( "away", "1"+msg );
		write("进入 away 状态。\n"); 
	}
  	else {
		me->set( "away", "1"+arg );
    		write("您的 away 讯息设成 " + arg + "。\n");
 	}
	me->delete("away_msg");
  	return 1;
}

int help( object me )
{
	write("
	away <讯息> : 设定 away 状态。

	当别人 tell 您时, 系统自动帮您回覆 away 的讯息。

	若想解除 away 状态, 只要再下一次 away 指令便可解除。
	如果已输入过 away 讯息, 只要直接下 away 指令, 而不需
	重复输入讯息, 便可进入 away 状态。

	[范例] away 我去一下厕所。
	[说明] 当别人 tell 你时, 将出现\"我去一下厕所。\"。

	                                        by ACKY 06/01/2000
");
        return 1;

}
