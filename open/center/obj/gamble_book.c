// blade_book.c

inherit ITEM;

void create()
{
        set_name("赌神秘术", ({ "book" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "这是一本赌徒最想要的珍宝, 只有幸运的人才能拿得到.\n");
                set("value", 10);
                set("material", "paper");
                set("skill", ([
                        "name":         "gamble",
                        "exp_required": 1,
                        "sen_cost":     30,
                        "difficulty":   30, // 不能比 30 小
                        "max_skill":    39,
                ]) );
        }
        setup();
}

int valid_learn(object me)
{
  if (!me->query("quests/gamble_book")) return -1;
  else return 1;
} 
