inherit ROOM;

void create()
{
	set("short","蛇寨");
	set("long",@LONG
这里有一扇门，门扇两旁分别雕饰着一条蛇，蛇身上有着一些你
无法理解的文字与图形。
LONG);
	set("item_desc",([
"door":"门中央有着一个蛇型的标志。\n",
"门":"门中央有着一个蛇型的标志。\n",
"蛇型":"它是一个蛇型的凹槽，似乎可以放置什么东西...\n",
"标志":"它是一个蛇型的凹槽，似乎可以放置什么东西...\n",
]));
	set("objects",([
__DIR__"npc/snake_soldier":2,
]));
	set("exits",([
"west":__DIR__"r-11",
"east":__DIR__"r-09",
"south":__DIR__"r-03",
]));
	setup();
}

void init()
{
add_action("do_put","put");
}

int do_put(string arg)
{
object me,ob;

	me = this_player();

	if( !arg )
		return 0;
	if( arg != "snake statue" && arg !="statue" )
		return 0;
	if( !present("snake-key-1",me) )
		return notify_fail("你怎么摆\都无法将东西摆\入凹槽内，似乎不合。\n");

	message_vision("$N将蛇型雕像摆\入了凹槽内～\n",me);
	call_out("door",3,me);
	destruct(present("snake-key-1",me));
return 1;
}

int door(object me)
{
object ob = this_object();

	message_vision("大门缓缓的打开～\n",me);
	set("exits/north",__DIR__"r-05");
return 1;
}

int valid_leave(object me,string dir)
{
	if( present("snake-soldier",environment(me)) )
	{
		message_vision("守卫大喝：兄弟们～别让"+me->name(1)+"跑了～\n",me);
		return notify_fail("你的退路已经被挡住了。\n");
	}
	if( dir == "north" )
	{
		message_vision("$N一走过门槛，大门又随即关上。\n",me);
		delete("exits/north");
	}
return 1;
}