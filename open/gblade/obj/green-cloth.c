inherit EQUIP;

void create()
{
        set_name("翠萝衫", ({ "green cloth", "cloth" }) );
	set_weight(700);
        set("gender_only", "女性");
        set("long", "
翠绿质柔，女红精巧，衣袖开口的地方，滚着淡淡的蓝边，拿在手里让你
有一种纤滑细腻的感觉。
\n");
        set("unit", "件");
        set("value",200);
        set("material", "cloth");
        set("armor_type", "cloth");
	set("armor_prop/armor", 3);
        setup();
}
