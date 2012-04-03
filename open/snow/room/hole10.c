#include <room.h>

inherit ROOM;

void create()
{
           set("short","洞穴");
          set("long","洞穴第二层,由于景象都差不多,所以在没有完整的地图概念之前,最好不要误闯此处,旁边有一个似乎是前人用血写下来的告示牌(sign)。\n");

        set("exits", ([
          "west":__DIR__"hole12",
          "east":__DIR__"hole11",
          "north":__DIR__"hole24",
          "south":__DIR__"hole21",
      "down":__DIR__"hole2",
        ]) );
        set("item_desc", ([ /* sizeof() == 1 */
        "sign" : "建议您:如果没有十足的把握的话,最好不要得罪这一楼的mob,我就是死在他们的手上,还有往北,往南的道路有去无回,自己小心!\n"
        ]) );
        setup();
}
