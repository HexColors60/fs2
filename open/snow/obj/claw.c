// claw.c
#include <weapon.h>
inherit UNARMED;
void create()
{
        seteuid(getuid());
        set_name("��צ" ,({"claw"}));
        set_weight(1000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","����ѩ�Ե�����ϰ��֮������\n");
        set("value",1000);
        set("material", "steel");
        }
        init_unarmed(10);
        setup();
}
