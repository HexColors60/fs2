// open/killer/ninja/find/r8a.c
#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "����̽��");
  set ("long", @LONG
  ��Ȼ�Է���һ��ѣ����ǱϾ������ڰ�ɱ�ֺ���Ҫ�������˻�����
  ���Բ��������Է������������ȡ��ս�پ���̬��......
  �������ﲢ�ǲ���ԭʼ���������磬����û�и��ܵ����������
  �㽫���еİ����ս�����ע��ħ��ɱ������ʹ������©�����ⱻ���ֲ�֪
  ���Է�̤����������ʱ�����еİ�������֪̽�ַ����Ķ���
  һ������ע��ħ���İ��������ɹ�Ӱ����Է������ڣ����ұ�������
  ���еĶ��ָ�����������Ӧ�����Ѿ�һһ����.........
  ����һ��ħ��ɱ���벻����û����.�����񹦵��ƶ��£�����������ħ��ɱ���֡�
  ԭ�������Ѿ�����˹����������������ǲ��������й���
  ���������ٶ���Ϊûѧ����.�����񹦣����޷�����ħ��ɱ�����Ȼ�ü򻯰�ĺ����񹦣�
    ��ϰ����ڻ꽫ħ����������ȡ��ħ��ɱ��׷��Ч���������ҿ��Ը����㣬
    �����㽫��������Ϊ�޷������ھ�����ʹ��ħѪ��ɱʱ�����ܾ��ˡ�
    ������ħ��ɱ�����������񹦣����ھ�����������ʹ���ڰ����ַ����档��
  ��������������һ��ħ��ɱ����Ȼ�������������ļ��⣬����������������
  
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "׷��" : "����Ĺ�ȥ....����Ҫ�Լ�ȥ̽��\n",
  "���" : "����Ĺ�ȥ....����Ҫ�Լ�ȥ̽��\n",]));
   //�е����Ƿ�����һҳ��������������ȷ��
  set("exits", ([ /* sizeof() == 1   */
     "׷��" : __DIR__"r11a.c",   
     "���" : __DIR__"r11a.c",   ]));
  set("no_transmit",2);
  setup();
}