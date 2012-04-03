inherit ROOM;

int time=0;
void create()
{
   set("short","弯月舫");
   set ("long", @LONG
雕饰着云女玩月图的弯月舫, 船体是由千年神木所輮制而成,
是当今京城首富赠与双月姊妹的礼物, 只为能够欣赏一次她们媲美
天仙的技艺. 姊妹偶尔会乘着弯月舫游湖赏景, 但通常都是让弟子
们外出购物用.

LONG);
   set("light_up", 1);
	set("objects",([
	"/open/dancer/npc/ship_girl":1,
	"/open/tensan/linjoy/npc/linlin":1,
	]));
   set("no_clean_up",1);
   set("no_transmit", 1);
  setup();
	set_heart_beat(1);
}

   void arrive_port()
{
	tell_room(this_object(),"镜月岛到啰 , 请赶快下(out)船!\n");
	set("exits/out","/open/dancer/room/port.c");
	new("/open/dancer/npc/ship1")->move("/open/dancer/room/port"); 
	
}	
  void leave_port()
{
	tell_room(this_object(),"本船即将驶往枫林港 !\n");
	delete("exits/out");

	
}
   void arrive_fonport()
{
	tell_room(this_object(),"枫林港到了 , 要下(out)船的请快!\n");
	set("exits/out","/open/dancer/room/fonport.c");
        new("/open/dancer/npc/ship2")->move("/open/dancer/room/fonport");
}	
  void leave_fonport()
{
	tell_room(this_object(),"镜月岛之旅开始啰 !\n");
	delete("exits/out");

}


  void heart_beat()
{
	
	time++;
	if(time>60)
// 60 为周期 , 要更密集就调低一点 
	time=1;
	if(time==1)
	arrive_port();
	if(time==11)
	leave_port();
	if(time==31)
	arrive_fonport();
	if(time==41)
	leave_fonport();
}

	

