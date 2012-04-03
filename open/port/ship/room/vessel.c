// Room: /open/gblade/port/room/port.c
inherit ROOM;

int time=0;
void create()
{
	set("short","幽冥魔船内");
   set ("long", @LONG
一收阴气森森的魔船 , 坐在上面 , 你感到一股寒气侵体 ,
船首一个人在驶着船 , 从背后看起来 , 到像具骷颅 .

LONG);
   set("light_up", 1);
	set("objects",([
	"/open/gblade/port/npc/vessel_leader":1,
	]));
   set("no_clean_up",1);
  setup();
	set_heart_beat(1);
}

   void arrive_port()
{
	tell_room(this_object(),"枫林港到啰 , 请赶快下(out)船!\n");
	set("exits/out","/open/gblade/port/room/port.c");
	new("/open/gblade/port/npc/vessel1")->move("/open/gblade/port/room/port");
	
}	
  void leave_port()
{
	tell_room(this_object(),"出发啦 , 目的地是冥魔岛 !\n");
	delete("exits/out");

	
}
   void arrive_island()
{
	tell_room(this_object(),"冥魔岛到啰 , 请赶快下(out)船!\n");
	set("exits/out","/open/gblade/port/room/island2.c");
	new("/open/gblade/port/npc/vessel2.c")->move("/open/gblade/port/room/island2");
}	
  void leave_island()
{
	tell_room(this_object(),"出发啦 , 目的地是枫林港 !\n");
	delete("exits/out");

}


  void heart_beat()
{
	
	time++;
	if(time>50)
	time=1;
	if(time==1)
	arrive_port();
	if(time==11)
	leave_port();
	if(time==26)
	arrive_island();
	if(time==36)
	leave_island();
}

	

