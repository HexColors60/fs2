// by roger && taifar
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short","曲径芙蓉");
set ("long", @LONG
一路，绿玉围径红石作踩，有阔叶芭蕉，大株翠梨，桑榆槿桦，各
色树稚新条，随其曲折，编就成两溜青蓠，蓠外小丘之下还有桔樨
辘轳之属，分畦列亩，佳蔬菜花一望无际，从凄沚分留而来的细细
沟尺盘旋错过。
沿着凄沚之水而行，又见一带清流从花木深处泻于石隙之下，转过
山坡穿花度柳，扶出薜荔萝藤，更有樱穗遮天，实若丹彤，花若金
桂，忽迎面突出插天的大玲珑山石来，四方寻绕各式石样，导入蔷
薇院水仙坞里又是一天外天。
LONG);



  set("exits", ([
            "south"  : __DIR__"91",
            "north"  : __DIR__"86",
                ]));
  set("objects", ([ 
  __DIR__"npc/music-bird" : 2,
                  ]));
        setup();
}
