inherit ROOM;
void create() {
	set( "short", "$HIR$����$NOR$��" );
	set( "build", 11508 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room27",
	]) );
	set( "long", @LONG

���Ŵ�Ҷ��������½̸�....
��ͷ������ݵ���������������С��..
������似�����㹦�򿰳�����֮��...
��ʵ....
���Ķ㹦��������...
��ȫ�ǿ�������Ԫ����...
������������� : Ϊ�κ�����Ԫ���������Ч??
��������ѧ���˾�֪����...����ȫ��ʳ��������..
��Ϊ..������Сǿ...��Сǿ�����;��������޵�������������...
�������ǳ��˺�����Ԫ��...���ܽŵ�Ĩ��...
���������������ȥ...
���а��Ĺ���Ͷ���ֻ���������ǵ�ƨ��ë��..wahaha!!

LONG);
	setup();
	replace_program(ROOM);
}