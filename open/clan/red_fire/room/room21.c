// Room : /open/clan/red_fire/room/room21.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIM$Ąž$HIW$°ËŘÔŐó $HIM$ŮăˇçšŇĄż$NOR$" );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "light_up", 1 );
	set( "long", @LONG
    


                              $HIY$¨¨¨¨¨¨¨¨ 


                              ¨¨¨¨¨¨¨¨


                              ¨¨¨    ¨¨¨

                                  $HIM$Ůăˇç$HIW$ŘÔŐó$NOR$



LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "northwest" : "/open/clan/red_fire/room/room20.c",
  "south" : "/open/clan/red_fire/room/room22.c",
]) );
	setup();

	}
