inherit ROOM;
void create() {
	set( "short", "$HIW$长庚医院$HIY$X皮$HIR$收藏室$NOR$" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/hell/room/room42",
	]) );
	set( "long", @LONG

水公月老医师因为年事已高,再加上有时外务缠身....
比如说送送宵夜..打打电话...看看Z频道...
身为水月老医师爱徒的小牙签终结者...再也不好意思让师父如此奔波..
所以他发挥长□.在此开设一家专割X皮的诊疗室..
当然使男性恢复雄风...也是小牙签终结者的拿手绝活...
如果你想要跟你的小牙签说BYE BYE,或是想每晚一柱擎天的话...
记得来找怪医小牙签终结者喔.....

 救命专线 : 79979!! 并请告诉小牙签终结者你的症状...

      (症状1)被吸干 : tell nirvana heal代号gin
    (症状2)老垂已已 : tell nirvana heal代号kee
      (症状3)小牙签 : tell nirvana heal代号sen
       (症状4)X冷感 : tell nirvana deffire 
(症状5)手断脚痛青瞑 : tell nirvana heal代号ack

           如忙线...请稍后再拨.......
LONG);
	setup();
	replace_program(ROOM);
}
