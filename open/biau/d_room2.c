// Room: /u/o/onion/room/d_room2.c

inherit ROOM;

void create()
{
	set("short", "�뷿");
	set("long", @LONG
��������Զ���Ķ���Ů--��������ס�Ĺ뷿,��������˴���,��������,���г�
��������,�����Կ����ֵ��ϵ�������������.���Ӷ�������ȥ�������гǽ���ľ�ɫ,
��ľ����,����ɭɭ,ɽ��һ��,է��֮�·羰�����Ƿ�.
    ���ŵ�����Ʈ��һ������,����Ŀ���ȥ,�ŷ��ֵ������������ڴ�����˼,������
�ĵ����ƺ��Ӷ�����.

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"d_room1",
	]));
	set("objects",(["/u/o/onion/npc/lady.c" : 1]));

	setup();
}