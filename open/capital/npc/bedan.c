inherit NPC;

void create()
{
	set_name("花轿",({"bedan"}));
	set("short", "花轿");
	set("race", "野兽");
	set("gender", "中性");
	set("light_up",1);
	set("age", 10);
	setup();
}

void init()
{
  add_action("do_look", "look");
}

int do_look (string arg)
{
  object        me, env;

  me = this_player();
  if (!arg || arg != "out") return 0;

  env = environment();

  "/cmds/usr/look"->look_room(me, env, 1);
  return 1;
}

int start_marry(object wife)
{
  string	name=wife->query("name");

  set("short", "美娇娘"+name+"的花轿(Bedan)");
  set("long", "这是一顶花轿，上头处处结红采，显得喜气洋洋的样子，\n"+
              "现在在里面坐着的正是新娘--"+name+"。\n");
}
