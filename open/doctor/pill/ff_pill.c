// made by ccat
// refix by chan
// 加上药性
inherit F_MEDICINE;
void create()
{
        set_name("雪莲丹", ({"force pill","pill"}) );
        set("long",
"此物乃蜀中将军自天山绝顶采来之神药,可以恢复大量内力.\n"+
"此要须经药师调配(check item),方得食用(eat pill).\n");
        set("unit", "盒");
        set("base_unit", "粒");
        set("no_sell",1);
       set("value",30000);
        set("base_weight", 50);
        set("cure_type","force");
        set("medicine_sick",125);
        set("eat_msg","$N将$n服下后, 感觉身上涌出源源不断的内力,瞬时内力大增。\n");
        set_amount(1);
        setup();
}
