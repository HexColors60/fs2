// made by funkcat, copy and re-edit by ccat
inherit BANK;
void create ()
{
  set ("short", "蜀中钱庄");
	set( "build", 6 );
  set ("long", @LONG
这里是蜀中最大的钱庄，也是蜀中富豪林万金的产业，这
里一向以安全，便捷闻名.  一张告示(board)告诉你这里的服
务项目.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/gsword/room/su3",
]));

  set("item_desc", ([ /* sizeof() == 1 */
  "board" : "
    balance: 查看您现有的存款    convert: 换钱币
    withdraw: 提款               deposit: 存款    
    cdonate: 把钱转存至你的帮派之中
 ",
]));
    set("objects", ([
        "/open/gsword/mob/officer" : 1,
       ]) );

  set("light_up", 1);
   set("donate",1);

  setup();
}
