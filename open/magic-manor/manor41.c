#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "����");
	set ("long", @LONG
�߽�����������������ſ���ͨ�����䲻ͬ���᷿�������ϲ�
�ü򵥲�û��ʲô̫���۵İ��裬���롢�������ǰΨһ��д�ա�
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor44",
	"south"	: __DIR__"manor42",
	"east"	: __DIR__"manor43",
	"west"	: __DIR__"manor67",
	]));

	set("light_up", 1);

	setup();
}