inherit ROOM;
void create() {
	set( "short", "   $HIR$�����ǰһ�ڣ�����ʲôҲ��֪����....$NOR$" );
	set( "light_up", 1 );
	set( "build", 28 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room55.c",
	]) );
	set( "long", @LONG

�����ˡ�

[31m�������[0m - 
    ���Ѿ��������������ڡ���Ȼ����ظ�����һ�ξ��룬�������Ѿ�
���ܵ�����̹ǵ����硣����һƬ����������ȴ��Ӱ������������ߵ�ҹ
�ܻ������ֵģ�Ӧ�ò���û�顣�ϱߺ���������Ǻ���������ͨ�Ĺܵ���
����������һ�����ε�����������������ͬ�����磬����Ҫ������������
��ȥ������ô�򵥵����顣
    
LONG);
	setup();
	replace_program(ROOM);
}