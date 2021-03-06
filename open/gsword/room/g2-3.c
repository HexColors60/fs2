// Room: /open/gsword/room/gsword3-8.c
inherit ROOM;

void create ()
{
  set ("short", "春秋阁");
  set ("long", @LONG
春秋阁里摆满了桌椅 ,排列整齐 ,数十位新进的剑童正专心的朗颂诗书 ,
跟外面百人练剑的情景相比 ,似乎又是另一个世界 .西首有个小讲台 ,一张古
朴的书桌放置其上 ,应该就是老师授课所在 ,南边一排阳台 ,架在峭壁之巅
弟子们于课余之暇 ,往往喜欢倚着栏竿 ,观赏远方的蜀中城 .

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : "/open/gsword/room/g2-4.c",
]));

  set("objects", ([ /* sizeof() == 2 */
   "/daemon/class/swordsman/sauhu":1,
   "/open/gsword/npc/student":2,
]));

  set("light_up", 1);

  setup();
}
