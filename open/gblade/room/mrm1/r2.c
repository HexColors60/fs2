// Room: /u/m/moner/water/r7.c
inherit ROOM;

void create ()
{
  set ("short", "�㳡");
  set ("long", @LONG

    ������ħ���ŵĹ㳡����ħ�������ټ���ͽ���������գ�������
�ǳ�ʱ�̵���Ҫ�ط����㳡���ϡ����������죬����������������ǧ
�ˡ�

LONG);

  set("light_up", 1);
  set("outdoors", "wind");
  set("exits", ([ /* sizeof() == 1 */
"east":"/open/gblade/mroom/mrm/r7.c",
]));
        set("objects",([
"/open/gblade/npc/man.c":3,
]));
  setup();
}