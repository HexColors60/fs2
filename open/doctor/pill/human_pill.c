//每种pill都有药性
//design by chan
inherit F_MEDICINE;
void create()
{
        set_name("人灵丹", ({"human pill","pill"}) );
        set("long",
                   "此物乃传说中的丹药,具有起死回生的药效.\n");
        set("unit", "盒");
        set("base_unit", "粒");
        set("no_sell",1);
        set("value",7000);
        set("base_weight", 50);
        set("cure_type","heal_kee");
        set("medicine_sick",120);
        set("eat_msg","$N将$n服下后, 感觉身上伤痕都不见了。\n");
        set_amount(1);
        setup();
}
