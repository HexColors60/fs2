#define RMK_VERSION "(v 1.0 12/1/1995)"
#define INN "/player/inn"

inherit ITEM;

int save_room_file(string yn, string file, string str);

string *special_props = ({
  "short", "long", "file_name" });

int create()
{
  seteuid(getuid());
  set_name("简易房间编辑器" + RMK_VERSION,
    ({ "simple room maker", "maker" }) );
  set_weight(100);
  set("unit", "个" );
  set("long", @LONG
这是一个用来「简单地”制造房间的工具，让玩家也能编辑自己的房间。

rset <房间属性> <属性内容>   设定你目前所在房间的属性。
uset <房间属性>      取消目前所在房间的某项属性。
setlong        设定房间的长叙述。
saveroom        将你目前所在的房间存档。

LONG
  );

  set("no_drop",1);
  setup();
}

int init()
{
  seteuid(getuid(environment()));
  add_action("do_rset", "rset");
  add_action("do_uset", "uset");
  add_action("do_setlong", "setlong");
  add_action("do_settle", "settle");
  add_action("do_saveroom", "saveroom");
}

int check_owner(object me)
{
  object        env;
  mapping       couples;
  string        *master, my_id, my_name, file, *dir;

  my_id = me->query("id");
  my_name = me->query("name");
  env = environment(me);
  couples = me->query("couples");
  master = env->query("master");
  file = base_name(env);
  dir = explode(file, "/");

  if (dir[0] != "player") return 0;
  if (!couples) return 0;
  if ( master && (master[0] != my_id && master[1] != my_id) ) return 0;
  return 1;
}

void done_setlong (object me, string text)
{
  environment(me)->set("long", text);
        return;
}

int do_setlong ()
{
  object me=this_player();

  if (!check_owner(me)) {
    write ("噫? 你怎么想拆别人的家? 就麻烦你到出入境管理局一趟吧。\n");
    me->move(INN);
    destruct (this_object());
    return 1;
  }

  this_player()->edit( (: done_setlong, this_player() :) );
  return 1;
}

int do_uset(string arg)
{
  object me=this_player();
  string prop, str;

  if( !arg || sscanf(arg, "%s", prop)!=1 )
    return notify_fail("指令格式：uset <房间属性>\n"
                                   "      如: uset light\n");

  if (!check_owner(me)) {
    write ("噫? 你怎么想拆别人的家? 就麻烦你到出入境管理局一趟吧。\n");
    me->move(INN);
    destruct (this_object());
    return 1;
  }

  environment(this_player())->delete(prop);
  write("Ok.\n");
  return 1;
}

int do_rset(string arg)
{
  object	me=this_player();
  string prop, str;
  int data, i, n;

  if( !arg || sscanf(arg, "%s %s", prop, str)!=2 )
    return notify_fail("指令格式：rset <房间属性> <属性内容>\n");

  if (!check_owner(me)) {
    write ("噫? 你怎么想拆别人的家? 就麻烦你到出入境管理局一趟吧。\n");
    me->move(INN);
    destruct (this_object());
    return 1;
  }

  n = strlen (str);
  if (str[0] == '"' && str[n-1] == '"') {
          write ("set "+prop+" = \""+str[1..n-2]+"\"\n");
    environment(this_player())->set(prop, str[1..n-2]);
    return 1;
  }

  data = 0;
  for (i=0; i<n; i++)
    if (str[i] < '0' || str[i] > '9') {
      data = 1;
      break;
    }

  if( !data && sscanf(str, "%d", data)==1 ) {
          write ("set "+prop+" = "+data+"\n");
    environment(this_player())->add(prop, data);
  }
  else {
    write ("set "+prop+" = \""+str+"\"\n");
      environment(this_player())->set(prop, str);
  }
  return 1;
}

int save_room_file(string yn, string file, string str)
{
  string  tmp;
  int    i;

  if( strlen(yn)<1 || yn[0]!='y' ) return 1;

  i = sizeof(file)-1;
  if (!(file[i] == 'c' && file[i-1] == '.')) file = file+".c";
  write ("file name is " + file + "\n");
  if ( write_file(file, str, 1) )
    return 1;
  else {
    write ("尝试整建失败!!\n");
    return 0;
  }
}

void owner_is_killed() { destruct(this_object()); }

int do_saveroom(string arg)
{
  object env, me=this_player();
  string str, *name, file, pre, suc;
  mapping prop;
  int i;
  string cwd;

  if (!check_owner(me)) {
    write ("噫? 你怎么想拆别人的家? 就麻烦你到出入境管理局一趟吧。\n");
    me->move(INN);
    destruct (this_object());
    return 1;
  }

  env = environment(this_player());
  file = file_name(env) + ".c";

  if (file_size(file) <= 0) return
          notify_fail ("没有这房间的档案: "+file+"\n");

  name = explode (read_file (file), "\n");
  pre = "";
  for (i=0; i<sizeof (name); i++)
    if (strsrch (name[i], "void create") != 0)
      pre += name[i] + "\n";
    else break;
  pre += "void create ()\n{\n";

  i += 2;
  while (name && name[i][0..0] != "}") i++;
  suc = ""; i++;
  while (i<sizeof(name)) suc += name[i++]+"\n";

  prop = env->query_entire_dbase();
  
  str = pre;
        str = sprintf ("%s  set (\"short\", \"%s\");\n"
               "  set (\"long\", @LONG\n%sLONG);\n\n",
             str, prop["short"], prop["long"]);

  name = keys(prop);
  for(i=0; i<sizeof(name); i++) {
    if( member_array(name[i], special_props)!=-1 ) continue;
    if ( (intp(prop[name[i]]) && prop[name[i]]>0) ||
    (stringp(prop[name[i]]) && prop[name[i]] != "" ) ||
    (mapp(prop[name[i]]) && prop[name[i]] == ([])) ||
      sizeof (prop[name[i]]) > 0)
        str += sprintf("  set(\"%s\", %O);\n",
                                   name[i], prop[name[i]] );
  }
  if (sizeof (explode(suc, "\n")) < 3)
   str += "\n  setup();\n}\n";
  else
   str += "\n  setup();\n}\n"+suc;

  if( file_size(file)!=-1 ) {
    write("你确定要以现在的样子装璜吗? (y/n) ");
    input_to("save_room_file", file, str);
    return 1;
  }

  // Replace current directory with __DIR__ macro to make relocatable code.
  file = file_name(env);
  i = strlen(file)-1;
  while( (i > 0) && (file[i]!='/')) i--;
  if( i>0 ) {
    write("房屋存档完毕。\n");
    str = replace_string(str, "\"" + file[0..i], "__DIR__\"");
  }

  return save_room_file("y", file, str);
}

int do_settle()
{
  object  me, env, couple;
  mapping  couples;
  string  *master, my_id, my_name;

  me = this_player();
  my_id = me->query("id");
  my_name = me->query("name");
  env = environment(me);
  couples = me->query("couples");
  master = env->query("master");

  if (!check_owner(me)) {
    write ("噫? 你怎么想在别人的地盘定居，就麻烦你到出入境管理局一趟。\n");
    me->move(INN);
    destruct (this_object());
    return 1;
  }

  env->set("short", my_name+"与"+couples["name"]+"--爱的小屋");
  env->set("master", ({my_id, couples["id"]}) );

  if (do_saveroom("")) {
    write (my_name+"和"+couples["name"]+"终于安心定居下来了。\n"
     "你看了看四周空空荡荡的，好不凄凉，不如开始着手整建一番吧。\n");
    me->set("house", base_name(env));
    couple = FINGER_D->acquire_login_ob(couples["id"]);
    couple->set("house", base_name(env));
    couple->save();
    if (!interactive(couple)) destruct(couple);
  }
  else
    write ("哇，怎么不能定居啦，快找人看看风水是不是有什么问题啊!!\n");
  return 1;
}
