inherit ROOM;

#define WADE_HOME "/u/w/wade/workroom"

void create ()
{
  set ("short", "LPC 讲座 -- 对应 -- 续");
  set ("long", @LONG
mapping 跟 array 实在是很重要的资料型态, 最好的例子是在 /feature/dbase.c
不过一般人看不到, 可以 more ~wade/dbase.c 看看.
在此先不多说, 请自行揣摹.
LONG);

  set("exits", ([
	"back"	:	__DIR__"lpc",
  ]) );

  setup();
}
