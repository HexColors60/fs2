inherit ROOM;
void create() {
	set( "short", "$HIW$白龙$NOR$区" );
	set( "build", 12068 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room27",
	]) );
	set( "long", @LONG

你想要坚挺吗!? 你想要持久吗!? 
挥别趴趴熊的形象,迈向SUPER MAN的境界,
白龙精元绝对是你最好的选择!! 

让你不再是拿着竹筷捞水桶....
保证另一半天天对你赞口不绝...

你还在犹豫什么,赶快拿起电话订购...
订购专线 : 020479979..
来电前五名附赠七叔牌神油一罐..
让你真正成为一尾活龙!!!

LONG);
	setup();
	replace_program(ROOM);
}
