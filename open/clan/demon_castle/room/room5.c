// Room : /open/clan/demon_castle/room/room5.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "short", "魔˙血池林" );
	set( "light_up", 1 );
	set( "build", 7150 );
	set( "clan_room", "恶魔城" );
	set( "exits", ([ /* sizeof() == 6 */
  "north" : "/open/clan/demon_castle/room/room6.c",
  "south" : "/open/clan/demon_castle/room/room7.c",
  "down" : "/open/clan/demon_castle/room/hall",
  "west" : "/open/clan/demon_castle/room/room9.c",
  "up" : "/open/clan/demon_castle/room/room10.c",
  "east" : "/open/clan/demon_castle/room/room8.c",
]) );
	set( "long", @LONG

    [1m[37m这里是[31m恶魔城[37m内的[35m血池[36m林[37m，亦是武林老一辈人口中的[33m江湖禁地[37m，[0m
[1m[37m相传在数十年前武林中出现了一位武功极为高强的[32m御剑[34m飞龙[36m傅剑寒[37m，[0m
[1m[37m统领着[32m二尊者[33m、[36m四霸王[33m、[31m八魔使[37m为了理想而战遍大江南北未逢敌手，[0m
[1m[37m数年前成立[31m恶魔城[37m后[31m大恶魔[36m傅剑寒[37m便率领其下隐居于此，专心的修练[0m
[1m[37m武学之[32m最高境界[37m，岂知近年内武林中纷乱不休，群强争霸，而隐居于[0m
[1m[35m血池[36m林[37m内的众高手是否会因此而再度踏上[31m血腥之路[37m。[0m

LONG);
	setup();

	}
