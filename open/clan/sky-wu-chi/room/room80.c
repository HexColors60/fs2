inherit ROOM;
void create() {
	set( "short", "$HIR$妖刀$HIG$正宗$HIB$□冢$NOR$" );
	set( "object", ([
		"amount6"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
	]) );
	set( "owner", "hild" );
	set( "build", 10004 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room73",
	]) );
	set( "long", @LONG
就是冈崎五郎入道正宗所作之刀，正宗为正剑的代表，后来更成为
权力授与的印信，大名将一国赐与重臣管理时，往往会赠予名刀作为象
征品，因此当大名给予重臣正宗刀，往往是代表授与一国国主的无上光
荣，关之原大战后，石田三成被田中吉政所捉，后来面临死刑的命运，
临死前缴回两把正宗刀，除了证明自己曾受太阁重用之外，也是对家康
的无言抗议。 

LONG);
	setup();
	replace_program(ROOM);
}
