// knowledge_cloth by nako

inherit EQUIP;

void create()
{
        set_name("孔子儒服", ({"knowledge robe" , "robe"}) );
        set_weight(7000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","传说中至圣先师穿过的儒服, 流传至今日已是无价之宝。\n");
        set("unit","件");
        set("value",30000);
	set("material","cloth");
        set("armor_type","cloth");
        set("armor_prop/armor", 20);
        set("armor_prop/dodge", 6);
        set("armor_prop/parry", 5);
        set("armor_prop/literate", 25);
          set("armor_prop/stabber", 5);
	}
        setup();
}

int wear()
{
    if( (string)this_player() -> query("class") != "scholar" )
    return notify_fail("你又不是书生, 不用穿儒服啦！\n");
    else {
           :: wear();
         }
    return 1;
}
