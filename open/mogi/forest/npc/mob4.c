//by roger
#include <ansi.h>
inherit NPC;

void create() {
        set_name("九节尸",({"nine ghost","ghost"}));
        set("long",
            "\n它是魔森林中常常出现的鬼物，一闻到生人气息就蹦出来吃人。\n");
        set("age",1937);
        set("str",25);
        set("cor",25);
        set("race","野兽");
        set("gender","雄性");
        set("attitude","aggressive");
        set("max_gin",600);
        set("max_kee",1700);
        set("max_sen",300);
        set("max_force",2000);
        set("force",2000);
        set("force_factor",9);
        set("combat_exp",950000);
        set_skill("unarmed",90);
        set_skill("dodge",80);
        set_skill("nine-steps",90);
        set_skill("move",60);
        set_skill("parry",90);
        set_skill("mogi-strike1", 90);
        map_skill("unarmed", "mogi-strike1");
        map_skill("dodge","nine-steps");
        map_skill("parry","hell-evil");
        map_skill("move","nine-steps");
        set("chat_chance",50);
        set("chat_msg",({
	"咭咭...好久没吃到人肉了～～\n",
	}));
        set("limbs",({"头部","胸部","大黑手","大黑脚","背部","腰部"}));
        set("verbs",({"bite","claw"}));
        setup();
 }

void init()
{
        object obj;
        ::init();
	set_leader(this_player());
}

int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIB"魔石雕像发出一阵强光，把$N再度吸回雕像中了！\n"NOR, this_object ());
             destruct(this_object());
             return 1;
        }
        return ::heal_up() + 1;
}
