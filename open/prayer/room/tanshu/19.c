// Room: /open/prayer/room/tanshu/19.c

inherit ROOM;

void create()
{
	set("short", "茅厕");
	set("long", @LONG

    呜～好臭！一进来就闻到了米田共的味道，这边是茅厕，坑坑洞
洞的，连个门也没有，本门的弟兄如果有人犯错，通常会被门主罚来
这里扫茅厕，如果没事不要待在这里，以免被误会在这做坏事！         

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"18.c",
]));
	set("no_clean_up", 0);

	setup();
	}
