// crazy_dog.c

inherit NPC;

string do_ask();
string do_ask1();

void create()
{
	set_name("地痞", ({ "dipi", "human" }) );
	set("race", "人类");
	set("age", 30);
	set("long", "一双凶恶的眼神郑上下打量着你。\n");
	
	set("str", 30);
	set("cor", 27);
	set("combat_exp",340);

	
	set("chat_chance_combat",4);
	set("chat_msg_combat", ({
		"地痞神不知鬼不觉的打了你一记耳光\n",
		"地痞突然狂性大发,七拳八脚的向你挥了过来。\n",
	}) );
	set("chat_chance", 5);
	set("chat_msg", ({
		"地痞说道: 大侠燕南天是个真英雄。\n",
		"地痞说道: 说起大侠燕南天，真的是令黑白两道都拜服的豪杰。\n",
	}) );
		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);
	set("inquiry", ([
	    "恶人证"	:	"是有听说这回事，拥有它才能顺利进入恶人谷。",
	    "恶人谷"	:	"恶人谷不就在昆仑山吗? 但..从来没有人找得到路。",
	    "昆仑山"	:	"地图上不就有了吗?",
	    "地图"	:	"自己去买一本吧。",
	    "义弟"	:	"谁是你义弟啊，也不自己照照镜子。",
	    "江枫"	:	"听说他微微的一笑，就足以让女子神魂颠倒，我要有这本领就好了。",
	    "燕南天"	:	(: do_ask :),
	    "大侠燕南天":	(: do_ask :),
	    "哭风坡"	:	(: do_ask1:),
	]) );

	setup();
       add_money("coin",50);
}

string do_ask()
{
  int	query;
  object me=this_player();

  query=me->query_temp("quests/badman_license");

  if (!query || query != 1 || me->query("quests/badman_license"))
  {
      switch (random(5)) {
	case 0:
	  return "燕南天谁人不知何人不晓，这问题拿来问我，是寻人开心吗?\n";
	  break;
	case 1:
	  return "燕南天神龙不见尾，我也不知他老人家身在何处。\n";
	  break;
	case 2:
	  return "燕南天三个字是你随口说说的吗?\n";
	  break;
	case 3:
	  return "幸好我没做什么伤天害理的大事，不然哪能逃离燕南天的手中。\n";
	  break;
	default:
	  return "求求您别在我面前提燕南天三个字好吗?\n";
      }
  }
  else {
    me->set_temp("quests/badman_license", 2);
    if (random(2))
      return "燕南天听说为了搭救他的义弟江枫，已经赶去哭风坡了。\n";
    else if (random(2))
      return "这几天以来，听说燕南天为了他的义弟江枫心急如焚，"+
		"此刻已追赶去哭风坡了。\n";
    else
      return "听说燕南天日夜兼程赶去哭风坡搭救他义弟，却没人知道谁是燕南天。\n";
  }
}

string do_ask1()
{
  object me=this_player();
  int	query1, query2;

  query1=me->query_temp("quests/badman_license");
  query2=me->query_temp("quests/help_water_god");

  if ((query1 && query1 == 2 && !me->query("quests/badman_license")) ||
      (query2 && query2 == 2 && !me->query("quests/help_water_god")))
  {
	if (random(2))
	  return "听说这地方连地图上都没有记载，却不知燕大侠是怎么找去的。";
	else
	  return "有人拿着地图跑去京城到处问人，也不知有没有问到。";
  }
  else
	if (random(2))
	  return "哭风坡? 只听说有这地方，到底在哪儿我也不知道。\n";
	else
	  return "哭风坡? 大概是专门哭爹哭妈的地方吧，我没兴趣。\n";
}
