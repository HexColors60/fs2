inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIG"����֮ӡ"NOR,({"surname-yin"}));
	set("long","һ��ע����֮��ӡ������ӡ���治ʱ����˸��һ����ֵ���⣬��\n"
		  +"����ε�ϸ�����о���ȴҲ��֪���к����ã�Ҳ���ʹ�˵�е�����\n"
		  +"�ؽ��йء�\n");
	set("unit","��");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set_weight(1000);
        setup();
}