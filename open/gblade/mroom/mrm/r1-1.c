// made by funkcat, copy and re-edit by ccat
inherit BANK;
void create ()
{
  set ("short", "帐房");
  set ("long", @LONG

这里是魔刀门内提存钱款的钱庄，也同计算门内的收入,这
里一向以安全，便捷闻名.一张告示(board)告诉你这里的服
务项目.

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "board" : "
    balance: 查看您现有的存款    convert: 换钱币
    withdraw: 提款               deposit: 存款    
 ",
]));
  set("exits", ([ /* sizeof() == 1 */
"north":__DIR__"r7.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
     "/u/m/moner/npc/officer.c" :1,
]));

  setup();
}
