inherit ROOM;

#define WADE_HOME "/u/w/wade/workroom"

void create ()
{
  set ("short", "LPC 讲座 -- 资料型态");
  set ("long", @LONG
在 LPC 里, 支援下列的资料型态,
	int	整数状态, 这个型态的值的范围跟机器有关
	float	浮点数, 非常不常用, 也没什么必要
	string	字串
	array	阵列
	mapping	对应(阵列)
	object	物件

    基本上来说, float 几乎用不到, 其它值请到各房间去看,
在此先说明一件事: 所有型态的变数都有一个 "零" 值, 如 :
  int 是 0, 字串是 "", 阵列是  ({ }), 对应是 ([ ]), 物
件是 0. 进一步的 LPC 说明请往东走.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "back"	: WADE_HOME,
  "int"		: __DIR__"LPC_int",
  "string"	: __DIR__"LPC_string",
  "array"	: __DIR__"LPC_array",
  "mapping"	: __DIR__"LPC_mapping",
  "object"	: __DIR__"LPC_object",
]));

  setup();
}
