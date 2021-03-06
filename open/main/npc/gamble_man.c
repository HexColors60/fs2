#include "/open/open.h"
inherit NPC;

void create()
{
        set_name("轩辕三光", ({ "san guan", "guan" }) );
        set("race", "人类");
        set("gender", "男性");
        set("age", 38);
        set("long", @LONG
他是恶赌徒轩辕三光，每次一赌下去，不输光当光裤子脱光是不会
罢手的。他赌术奇差，却老是自命不凡，唯一值得自傲的，就是他只要
一赌下去，非得对方认输不可，这也是恶赌徒称号的由来。不过他有一
项优点，从不赖账。
LONG);
        set("attitude", "peaceful");
        set("str", 27);
        set("cor", 25);
	set("combat_exp", 1689);
        set("chat_chance", 8);
        set("chat_msg",({  
		"轩辕三光说道: 终于让我找到一本赌林奇书了。\n",
		"轩辕三光说道: 谁敢赖账我一定Ｋ死他。\n",
		"轩辕三光说道: 赌博最重要的是输赢各凭本事，输要输得起。\n",
		"轩辕三光说道: 多年来我已经没碰到敌手了。\n",
        }));
        set("inquiry", ([
	"赌神秘术"	: "你以为问我我会给你吗? 别傻了, 除非跟我赌一局！",
	"输得起"	: "废话, 不然还有谁愿意跟你赌啊!",
	"赌林奇书"	: "我找了老半天才找到的，当然是珍而密之啰。",
	"本事"		: "哈，来来来，赌一场见真章。",
	"输赢各凭本事"	: "小子，难不成你不懂赌博规矩？还想赖账？",
	"赖账"		: "谁谁谁? 谁敢赖账我去Ｋ死他!",
	"敌手"		: "小子, 想比一场吗? 来来来, 回答我! 要不要比一场?",
	"赌博"		: "赌博是我最拿手的了，你愿意跟我比一场吗？快点回答！",
	"比一场"	: "比一场? 只要回答 yes or no 就可以了。",
	"回答"		: "就是 answer y 或者 answer n 嘛!",
        ]) );
        set_temp("apply/attack", 20);
        set_temp("apply/damage", 3);
        set_temp("apply/armor", 4);
	set_skill("dodge",30);
	set_skill("parry",40);
 
        setup();
}

void init()
{
  add_action("do_answer", "answer");
}

int do_answer(string arg)
{
  object	me=this_player();
  int		value;

  printf ("%O\n", arg);
  if (arg == "n" || arg == "no" ) return
	notify_fail ("轩辕三光说道: 不要就算了, 还啰哩啰唆的。\n");
  else if (arg == "y" || arg == "yes") {
    say ("这里有一个铜板, 你猜是正面还是反面?\n");
    return 1;
  }

  if (arg == "你赖账" || arg == "赖账") {
    if (me->query_temp("quests/gamble_book") == 2) {
	message_vision("轩辕三光说道: $N敢说我赖账, 不服气来打一场架啊。"
		"还是乖乖再赌一局试试吧?!要不要再来一盘?",
		me);
	return 1;
    }
    else {
	message_vision("轩辕三光说道: 赖账? 赌博的规矩你是会不会啊!"
		"多说无用, 不跟你玩了, 哼!\n",
		me);
	return 1;
    }
  }
  value = random(2);
  if (arg == "正面" || arg == "正")
    if (value) {
	if (me->query_temp("quests/gamble_book"))
	  me->set_temp("quests/gamble_book",2);
	message_vision("轩辕三光说道: 哈! 不是反面, $N猜正面就错了!\n", me);
    }
    else say ("哈! 是反面, 你猜正面就错了!\n");
  else if (arg == "反面" || arg == "反")
    if (value) say ("哈! 是正面, 你猜反面就错了!\n");
    else {
	if (me->query_temp("quests/gamble_book"))
	  me->set_temp("quests/gamble_book",2);
	say ("哈! 不是正面, 你猜反面就错了!\n");
    }
  else {
    message_vision("轩辕三光说道: 有什么问题直接说就好了, 不必那么客气 :)\n",
	me);
    return 1;
  }
  say ("怎样, 愿赌服输, 不得赖账, 要不要再来一盘?\n");
  return 1; 
}

void die()
{
  object        me;

  me = this_object()->query_temp("last_damage_from");
  if (me) {
    if (me->query_temp("quests/gamble_book") >= 2) {
      message_vision("轩辕三光说道: 好吧, 我认了, 跟你说吧, 为了怕人抢, 我把"
	"赌神之秘藏在这里的某个地方，有本是你自己找出来。\n",
	me);
      me->set_temp("quests/gamble_book", 3);
    }
  }

  ::die();
}
