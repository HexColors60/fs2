// 钥匙, 有锁的房间请到 /u/w/wade/room/key_room 参考
inherit ITEM;

void create()
{
  set_name("四面佛像", ({ "wade token", "token" }) );
  set("unit", "块");
  set("no_drop",1);
  set("long", @LONG
    这是一块四面佛像, 据说是菠萝面包的女朋友送的, 他已
经珍藏了接近七年了, 一直跟钥匙放在一起, 现在已经斑驳不
堪. 上面除了有点破损, 还有看来是臭汗干掉后出现的痕迹.
看这样子, 大概原先是项炼的一部份, 自己去买的话, 也许只
值四五十块钱的路边货. 说归说, 但是这个信物代表着另一个
人以身相许的无限情意与信任, 因此它总算保留至今.
    在菠萝面包当兵前, 他将这个信物郑重的交给你, 代表另
一次的信任之情. 据说, 有了这个信物, 如果有巫师做不非常
不利于狂想空间的事情, 或是有什么不对劲, 可以用这个信物
传达菠萝面包的威力. 至于详情嘛........只好问问别人了.
LONG);
}

void init ()
{
  add_action ("log", "log");
  add_action ("read_log", "readlog");
  add_action ("give", "give");
  add_action ("help", "help");
}

int log (string str)
{
  int	sec;

  if (!str) {
    write ("log SECOND\n这命令可以用来让你把自己所见的讯息记录 SECOND 秒钟.\n");
    return 1;
  }
  else if (sscanf (str, "%d", sec) == 1) {
    if (sec <= 0) {
      write ("log SECOND\nSECOND 必须是正整数.\n");
      return 1;
    }
    this_player()->set_temp ("记录", time()+sec);
    assure_file ("/log/harass/"+this_player()->query ("id"));
    rm ("/log/harass/"+this_player()->query ("id"));
    write (sec + "你所接收的讯息将会记录成档案.\n");
  }
  return 1;
}

int read_log(string str)
{
  string who;
  string fn, buf;

  if (!wizardp (this_player()))
    return 0;

  if (!str)
    who = this_player()->query ("id");
  else
    who = str;

  fn = "/log/harass/"+who;
  this_player()->more_file ("", fn, 0);
  return 1;
}

int give (string str)
{
  string what, who;
  object ob;

  if (!str) return 0;

  if (sscanf (str, "%s to %s", what, who) != 2)
    return 0;

  if (!id (what)) return 0;

  if (!ob = present (who, environment (this_player()))) {
    write ("没有这个人在.\n");
    return 1;
  }

  if (!wizardp (this_player()))
    if (!wizardp (ob)) {
      write ("这个人不是巫师.\n");
      return 1;
    }

  this_object()->move (ob);
  this_player()->command ("say 好了, 信符交到你手上, 好好保管吧.\n");
  return 1;
}

int help (string str)
{
  if (!str || str != "wade") return 0;

  write (@HELP
本信符你可以用来记录你所看到的, 如果有人欺负你, 你可以把你
所看到的一切都记录下来, 然后持此信符通知高级巫师, 跟他(们)
说你所遭受的困扰. 当然, 此信符还可作为跟 wade 是兄弟的证明.
因为你们彼此信赖. 
    如果你想记录你所看到的, 请打 log N, 其中的 N  是要记录
的秒数. 如果你是巫师, 此外还可以用此信符来查看任何人的记录.
方法是 readlog WHO, WHO 是你要看的玩家的记录, 不在也行.
HELP);
  return 1;
}

int query_autoload() { return 1; }
