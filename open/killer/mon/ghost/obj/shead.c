// star head 陈星辉的头

inherit ITEM;

void create()
{
   set_name("陈星辉的头", ({ "star head", "head"}) );
   set_weight(20);
   if( clonep() )
      set_default_object(__FILE__);
   else
   {
      set("unit", "颗");
      set("long", "这是陈星辉的头, 是用来祭祀女鬼用的。\n");
      set("value", 100);
   }
}
