inherit ROOM;
#include <ansi.h>
string screen();
void create ()
{
set("short", HIW"试炼之塔--领奖区"NOR);
set("long",@LONG

一部极大的主电脑正在此处运转着，它就是掌管着‘试炼之塔’的
主电脑，你必须载入(check)晶片，才可以兑换奖品。

一个电脑银幕(computer screen)就在你眼前。
LONG);
set("exits", ([
"west" : __DIR__"ticket",
]));
set("no_die_room",1);
set("item_desc",([
"computer screen":(:screen:),
"screen":(:screen:),
"银幕":(:screen:),
"电脑银幕":(:screen:),
]));
setup();
}

void init()
{
add_action("do_check_card","check");
}

string screen()
{
object me=this_player();
tell_object(me,"
"HIB"========================================================================

	"HIW"使用者："+me->query("name")+"

	目前挑战楼层："+me->query("quest/start_game")+"

	晶片记录："+present("fight_card",me)->query("name")+"

"HIG"‘"HIR"试炼□塔"HIG"’"HIW"奖品列表：

LV 10～       LV 20～       LV 30～       LV 40～       LV 50～

"HIY"黄金一两      尚待讨论      尚待讨论      尚待讨论      尚待讨论

"HIW"LV 60～       LV 70～       LV 80～       LV 90～       LV 100～

"HIY"尚待讨论      尚待讨论      尚待讨论      尚待讨论      "HIG"成长型武器一把
                                                        感谢巫师:小渡(wataru)制作。
"HIC"P.S.  LV100以上另外有设定可以挑战地下城

"HIY"      奖品：属性丸
"HIR"(不是我小气，只是目前试验阶段，不可能给什么东西，而且我也没收门票钱-.-)

                                       试炼塔塔主Firedancer@F.S.
"HIB"========================================================================
"NOR);
return "\n";
}


int do_check_card(string arg)
{
object me=this_player();
if(!arg)
return 0;
if(arg!="card")
{
tell_object(me,HIW"系统：错误，检查物件不适用于试炼之塔。\n"NOR);
return 1;
}
	if(!present("fight_card",me))
	{
	tell_object(me,HIW"系统：错误，使用者无携带晶片。\n"NOR);
	return 1;
	}
	if(!me->query("quest/start_game"))
	{
	tell_object(me,HIW"系统：错误，"+present("fight_card",me)->query("name")+"档案与"+me->query("name")+"不符合。\n"NOR);
	return 1;
	}
	if(!me->query_temp("apply_newdata"))
	{
	tell_object(me,HIW"系统：错误，"+present("fight_card",me)->query("name")+"资料并无更新，不能载入。\n"NOR);
	return 1;
	}
else
{
int i,j;
j=me->query("quest/start_game");
j=j-1;
i=j/10;
	switch(i)
	{
	case 0: tell_object(me,HIW"系统：此等级无奖品可拿。\n"NOR);
		me->delete_temp("apply_newdata");
		break;
	case 1: if(me->query("quest/start_game_prize")==1)
		{
		tell_object(me,HIW"系统："+new(__DIR__"prize01")->query("name")+"已经领取过，请勿重复领取。\n"NOR);
		me->delete_temp("apply_newdata");
		return 1;
		}
		{
		tell_object(me,HIW"系统："+present("fight_card",me)->query("name")+"资料载入完毕。\n"NOR);
		me->delete_temp("apply_newdata");
		new("obj/money/gold")->move(me);
		message_vision(HIW"系统：恭喜"+me->query("name")+"获得"+new("/obj/money/gold")->query("name")+"。\n"NOR,me);
		me->set("quest/start_game_prize",1);
		return 1;
		}
		break;
	case 2:if(me->query("quest/start_game_prize")==2)
		{
		tell_object(me,HIW"系统："+new(__DIR__"prize02")->query("name")+"已经领取过，请勿重复领取。\n"NOR);
		me->delete_temp("apply_newdata");
		return 1;
		}
		{
		tell_object(me,HIW"系统："+present("fight_card",me)->query("name")+"资料载入完毕。\n"NOR);
		me->delete_temp("apply_newdata");
		new(__DIR__"prize02")->move(me);
		message_vision(HIW"系统：恭喜"+me->query("name")+"获得"+new(__DIR__"prize02")->query("name")+"。\n"NOR,me);
		me->set("quest/start_game_prize",2);
		return 1;
		}
		break;
	case 3:if(me->query("quest/start_game_prize")==3)
		{
		tell_object(me,HIW"系统："+new(__DIR__"prize03")->query("name")+"已经领取过，请勿重复领取。\n"NOR);
		me->delete_temp("apply_newdata");
		return 1;
		}
		{
		tell_object(me,HIW"系统："+present("fight_card",me)->query("name")+"资料载入完毕。\n"NOR);
		me->delete_temp("apply_newdata");
		new(__DIR__"prize03")->move(me);
		message_vision(HIW"系统：恭喜"+me->query("name")+"获得"+new(__DIR__"prize03")->query("name")+"。\n"NOR,me);
		me->set("quest/start_game_prize",3);
		return 1;
		}
		break;
	case 4:if(me->query("quest/start_game_prize")==4)
		{
		tell_object(me,HIW"系统："+new(__DIR__"prize04")->query("name")+"已经领取过，请勿重复领取。\n"NOR);
		me->delete_temp("apply_newdata");
		return 1;
		}
		{
		tell_object(me,HIW"系统："+present("fight_card",me)->query("name")+"资料载入完毕。\n"NOR);
		me->delete_temp("apply_newdata");
		new(__DIR__"prize04")->move(me);
		message_vision(HIW"系统：恭喜"+me->query("name")+"获得"+new(__DIR__"prize04")->query("name")+"。\n"NOR,me);
		me->set("quest/start_game_prize",4);
		return 1;
		}
		break;
	default:tell_object(me,HIW"系统：你的晶片出了问题，请Firedancer帮你检查吧。\n"NOR);
		me->delete_temp("apply_newdata");
		break;
	}
return 1;
}
}