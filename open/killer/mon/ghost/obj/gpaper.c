// gpaper.c

inherit ITEM;

void create()
{
   set_name("金纸", ({ "gpaper" }) );
   set_weight(20);
   if( clonep() )
      set_default_object(__FILE__);
   else
   {
      set("unit", "叠");
      set("long", "这是用来祭祀鬼神所用的金纸。\n");
      set("value", 100);
   }
}
