// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;

void create()
{
        set_name("阎罗王", ({ "ghost king", "king" }) );
        set("long",
                "想求免死符，先跪(kneeze)下来，磕足响头再说。\n");
        set("attitude", "peaceful");
        set("age", 21700);
        set("combat_exp", 20000000);
        set("max_gin", 900);
        set("max_kee", 900);
        set("max_sen", 200);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        setup();
}

void init()
{
        add_action("do_kneeze", "kneeze");
}

int do_kneeze(string str)
{
  message_vision("$N满心欢喜地朝阎罗王跪了下去。\n", this_player());
  if (this_player()->query("standby") < 2) {
    this_player()->add("standby", 1);
  }
  return 1;
}
