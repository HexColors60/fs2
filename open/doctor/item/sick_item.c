// made by ccat
// 为保障doctor权利..只允许给doctor..check
inherit COMBINED_ITEM;
void create()
{
        seteuid(getuid());
        set_name("东海冰精", ({"ice item","item"}) );
        set("long",
"此物乃蜀中将军自东海漩涡采来之神药,专治药性.\n"+
"此要须经药师调配(check item),方得食用(eat pill)。\n");
        set("unit", "棵");
        set("base_unit", "棵");
        set("value",2500);
        set("base_weight", 50);
        set_amount(1);
        setup();
}

void init()
{
        if( this_player()==environment() )
        {
                add_action("check_item","check");
        }       
}

int check_item(string arg)
{
     int cure;
     if( (arg=="item" || arg=="ice item") )
     {
        object user,ob;
        user = this_player();
       if(user->query("class")!="doctor")
        return notify_fail("你职业不是医者无法药株制成药丸!!\n");
        cure = user->query_skill("cure");
        cure = cure /5;
        if( cure > 16)
        {
          message_vision("$N试着将冰精制成药珠.\n", user);
          ob=new("/open/doctor/pill/ice_pill");
          ob->move(this_player());
          ob->add_amount((int)cure);
          add_amount(-1);
        }else
          message_vision("$N的医术太低,无法将冰精制成药珠.\n", user);
        return 1; 
     }
     return 0;   
}              
              
                           
