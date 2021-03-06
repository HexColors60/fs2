#include <ansi.h>

inherit ITEM;
//inherit F_LIQUID;

int extra_func();
int drink_func();

void create()
{
        set_name(HIC"千年冰"NOR, ({ "thousand year's ice","ice" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
                set( "long", "一个取自于邪灵界琰扬湖最底极寒之处的冰块，十分解渴。\n" );
                set( "unit", "个" );
                set( "value", 20000 );
                set( "饱和", 30 );
        }
        set("液体", ([
                "种类"          : "茶",
                "名称"          : HIW"琰扬湖水"NOR,
                "剩"            : 3,
                "止渴"          : 300,
                "饮用讯息"      : (: drink_func :),
                "额外函数"      : (: extra_func :)
        ]) );
        setup();
}

int extra_func()
{
        if( !query("液体/剩") )
	{
                write( HIW"千年冰已经被你的内力给融化掉了。\n"NOR );
                destruct( this_object() );
                return 1;
        }
        return 0;
}

int drink_func()
{
        object me = this_player();
        message_vision( HIC"$N轻运内力，以气力之热溶化千年冰，并吸吮其融化之水。\n"NOR, me );
	me->add("force",-100);
	me->add("food",-300);
        return 1;
}
