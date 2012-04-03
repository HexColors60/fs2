inherit ROOM;

int time=0;
void create()
{
   set("short","小木筏");
   set ("long", @LONG
用木材扎起来的筏子 ,古朴的样子令人感到
无比的亲切 ,风大舟轻 ,大概很快就能够到
达想去的地方...

LONG);
   set("light_up", 1);
        set("objects",([
        "/open/island/npc/bman1":1,
        ]));
   set("no_clean_up",1);
  setup();
        set_heart_beat(1);
}

   void arrive_island()
{
        tell_room(this_object(),"神仙岛到啰 , 请赶快下(out)船!\n");
        set("exits/out","/open/island/room/island.c");
        new("/open/island/npc/boat1")->move("/open/island/room/island"); 

}
  void leave_island()
{
        tell_room(this_object(),"要驶回东津港了 !\n");
        delete("exits/out");


}
   void arrive_port2()
{
        tell_room(this_object(),"东津港到了 , 要下(out)船的请快!\n");
        set("exits/out","/open/island/room/port2.c");
        new("/open/island/npc/boat2")->move("/open/island/room/port2");
}
  void leave_port2()
{
        tell_room(this_object(),"海外之旅开始啰 !\n");
        delete("exits/out");

}


  void heart_beat()
{

        time++;
        if(time>90)
// 90 为周期 , 要更密集就调低一点 
        time=1;
        if(time==1)
        arrive_island();
        if(time==11)
        leave_island();
        if(time==31)
        arrive_port2();
        if(time==41)
        leave_port2();
}




