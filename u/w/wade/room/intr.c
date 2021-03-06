inherit ROOM;

void create ()
{
  set ("short", "LPC 说明之 简介");
  set("long", @LONG
本系列的 LPC 说明做了底下的基本假设:
你已经学会某些基本的 UNIX 命令, 如: ls, cd, mkdir, mv, rm, 等等, 以及
你知道怎么使用 edit 编辑档案. 假如你知道 C, 那你会发现 LPC 很像 C, 但
是又不是 C. 如果你已经有模组化程式设计概念的话, 也许反而会造成你写 LPC
 程式的一种阻碍, 你必须克服这种阻碍. 如果你从未听过写过 C 程式语言(像
我在 1991 年五月时一样), 那么你只是有一些简单的东西不会, 如流程控制,
逻辑指令的操作, 说穿了, 对 C 语言的了解并没有很大助益(反而有阻力), 因
为一般 C 对 LPC 有用的地方满容易从头学起的.. 对于新手, 奉劝你照顺序读
本手册. 每章的开头会有简短的说明, 之后会介绍该章的顺序, 再来才是该章的
正题. 每节的最后会有简短的本章摘要说明, 通常都是那些希望你知道的事项.
    假如你读了某一章, 确定你从头到尾都读过却还是不懂的话, 可以寄信给我.
因为, 很明显的, 我在那一章有了败笔, 所以我也希望能订正过来. 同样的,
章末的摘要如果发生类似情形也请寄信给我. 假如你的 mud 是架在 LP mud 上,
可以寄到 descartes@nightmare, 否则请寄到 borg@hebron.connected.com.
LONG);

  set("exits", ([
	"mudlib": __DIR__"mudlib",
	"driver": __DIR__"driver",
	"area"	: __DIR__"area",
	"object": __DIR__"object",
	"back"	: "/u/w/wade/workroom",
  ]) );
  setup();
}
