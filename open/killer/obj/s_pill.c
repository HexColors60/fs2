inherit COMBINED_ITEM;
void create()
{
        set_name("杀手密药", ({"killer pill","pill"}) );
set("long",
"此物乃天才机关手诸冈渡自富士山密洞采来之密药,可以恢复灵力.\n"+
"需经过叶秀杀认可才可以食用(eat pill).
  如果不是杀手食用了会有严重的后果\n");
        set("unit", "盒");
        set("base_unit", "粒");
        set("no_sell",1);
        set("value",0);
        set("base_weight", 10);
set_amount(1);
setup();
}

void init()
{
  if( this_player()==environment() )
  {
    add_action("eat_pill", "eat");
  }
}

int eat_pill(string arg)
{      

   object ob,me=this_player();
   int max_atman,atman;

   if( !arg )                      return 0;
   arg=lower_case(arg);
   if( !ob = present(arg,me) )     return 0;
   if( ob != this_object() )       return 0;
   if (me->query("class") != "killer")
   {
     atman=me->query("kee");
     atman= atman/2;
     me->add("kee",-atman);
tell_object(me,"你吃下之后感到一阵不适  难道是中毒了!!!\n");
     ob->amount(-1);
     return 0;
   }
   message_vision("$N吃下一粒杀手密药.\n", me);
   max_atman = me->query("max_atman");
   me->set("atman",max_atman);
   ob->amount(-1);
   return 1;
}
