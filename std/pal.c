// npc.c

#include <command.h>

inherit CHARACTER;
inherit F_MESSAGE;
inherit F_MORE;
inherit F_CLEAN_UP;

string process_input(string str)
{
  seteuid(getuid());

  return str;
}

object carry_object(string file)
{
	object ob;

	if( !objectp(ob = new(file)) ) return 0;
	ob->move(this_object());
	return ob;
}

object add_money(string type, int amount)
{
	object ob;

	ob = carry_object("/obj/money/" + type);
	if( !ob ) return 0;
	ob->set_amount(amount);
	return ob;
}

int accept_kill(object who)
{
  if (query("race") == "人类")
    command("say 想砍我? 鹿死谁手还不知道呢!\n");
  return 1;
}

int accept_fight(object who)
{
	string att;

	att = query("attitude");
	if( att == "friendly" ) {
		command("say 好抱歉 ! 我不想和你打架。");
		return 0;
	}
	return 1;

}

// This function is called by the reset() of the room that creates this
// npc. When this function is called, it means the room demand the npc
// to return its startroom.
int return_home(object home)
{
	// Are we at home already?
	if( !home || !environment()
	||	environment()==home )
		return 1;

	// Are we able to leave?
	if( !living(this_object())
	||	is_fighting()
	// ||	!mapp(environment()->query("exits"))
        ) return 0;

	// Leave for home now.
	message("vision", this_object()->name() + "急急忙忙地离开了。\n",
		environment(), this_object());
	return move(home);
}

// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.
int chat()
{
	string *msg;
	int chance, rnd;

	if( !environment() ) return 0;

	if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
		return 0;
	if( random(100) > chance ) return 0;

	if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) {
		if (sizeof(msg) == 0) return 0;
		rnd = random(sizeof(msg));
		if( stringp(msg[rnd]) )
			say(msg[rnd]);
		else if( functionp(msg[rnd]) )
			return evaluate(msg[rnd]);
		return 1;
	}
}

// Default chat function: Let the npc random move to another room.
int random_move()
{
	mapping exits;
	string *dirs;

	if( !mapp(exits = environment()->query("exits")) ) return 0;
	if (query("random_move") <= 0) return_home(query("startroom"));
	add("random_move",-1);
	dirs = keys(exits);
	command("go " + dirs[random(sizeof(dirs))]);
}

// Default chat function: Let the npc cast his/her enabled spells
void cast_spell(string spell)
{
	string spell_skill;

	if( stringp(spell_skill = query_skill_mapped("spells")))
		SKILL_D(spell_skill)->cast_spell(this_object(), spell);
}

void conjure_magic(string magic)
{
        string magic_skill;
        if( stringp(magic_skill = query_skill_mapped("magic")))
            SKILL_D(magic_skill)->conjure_magic(this_object(), magic);
}

// Default chat function: Let the npc exert his/her enabled force
int exert_function(string func)
{
	string force_skill;

	if( stringp(force_skill = query_skill_mapped("force")))
		SKILL_D(force_skill)->exert_function(this_object(), func);
}

// Default chat function: Let the npc perform special action with 
// his/her enabled martial art
int perform_action(string action)
{
	object weapon;
	string martial_skill, act;

	if( sscanf(action, "%s.%s", martial_skill, act) != 2 )
		return 0;
	martial_skill = query_skill_mapped(martial_skill);
	if( stringp(martial_skill) )
		return SKILL_D(martial_skill)->perform_action(this_object(), act);		
}
