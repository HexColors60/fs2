// made by funkcat, copy and re-edit by ccat
inherit BANK;
void create ()
{
  set ("short", "京城干记钱庄");
  set ("long", @LONG
大门闪闪发光，原来这钱庄的大门竟是用黄金铸的。不禁佩服干通
天干老爷的富可敌国。这里是干通天的产业之一，是干通天所有事业的
资金来源。由于全国钱庄有协定在，因此您的存款可以在各钱庄之间互
相流通。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"h09.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "board" : "
    balance: 查看您现有的存款    convert: 换钱币
    withdraw: 提款               deposit: 存款    
 ",
]));
  set("light_up", 1);

  setup();
}
