inherit ROOM;

void create ()
{
  set ("short", "泻玉亭");
  set ("long", @LONG

进入此处，只见佳木成荫，奇花烂漫，一湾清流，从奇花深处泻于石隙之
下。清溪泻玉，石磴穿云；白石为栏，环抱池沼。溪上有桥，桥上有亭，
亭上有一赤金九龙青地大匾（sign）。

LONG);
 set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "

只见上面写着

                  亭   玉   泻  

            隔                     绕
            岸                     隄
            花                     柳
            分                     借
            一                     三
       王   脉                     篙
       元   泉                     翠
       霸
       题
 
没想到王元霸除了在武功尚有惊人的造诣之外，文学上的成就
也是不凡。\n",

]));

   set("light_up", 1);
set("outdoors", "/open/gblade" );
   set("exits", ([ /* sizeof() == 3 */
"east" : __DIR__"g2-2.c",
"north" : __DIR__"g2-5.c",
"west" : __DIR__"g2-4.c",
]));

  setup();
}

