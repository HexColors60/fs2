// enterd.c
//
//      预定将所有进 mud 的检查写在这边, 虽然 logind.c 中已经
//      有 enter_world 了, 但是还是写一个出来, 我比较习惯
//
//                                                      Arthur (1999/1/17)
//
// extract()                            By Annihilator (1-8-94)
// check_okip() & compare_okip()        By Arthur (1999/1/17)

varargs string extract( string str, int from, int to )
{
        if( nullp(to) ) return str[from..sizeof(str)-1];
        return str[from..to];
}

int compare_okip(object me)
{
        string  *ip_list, cur_ip, cur_ip_num, ip_part, num_part, be_checked;
        int     i, gate, check = 1, len, ed;

        if( !me ) return 0;
        if( !me->query("ok_ip") ) {
                tell_object(me, "你没有任何 ip 限制, 请用 okip 设定。\n");
                return 1;
        }
        
        ip_list = explode( me->query("ok_ip"), ":" );
        cur_ip  = query_ip_name(me);
        cur_ip_num = query_ip_number(me);
        i       = sizeof(ip_list);

        while(i--) {
                if( ip_list[i] == "" ) continue;
                check = 0;
                if( sscanf(ip_list[i], "%s*", be_checked) == 1 
                && be_checked != "" ) {
                        len      = strlen(be_checked);
                        ip_part  = extract(cur_ip, 0, len-1);
                        num_part = extract(cur_ip_num, 0, len-1);
                } else if( sscanf(ip_list[i], "*%s", be_checked) == 1 
                && be_checked != "" ) {
                        len      = strlen(be_checked);
                        ed       = strlen(cur_ip);
                        ip_part  = extract(cur_ip, ed - len);
                        num_part = extract(cur_ip_num, ed - len);
                } else {
                        be_checked = ip_list[i];
                        ip_part    = cur_ip;
                        num_part   = cur_ip_num;
                }
                if( lower_case(be_checked) == lower_case(ip_part) 
                ||  lower_case(be_checked) == lower_case(num_part) ) {
                        tell_object(me, " IP checked and ok.\n");
                        return 1;
                }
        }
        if( check ) {
                tell_object(me,
                        "无 IP Address 限制。\n");
                return 1;
        } else return 0;
}               
 
void check_okip(object me)
{
        if( !me ) return;
        if( !compare_okip(me) ) {
                tell_object(me, "警告: 你无法从这个位址上来。\n" );
                "/cmds/std/quit"->main(me);
                return;
        }
}
