// by ACKY 06/01/00

#include <ansi.h>
#include <msg.h>

#define MAX_BUFFER	5120	// MAX 讯息流量 = 5KB

int help( object me );

int main( object me , string arg )
{
        int msg_buffer;

	if( !arg )
		return help( me );

	if( sscanf( arg, "%d", msg_buffer )!=1 )
		return help( me );

	if( msg_buffer == 0 ) {
		me->delete_temp( "msg_buffer" );
		write( HIC"系统将不取代任何讯息。\n"NOR );
		return 1;
	}

	if( msg_buffer < sizeof(MSG) || msg_buffer>MAX_BUFFER ) {
		write( HIR"[注意]"HIC" <最大讯息流量> 最小值为 "HIY+sizeof(MSG)+HIC" , 最大值为 "HIY+MAX_BUFFER+HIC"。\n"NOR );
		return 1;
	}

	me->set_temp( "msg_buffer", msg_buffer );	
	write( HIC"您将<最大讯息流量>设为 "HIY+msg_buffer+HIC"。\n"NOR );
	return 1;
}
        
int help( object me )
{
	write("
	msg_filter <最大讯息流量> : 设定接收讯息之最大流量。

		   <最大讯息流量> : 单位 byte

	如果讯息超过所设定的<最大讯息流量>, 将以 "+MSG+" 取代, 以节约流量。
	若<最大讯息流量>设定为 0, 系统将不取代任何讯息。
	每次上线时, 系统将自动设定<最大讯息流量>为 0。

	[范例] msg_filter 100
	[说明] 设定接收讯息之最大流量为 100 bytes。

	                                        by ACKY 06/01/2000
");
        return 1;

}

