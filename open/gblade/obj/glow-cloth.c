inherit EQUIP;

void create()
{
        set_name("五彩银丝窄袄", ({ "glow cloth", "cloth" }) );
        set_weight(2800);
        set("long", "
一件用上好棉料作成的衣服，外头用五彩丝线绣了一只麒麟，在靠近腰的
部份，还用银丝穿了两个雕饰精美的翡翠，走起路来还会发出叮叮当当的
声音。

\n");
        set("unit", "件");
	set("value", 10000);
        set("material", "cloth");
        set("armor_type", "cloth");
	set("armor_prop/armor", 18);
	set("dodge",3);
        setup();
}
