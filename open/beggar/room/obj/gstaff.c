#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
 set_name(HIG"�����"NOR,({"green staff","staff"}));
 set_weight(100);
 init_staff(95);
 if( clonep() )
  set_default_object(__FILE__);
 else
 {
  set("unit","��");
  set("long","��������ؤ�������֤�����ֻҪ˭�ܶ�ô˹������ܺ���ؤ������������ʮ�����ڡ�\n");
  set("value",23483);
  set("material","steal");
 }
 setup();
}
