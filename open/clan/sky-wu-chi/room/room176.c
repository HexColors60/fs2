inherit ROOM;
void create() {
	set( "short", "小志的房间" );
	set( "object", ([
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"amount1"  : 1,
	]) );
	set( "owner", "biwem" );
	set( "build", 10026 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room357",
		"north"     : "/open/clan/sky-wu-chi/room/room210.c",
		"up"        : "/open/clan/sky-wu-chi/room/room175.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
      此处到处布满了剑气，在地上充满了剑痕，好像有
  人在这修练了很久的样子，仔细一看原来是天道无极的
             [0;1;5;33m□[1;5mu[1;5m□[1;5mC[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5mv[1;5;36m□[1;5mp[1;5m□[1;5m□[1;5m□[1;5mM[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[0m
  在地上有一块石碑上面写着：
        非请勿入者...只有一条路  
                 [0;1;5;31m□[1;5my[1;5m□[1;5m□[1;5m□[1;5mz[0m
        [0;1;5;36m [1;5m [1;5m [1;5m [1;5m [1;5m [1;5m*[1;5m^[1;5m_[1;5m^[1;5m*[1;5m.[1;5m.[1;5m□[1;5mp[1;5m□[1;5m□[1;5m.[1;5m.[0m

LONG);
	setup();
	replace_program(ROOM);
}
