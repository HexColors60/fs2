// open/killer/ninja/find/rx19.c
// ����ҷ���������󣬾ͻ��ܵ����ؾ����˺����˻������
#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "����̽��");
  set ("long", @LONG
  
  ��ʱ���߸�����ʱ�����û��ǲ������л���������Χ����Ӱ֮�����û�˷��֡�
  ���������ʵ��̫�����ˣ���벶������ȸ�ں�
  һ�������������ؿڣ���ľ����ܵ����صĴ��!!
  ���㾫���ɢǰ�����뵽��ǰ�������ж�ѵ�������ᵽ��ע������
  ��һ���������˵Ķ�����Ǳ�е��У��ض��������Ե�һ��Ŀ��
    �ڶ��������֮�ڣ�������һ������Ա�����з�����
    ���һ���������Ա�����鷴��������.....��
  ��....������׳��Ŭ�����ϴ�ͽ�˱�...........
   
LONG);
  set("no_transmit",2);
  setup();
}

void init()
{
    object ob=this_player();
    if( interactive(ob))
	    remove_call_out("greeting");
  call_out("greeting",3 , ob);   
}

void greeting(object ob)
{
   if( ob->query_temp("firstpart")== 8)    
   {
     ob->set_temp("firstpart",7);
     ob->set("sen",1);
     ob->set("gin",1);
     tell_object(ob," ��е������𽥻�ɢ....���������״̬..... \n");
     ob->move("/open/killer/room/pillrm.c");
    }
    // �������Ǻܲ����������͵�����ʦ�����ã�һ�������
    else 
     ob->move(__DIR__"r1.c");
}
