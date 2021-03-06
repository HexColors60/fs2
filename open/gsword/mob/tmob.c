// copy from /d/snow/npc/teacher.c
inherit NPC;

int a;
int b;
int in_toss;

void create()
{
	set_name("王凯", ({ "wang","wang kai","kai"}) );
	set("gender", "男性" );
	set("age", 43);
	set("int", 26);
        set("long","他正聚精会神的看着桌上那一个大碗公，嘴中念念有词。你好奇
 的想知道尔J公里到底是啥宝贝，走近一看，挖哩勒！竟然是西八剌。\n" );
        
        set("inquiry",([
        "禁地": "你是谁！禁地的事我一概不知，就算知道不会告诉你，你走吧。\n",
        "封印": "唉！别说那么多讨人厌的话题了，咱们玩两把吧，你赢了，再来问
        	我也不迟啊。\n"]
        ) );
	
	set("combat_exp",1087);
        set("max_kee",500);
        set("max_gin",500);                        
	set("attitude", "peaceful");
	set_skill("unarmed",50);
	set_skill("parry",50);
	set_skill("force",50);
	setup();
}

init()
{
	add_action("play_dice","play");
	add_action("toss_dice","toss");
}


int play_dice(string str)
{

	if( str!="dice" ) {
		write("你要玩什么？\n");
		return 1;
	}
	write("王凯道:你先来吧，请掷骰子\n");
	return 1;
}

int toss_dice(string str)
{
	if( str!="dice") {
		printf("你要玩什么？\n");
		return 1;
	}
	if( in_toss ){
		printf("我正在跟别人玩，不要打搅我们！！\n");
		return 1;
	}

	a=random(5)+1;
	b=random(5)+1;
	message_vision("$N大喊∶[1m嬷眯八咪轰，天兵天将为我所用，西八辣！！[0m\n", this_player());
	if( a > 3 ) {
	 message_vision("$N大笑 : 哈！哈！我掷到 "+a+" 点，看来你是凶多吉少！！ 该你了！\n", this_player());
	} else {
	 message_vision("$N垂头丧气的说 : 唉！唉！真是赛，竟然是 "+a+" 点,你可乐了吧！你掷吧！\n", this_player());
	}//end if_else
	remove_call_out("shou_turn");
	in_toss=1;
	call_out("shou_turn",2, this_player()->query("id"));
	return 1;
}

void shou_turn(string str)
{
        say("\n只见王凯以迅雷不及掩耳速度，将碗公在空中晃了两圈，随即定在桌上，大叫一声‘开’！！\n");
	if( b > a ){
		command("say " + sprintf("哈！小兄弟你输了，我掷到 %d 点。\n", b));
	}
        else if( b==a){
		command("say " + sprintf("我也是掷到 %d 点，这盘咱们可是合局了。\n", b));
	}
	else {
		this_object()->add(str, 1);
		if(this_object()->query(str) != 3)
			command("say " + sprintf("真是背啊，竟是掷到 %d 点，算我倒楣，咱们再来两把！！\n",b));
		else if(this_object()->query(str) == 3)
		{
			command("say " + sprintf("真是背啊，竟是掷到 %d 点，输你三次!! 我就告诉你吧。\n",b));
			command("tell "+ str +" 当年祖师爷逍遥子用三样法宝将他封印起来，祖师爷退休之后就把三样宝物分别交给他三个大弟子保管，要解开天魔的封印，非要这三样法宝同时施法，除此之外别无他法。\n"); 
			this_object()->delete(str);
		}
	}
	in_toss = 0;
}
