inherit ROOM;

void create ()
{
  set ("short", "�������");
  set ("long", @LONG
�����������߾��������µĴ��۱�����,��Զ�����������۱����
��ʮ��ׯ����ΰ,Ȼ�������ŷ����������ǵ�̵÷ǳ�ϸ��,���˵��
���������еļ�Ʒ��
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"aa35",
  "south" : __DIR__"aa31",
]));
}