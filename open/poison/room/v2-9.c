// Room: /u/r/ranko/room/v2.c
inherit ROOM;

void create ()
{
  set ("short", "隔世村中");
  set ("long", @LONG
你正踏在隔世村的路上，村里的村民不时投以好奇的眼光，似
乎对于外来的访客并不太适应。两旁是供给村民居住的寻常农舍，
往远方望去则可看到一片片绿油油的稻田及临近的晒谷场。村中亦
有些许店铺供村民购买日常所需，你若有需要的话，不妨去那儿看
看。
LONG);

  set("light_up", 1);
  set("outdoors", "/u/r/ranko/room");

  setup();
}
