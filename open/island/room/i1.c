inherit ROOM;

void create()
{  
   
   set("short","神仙岛上");
   set ("long", @LONG
在你眼前的是一望无际的沙滩，深蓝色天空横过
一道七彩的虹，四周的景色均是中原所难见到，地上
尽是奇花异草，在白色的莹莹沙粒中显得格外的艳丽
芬芳，东边是一片草原．                     
LONG);
   set("light_up", 1);
        set_heart_beat(1);
 set("exits", ([ /* sizeof() == 4 */

   "west" : "/open/island/room/island",
    "east" : "/open/island/room/i3",
  "south" : "/open/island/room/i5",
]));
   set("outdoors", "/open/main");

 setup();
}


