// by Onion.
//fixed by Lum 6/25/1996 修正非书生的人也能读此书的Bug。
inherit ITEM;
string TITLE="[秘笈]";
string DESTRUCT_MESSAGE=TITLE+"这本秘笈不是你的,故书生工会会长杨书文派人将它取了回去。\n";
object me=this_player();
object ob=this_object();
mapping valid_types = ([
        "literate":     "读书识字",
        "unarmed":      "拳脚",
        "sword":        "剑法",
        "blade":        "刀法",
        "stick":        "棍法",
        "staff":        "杖法",
        "throwing":     "暗器",
        "force":        "内功",
        "parry":        "招架",
        "dodge":        "轻功",
        "magic":        "法术",
         "spells":       "咒术",
        "move":         "行动",
        "array":        "阵法",
        "dagger":       "匕首",
        "cure":         "医术",
        "plan":         "计谋",
        "stabber":      "刺术",
        "be-officer":   "政治",
        "whip":         "鞭法",
        "poison":       "用毒",
]);
 
void create()
{
      set_weight(0);
      if( clonep() )
           set_default_object(__FILE__);
      else {
           set("unit","本");
           set("long","这是一本记载武功的秘笈, 通常只有书生之流的人才能凭着"+
           "优异的学识将本身的武功心法计录下来。\n"+
           "键入<help secret_book>可获得更多的资讯。");
           set("value",0);
           set("no_drop",1);
           set("no_get",1);
      set("no_put",1);
           set("no_give",1);
           }
      set("belong",getuid(me));
      setup();
}
 
void init()
{
        if(!query("belong")){
           if(userp(environment())) set("belong",geteuid(environment()));
        }
        set_name(me->name(1)+ "的武功秘笈", ({ "secret_book" }));
        add_action("do_record","record");
        add_action("do_opento","opento");
        add_action("do_check","checkin");
        add_action("do_study","study");
        add_action("do_help","help");
}
int do_help(string str)
{
        if (str!="secret_book") return 0;
        write(@Help
 
        你可以使用以下的几个命令:
        record <skill>          将本身武学记录下来。
        opento <skill>          将书翻至记录此技能的地方, 方便研读。
        checkin secret_book     检查书上所记载的技能。
        study secret_book       由书上研读技能, 需先将书翻至正确的地方。
 
Help
        );
        return 1;
}
int do_study(string str)
{
        if( str != "secret_book" )              return 0;
        if( ob->query("skill/name") != 0 )      return 0;
        if( me->query("class")!= "scholar")
          return notify_fail(TITLE+"对于不是书生的人来说,这只是一本废物。\n");
        if(me->query("id") != this_player()->query("id") ||
           ob->query("belong") != environment(this_object())->query("id"))
        {
          write(DESTRUCT_MESSAGE);
          destruct(ob);                         return 1;
        }
        write(TITLE+"秘笈还没打开耶。\n");              return 1;
}
int do_record(string skill_name)
{
        int skill_max,skill_now;
        if(me->query("id") != this_player()->query("id"))
        {
          destruct(ob);
          return notify_fail(DESTRUCT_MESSAGE);
        }
        if( skill_name == 0 )
          return notify_fail(TITLE+"记录什么?\n");
        skill_now=me->query_skill(skill_name,1);
        skill_max=me->query("secret_book/"+skill_name);
        if( skill_now <= 0 )
          return notify_fail(TITLE+"呵..你这项技能还没练成勒。\n");
        if( me->query("class")!= "scholar")
          return notify_fail(TITLE+"对于不是书生的人来说,这只是一本废物。\n");
        if( undefinedp(valid_types[skill_name]) )
          return notify_fail(TITLE+"你只能记录基础技能。\n");
        if( me->query_skill("literate",1) < skill_now )
          return notify_fail(TITLE+"你的学识不足, 无法将身上所学记录下来。\n");
        if( skill_max >= skill_now )
          return notify_fail(TITLE+"你目前的技能并未比秘笈所记载的高出一级。\n");
        message_vision("$N在秘笈上龙飞凤舞的写下一些东西。\n",me);
        me->set("secret_book/"+skill_name,skill_now-1);
        if( me->query_skill("literate",1) < skill_now )
        {
          write(TITLE+"但由于你的学识不足, 无法将身上所学完全记录下来。\n");
          me->set("secret_book/"+skill_name,me->query_skill("literate",1)-1);
        }
        return 1;
}
int do_opento(string skill_name)
{
        int max_skill=me->query("secret_book/"+skill_name);
        if( skill_name == 0 )
          return notify_fail(TITLE+"翻到那儿?\n");
        if(me->query("id") != this_player()->query("id"))
        {
          destruct(ob);
          return notify_fail(DESTRUCT_MESSAGE);
        }
        if( me->query("secret_book/"+skill_name) == 0 )
          return notify_fail(TITLE+"秘笈中没有提到这项技能。\n");
        ob->set("skill/name",skill_name);
        ob->set("skill/max_skill",max_skill);
        ob->set("skill/sen_cost",(max_skill/20)+20);
        ob->set("skill/difficulty",20);
        setup();
        write(TITLE+"你将秘笈展开至「"+to_chinese(skill_name)+"”处。\n");
        return 1;
}
int do_check(string str)
{
        int i;
        mapping secret_book_skill;
        string *skill_name;
        if( str != "secret_book" )
          return notify_fail(TITLE+"检查什么?\n");
        if(me->query("id") != this_player()->query("id"))
        {
          destruct(ob);
          return notify_fail(DESTRUCT_MESSAGE);
        }
        if( sizeof(me->query("secret_book")) == 0 )
          return notify_fail(TITLE+"秘笈中目前仍是一片空白。\n");
        secret_book_skill=me->query("secret_book");
        skill_name=keys(secret_book_skill);
        write(TITLE+"以下是秘笈中记载的基本技能。\n");
        write("     名称        等级\n");
        for(i=0; i<sizeof(skill_name); i++)
          printf(" %-10s       %3d\n",to_chinese(skill_name[i]),me->query("secret_book/"+skill_name[i]));
        return 1;
}
 
int query_autoload()
{
    if(environment())
     if(userp(environment()) && environment()->query("class") == "scholar")
          return 1;
        return 0;
}
