// 帮派指令集 cview 帮派之能力排行榜暨职位一览表 by ~babe~ (小雪球) ^O^

#include <ansi.h>
inherit F_CLEAN_UP;

void second( object *user , string str );
string area( object me );
int sort_rank(object ob1, object ob2);
int sort_exp(object ob1, object ob2);
int help( object me );

int main( object me, string str )
{
	object  *user;
	if( !str )
		if( me->query("clan") )
			str = me->query("clan/name");
                else
                        return help(me);

        user = filter_array(users(), "filter_clan", this_object(), str);
        user = sort_array(user, "sort_exp",  this_object());
	second( user , str );
	return 1;
}

void second( object *user , string str )
{
	int     i, count, state;
	string  list, CO, state_str, list2;
	user = sort_array(user, "sort_rank", this_object());
        i = sizeof(user);
        list = sprintf( HIG"《"HIY"%|10s"HIG"》"HIC" 线上帮众 "NOR"-\n", str );
	list+= "───────────────────────────────────────\n";
	count = 0;

        while( i-- )
        {
                switch(user[i]->query("clan/rank")) {
	case 1  :       CO = HIW + "Ψ";        break;
	case 2  :       CO = HIC + "ζ";        break;
        case 3  :       CO = HIY + "Φ";        break;
        case 4  :       CO = HIG + "卍";        break;
        case 5  :       CO = HIM + "Ξ";        break;
        case 6  :       CO = HIB + "∏";        break;
        case 7  :       CO = HIR + "Χ";        break;
		default :       CO = NOR + "？";        break;
		}

        if(this_player())
        if( wizardp(user[i]) && !wizardp(this_player()))
			continue;
		if( wiz_level(this_player())<6 && user[i]->query("env/隐身") && wiz_level(user[i]) && wiz_level(user[i]) > wiz_level(this_player()) )
		{
		 continue;
		}
		state = 0;
		state_str = "";
		count++;

                list = sprintf( "%s"HIC"【"NOR"%|10s"HIC"】"NOR"%s%|10s%s"NOR"",
			list,
                        area(user[i]),
                        CO,
                        (user[i]->query("clan/title") ? user[i]->query("clan/title") : "--无职衔--"), CO );
/*
		list2 = (user[i]->query("title") ? user[i]->query("title") : "" ) +
                        (user[i]->query("nickname") ? "「"+user[i]->query("nickname")+"”" : " " ) +
                        user[i]->query("name")+"("+user[i]->query("id")+")";
                if( strlen((list2))>80 )*/
                	list2 = (user[i]->query("nickname") ? "「"+user[i]->query("nickname")+"”" : " " ) +
                        	user[i]->query("name")+"("+user[i]->query("id")+")";
                list += list2;

		if( user[i]->query_temp("netdead") ) {
			state_str += HIR"(断线)"NOR;
			state = 1;
		}
		if( !environment(user[i]) ) {
			state_str += HIG"(异次元)"NOR;
			state = 1;
		}
		if( in_edit(user[i]) ) {
			state_str += HIY"(编辑)"NOR;
			state = 1;
		}
		if( in_input(user[i]) ) {
			state_str += HIC"(阅\读)"NOR;
			state = 1;
		}
		if( interactive(user[i]) && query_idle(user[i])>120 ) {
                	state_str += sprintf( "%s", HIM"(发呆 "+query_idle(user[i])/60+" 分钟)"NOR );
                	state = 1;
                }
                if( state ) list = list + /*"\t\t\t　　 " +*/ state_str;
                list += "\n";
        }

	list +=	"───────────────────────────────────────\n";
	list += sprintf( " 目前线上共有 %d 位帮众, 系统负担: %s\n\n", count, query_load_average() );

        this_player()->start_more(list);
}

int help( object me )
{
	write("
	c_view <帮派名称>

	显示线上某帮派之能力排行榜暨职位一览表。

	              １２３４５６７
	阶级颜色说明："HIW+"■"HIC+"■"HIY+"■"HIG+"■"HIM+"■"HIB+"■"HIR+"■"NOR"


	相关查询指令: c_who, c_state, c_list

                                                      by ACKY 03/27/00

");
	return 1;
}

string area( object me )
{
	int i;
	string path, tmp;

	if( environment(me) ) {
		if( CLAN_D->what_clan_area(me) == me->query("clan/id") )
			return "本帮地盘";
		path = file_name(environment(me));
	}
	else
		return "异 次 元";

	i = 6;
		while( i++ )
        {
          if(i >= sizeof(path)) break;
          if(path[i])
			if( path[i] == '/' ) {
				tmp = path[6..i-1];
				break;
			}
        }
	switch( tmp )
	{
	case "badman"	: return "恶 人 谷";
	case "beggar"	: return "丐　　帮";
	case "bonze"	: return "少 林 寺";
	case "capital"  : return "京　  城";
	case "center"	: return "中央驿站";
	case "clan"	: return "帮派地盘";
	case "dancer"	: return "镜 月 岛";
	case "doctor"	: return "银 针 门";
	case "death" 	: return "地　  狱";
	case "fire-hole": return "火龙幻界";
	case "gblade"	: return "金 刀 门";
	case "god"	: return "天　  界";
	case "gsword"	: return "蜀 中 城";
	case "hall"	: return "总理衙门";
	case "killer"	: return "杀手区域";
	case "love"	: return "绝 情 门";
	case "marksman" : return "长 沙 镇";
	case "mogi"  	: return "魔　  界";
	case "mulitpk"	: return "武斗会场";
	case "newhand"  : return "新手区域";
	case "ping"	: return "平 南 城";
	case "poison"   : return "冥蛊魔教";
	case "port"	: return "枫 林 港";
	case "prayer"	: return "圣 火 教";
	case "scholar"	: return "儒　　门";
	case "snow"	: return "雪 苍 派";
	case "start"	: return "凌 云 村";
	case "steeple"	: return "试 炼 塔";
	case "tailong"	: return "天 龙 寺";
	case "tendo"	: return "天 道 派";
	case "wind-rain": return "金风细雨楼";
	case "wiz"	: return "神　　界";
	case "wu"	: return "正晴武馆";
	default		: return "人　　间";
	}
}

int filter_clan(object ob, string name)
{
        if( ob->query("clan/name") == name )
                return 1;
        return 0;
}

int sort_rank(object ob1, object ob2)
{
	return ob2->query("clan/rank") - ob1->query("clan/rank");
}

int sort_exp(object ob1, object ob2)
{

	return (int)ob1->query("combat_exp") - (int)ob2->query("combat_exp");
}
