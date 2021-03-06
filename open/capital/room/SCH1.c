// Room: /open/capital/room/SCH1
inherit ROOM;

void create ()
{
  set ("short", "书生公会书房");
  set ("long", @LONG
这间书房是杨书文的藏书所在, 杨书文一生的心血都放在这里, 因
此这里可不是一般人可以进来的, 若非杨书文的允许, 想看一看都不行
。入口处挂着一幅卷轴(paper)。

LONG);
  set("item_desc",([
  "paper"	:"请键入 <verify> 以得到自己的秘笈。\n",
  ]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"SCH",
]));
  set("no_fight", 1);
  set("light_up", 1);
  set("no_magic", 1);

  setup();
}

void init()
{
	add_action("do_verify","verify");
}
int do_verify(string str)
{
	object me=this_player(),book;
	if( me->query("class") != "scholar" )
	  return notify_fail("本指令对非书生公会会员无效。");
    book=present("secret_book",me);
	me->set_temp("aa",book);
	while( book )
	{
	  destruct(book);
    book=present("secret_book",me);
	}
    book=new("/data/autoload/scholar/secret_book.c");
	book->move(me);
	message_vision("$N从书架上抽出自己的武功秘笈。\n",me);
	return 1;
}
