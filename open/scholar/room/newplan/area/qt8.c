// Room: /u/s/sueplan/newplan/area/qroom2
inherit ROOM;

void create ()
{
  set ("short", "[47;30m������[0m");
  set ("long", @LONG
                    ����    ����

                        ������������

                        ������������

                           �ң���

֪Ϥ̫�������ǣ��������������������ԣ��˰���ʮ�Ļ���
�����й��׾�֮�����ڣ��������Դ˶������������ڱ�
����ǧ����ʹ����ʧ�ڲ��Ծ��䡣
����ǰ�����ٵķ�ɳ, ��ѡ��(move)��Ҫ�ߵķ���
[1;37m������-��, Ԫ, ��, ֧, ����, ��Ԫ, ֧��, ֧Ԫ��[0m
LONG);

  set("no_auc", 1);
  set("no_transmit", 1);

  setup();
}
void init()
{
add_action("do_move","move");
}
int do_move(string str)
{
  object me=this_player();
  if(str=="��")
  {
me->move("/open/scholar/room/newplan/area/qt8.c");
    return 1;
  }
  if(str=="Ԫ")
  {
me->move("/open/scholar/room/newplan/area/qt1.c");
    return 1;
  }
  if(str=="��")
  {
me->move("/open/scholar/room/newplan/area/qt6.c");
    return 1;
  }
  if(str=="֧")
  {
me->move("/open/scholar/room/newplan/area/qt5.c");
    return 1;
  }
  if(str=="����")
  {
me->move("/open/scholar/room/newplan/area/qt4.c");
    return 1;
  }
  if(str=="��Ԫ")
  {
me->move("/open/scholar/room/newplan/area/qt3.c");
    return 1;
  }
  if(str=="֧��")
  {
me->move("/open/scholar/room/newplan/area/qt2.c");
    return 1;
  }
  if(str=="֧Ԫ")
  {
me->move("/open/scholar/room/newplan/area/qt1.c");
    return 1;
  }
}