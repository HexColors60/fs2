inherit ITEM;
void create ()
{
set_name("鲁仝的护身符",({"luton's amulet","amulet"}));
set_weight(10);
    if(clonep())
        set_default_object(__FILE__);
    else{
        set("long","这是一个极为普通的护身符，鲁仝交给你的唯一线索。\n");
	set("value",1);
	set("unit","个");
	setup();
}}
