// Room: /open/death/bridge2.c

inherit ROOM;

void create ()
{
  set ("short", "奈何桥上");
  set ("long", @LONG
著名的奈何桥，奈何桥上三声无奈，早知如此，何必当初，善有善报
，恶有恶报，再往前头去就进了地府了．你突然想起一生的杀戮，不禁一
身冷汗直流，难道真的报应临头了吗！？随着鬼门关的逼近，心里越来越
恐惧，没想到叱吒江湖多年的你也会有报应的一天，听说一过奈何桥就回
不去了，真的无路可逃了吗！？往桥下看去，乌黑的水流中带着些许的腥
味，恐怕没有人敢跳下去吧！？
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bridge1",
  "north" : __DIR__"bridge3",
]));
  set("no_auc",1);
  set("item_desc", ([ /* sizeof() == 1 */
  "water" : "好黑的水喔！！为什么有腥味！？哇！！原来是血水！！
",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/ghost1" : 1,
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_transmit", 2);

  setup();
}

int valid_leave(mixed me, string dir)
{
	if(me->query_temp("ask") > 5)
		return notify_fail("你还没赌完，不可以走开！！\n");
	me->delete_temp("ask");
	return 1;
}

