#define WADE "/u/w/wade/npc/"
#define NAME "muse"
#define CNAME "妙妙"
#define SEX "女性"

void init()
{
    add_action("money", "ask");
}

void create()
{
        set_name( CNAME, ({ NAME }) );
        set("long",
"    你正盯着一位令人神魂颠倒的奇女子，当你第一眼看到她的时候，\n"+
"心中醋劲一发不可收拾，恨不相逢未...........\n"+
"如果你是她的爱人，你可以用 order_"NAME" <commands> 跟她沟通。\n"
        );
        set ( "gender", SEX );
        set("prevent_give_money", 1);
        // set("tactic_func", "call_help");
        set ( "have_partner", 0 );
        set("msg_min", "$N用优雅的步子走了过来。");
        set("msg_mout", "$N用优雅的步子走开。");
  setup();
}

int money (string arg)
{
  
}
