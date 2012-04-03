inherit ITEM;
void create ()
{
set_name("护身符",({"amulet"}));
set_weight(10);
    if(clonep())
        set_default_object(__FILE__);
    else{
        set("long","这是一个极为普通的护身符，与鲁仝交给我们的护身符相似，你可以调查(examine)看看。\n");
        set("value",1);
        set("unit","个");
        setup();
}}
void init()
{
add_action("do_ex","examine");
}
int do_ex(string arg)
{
object me;
me=this_player();
if(!arg||(arg!="amulet"))
return notify_fail("你要调查什么？\n");
if(me->query_temp("get_amulet")!=1)
return notify_fail("这护身符虽然外观已经损毁，但是在背面却有‘鲁仝’两个字，看来刚刚
那具尸体就是石田丽子。\n");
else {
tell_object(me,"这护身符虽然外观已经损毁，但是在背面却有‘鲁仝’两个字。\n");
message_vision("$N脸上露出十分讶异的表情。\n",me);
message_vision("$N倒退了几步，不小心掉入了底板之下。\n",me);
me->move("/open/killer/island/b_q01");
me->set_temp("get_amulet",2);
me->set_temp("move_out",1);
return 1;
}
}
