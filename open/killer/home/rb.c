inherit ROOM;
void create()
{
  set ("short", "密室");
  set ("long", @LONG
这是东瀛机关圣手--诸冈渡，所建造的伟大密道。
这是因为有许多的门派令人看守大门,使得杀手们无法顺利进行暗杀行动。
以至于当年黑牙连第一代掌门人叶孤城，远赴东洋聘请诸冈渡。
并且于富士山上，取得了富士山密草。据说在总坛的某处有密草的存在。
小渡率领杀手们费了几十年,来建造这个密道,
如今此密道已成,但你却不知道他是要通往那里!!
LONG);
   set("exits", ([
   "east"   : __DIR__"rbe.c",
   "west"   : __DIR__"rbw.c",
   "south"  : __DIR__"rbs.c",
   "north"  : __DIR__"rbn.c",
   "down"   : __DIR__"rbd.c",
  ]));
   set("no_fight", 1);
  set("no_magic", 1);
  set("no_transmit", 2);
  set("light_up", 1);
  setup();
} 
