
inherit ROOM;
void create()
{
  set ("short", "战备池");
  set ("long","
    这里的水好像特别干净，不像之前的水那么脏，在天
花板上还开有一个通气孔来排出水气，而这里的水好像都
自山上，水的味道有一种特别的味道，该不会是珍的偷接
山上的水来用。

 ");
   set("exits", ([
   "east"   : __DIR__"r30.c",
      
  ]));      
  set("light_up", 1);
  setup();
} 

