// made by funkcat, copy and re-edit by WATARU
inherit BANK;
void create ()
{
set("short","杀手钱庄");
  set ("long", @LONG
这里是杀手总坛的钱庄,这边的存款额在全国是排行第一名,或许是杀手的赚钱方式不同
你可以安心的将钱存在这里 . 这家钱庄的老板是大财主诸冈渡，他是叶秀杀的客座军师，
因此有不少人传闻，这里也是杀手支领完成任务的酬金处。
但是没人能够证实，因为暗杀工作没人愿意承认。
可以看看这儿的公告(board),看看有甚么服务.

LONG);

  set("exits", ([ /* sizeof() == 1 */
"east" : __DIR__"ru1.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "board" : "
    balance: 查看您现有的存款    convert: 换钱币
    withdraw: 提款               deposit: 存款    
 ",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
      "/open/killer/npc/wantman.c":1,
]));

  setup();
}
