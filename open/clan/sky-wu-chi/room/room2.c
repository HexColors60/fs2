// Room : /open/clan/sky-wu-chi/room/room2.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
这里是小燕仔所开的钱庄，号称高利率，借贷免
利息，你可以看到钱庄里里外外都打扫得干干净净，
这可发现老板的爱好清洁，显得每个人都来这里存你
所辛辛苦苦赚来的钱，都存在这里。只要打下几个小
小的指令(cdonate),就能让这个小小的帮派能够有资
金做更大的发展喔。

LONG);
	set( "exits", ([ /* sizeof() == 1 */
		"east"      : "/open/clan/sky-wu-chi/room/room5.c",
]) );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "light_up", 1 );
	set( "short", "$HIC$燕仔牌钱庄$NOR$" );
	set( "cmkroom", 1 );
	set( "item_desc", ([ /* sizeof() == 2 */
  "存钱桶" : "",
  "bank" : "",
]) );
	setup();

	}
