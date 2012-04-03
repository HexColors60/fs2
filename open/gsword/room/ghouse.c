// Room: /open/su/room/suroad9_1.c

inherit ROOM;

void create ()
{
  set ("short", "仙剑派大殿");
  set ("long", @LONG
	
这是仙剑派的大殿,殿中数位剑士恭谨的站在两侧,看看这的成设
,全以紫檀木造成，少了一种壮丽,却多一分莫名的英气。唯一令你
不解是大殿掌门人的位置上，却不见掌门人--李逍遥，坐在其上。
，看来想拜师的话只好问问左右的剑士们了。         

LONG);

  set("light_up",1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/gsword/room/north",
  "out" : "/open/gsword/room/test.c",
]));

  set("objects", ([ /* sizeof() == 2 */
  "/open/gsword/mob/swordsman" : 2,
  "/open/gsword/mob/chenfon.c" : 1,
]));

  setup();
}
