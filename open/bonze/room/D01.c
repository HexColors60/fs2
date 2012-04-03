// Room: /open/soulin/room/D01.c

inherit ROOM;

void create ()
{
  set ("short", "寺门");
  set ("long", @LONG
	雄伟壮阔的寺门，显示了少林寺数百年来屹立不倒
	的大家风范，在武林中说到少林寺莫不人人翘指称
	赞，是故有人传称少林武功乃武林之首，由其数百□	年来屹立不倒的气势看来也颇有几分可信度。


LONG);

  set("objects", ([ /* sizeof() == 1 */
"/open/bonze/npc/konwun":1,
]));
  set("outdoors", "/open/soulin");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r8",
  "enter" : __DIR__"s02",
]));

  setup();
}
int valid_leave(object who, string dir)
{
  if( present("kon wun", this_object()) ) {
if(who->query("bellicosity") > 700 && who->query("id")!="swordsman") {
        return notify_fail("空闻弯腰合十对你微笑道: 少林寺为佛门净地，施主杀孽之气太重，还请留步。\n");
   }
  }
 
  return ::valid_leave(who, dir);
}
