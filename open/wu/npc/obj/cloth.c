#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
   set_name("习武服",({"gonfu cloth","cloth"}));
       set_weight(250);
	if( clonep() )
		set_default_object(__FILE__);
	else {
          set("unit","件");
          set("value",2000);
		set("material", "cloth");
     set("long","这是一件泷山派武馆弟子专属衣物,似乎有特别的防御力。\n");

             set("armor_prop/armor",2);
               set("armor_prop/dodge",-1);
               set("armor_prop/unarmed",2);
}
	setup();
}
