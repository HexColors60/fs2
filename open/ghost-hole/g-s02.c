inherit ROOM;
#include <ansi.h>
void create ()
{
set("short",YEL"˫ڤ��̨"NOR);
set("long",@LONG
�����ǡ�����ڤ���ļ�̨, ������ǰ��һ��
СС��ʯ��(stone),����֮��, ���滹��������
���������ֵֹĹ���, �������ܶ��Ǽ����õ�
���ߡ�
LONG);
set("item_desc",([
"stone":"���ķ���(g-sac)��ڤ��֮ͷ�ߣ����˽��ԡ�����֮ˮ����Ϊл��\n",
"ʯ��":"���ķ���(g-sac)��ڤ��֮ͷ�ߣ����˽��ԡ�����֮ˮ����Ϊл��\n",
]));
set("no_light",1);
set("exits",([
"west":__DIR__"g-s01",
]));
set("no_transmit",1);
setup();
}

void init()
{
add_action("do_gsac","g-sac");
}

int do_gsac(string arg)
{
object ob,ob2,me;
me=this_player();
ob=present("death-ghost-head",me);
ob2=new(__DIR__"obj/living-water");
if(!arg)
return notify_fail("��Ҫ����ʲô����??\n");
if(arg!="death-ghost-head"&&arg!="head")
return notify_fail("������̨���������������׵���Ʒ!!\n");
if(!present("death-ghost-head",me))
return notify_fail("�����ϲ�û����ڤ����ͷ!!\n");
destruct(ob);
message_vision(HIY"һ����ɫ�Ĺ�â�������, �����л���������һ��
����֮ˮ, �պ�����$N������!!\n"NOR,me);
ob2->move(me);
tell_object(me,HIY"��õ���һ������֮ˮ\n"NOR);
me->set_temp("ghost-hole/sac/death",1);
return 1;
}
