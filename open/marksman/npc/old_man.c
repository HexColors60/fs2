inherit NPC;
string do_act();
string do_aca();
string do_acb();
string do_acc();
void create()
{
        set_name("老人",({"old man","man"}));
        set("gender","男性");
        set("age",70);
        set("str",30);
        set("long","一位白发苍桑的老人。\n");
        set("chat_chance",10);
        set("inquiry",([
        "弓老人" : (:do_acc:),
        "李广" : (:do_act:) ,
        "制弓" : (:do_aca:) ,
        "条件" : (:do_acb:) ,       
]));
        add_action("do_act","act");
        add_action("do_aca","aca");
        set("combat_exp",1000000);
        setup();
        add_money("silver",1);
}
int accept_fight(object who)
{
 return notify_fail("老人说:都不会敬老尊贤吗?，真没教养的人。\n");
}
void init() {
        object obj;

        ::init();
        if(interactive(obj=this_player()) && !is_fighting()) 

        {
        remove_call_out("greeting");
        call_out("greeting",2,obj);
        }
}
void greeting(object ob)
{
        command("say 有事吗? ");
}
  string do_act()
{
        command("say 我认识，当初他那把李广弓就是我做给他的。 ");
        command("say 不过我现在没在「制弓”了，年事已高啰。");           
}

string do_aca()
{
    command("say 什么?李广要我帮你做把弓?!");
    command("say hmm");
    command("say 看在李广的面子上，就帮你做吧，不过可是有「条件”的。\n");
}
string do_acb()
{
  command("say 我很喜欢后羿身旁的那把落日弓，若你能帮我取回，必定制做最好的弓。");
  command("say 来做为谢礼。\n");
}
string do_acc()
{
command("say 你可真厉害，我这个封号很久没用啰。");
command("say 说起来我这个封号只有「李广”一位知道而已呀。\n");
}
