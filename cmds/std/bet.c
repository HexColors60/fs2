#define GAMBLE_ROOM "/open/center/room/men"

inherit F_CLEAN_UP;

string  *bet_type = ({
        "cash",
        "money",
        "food",
        "water",
        // 不让人家赌 exp 了
        // "combat_exp",
        "force",
        "mana",
        "atman",
//"potential",  ...赌潜能取消
  "bellicosity", //新增杀气
});

int main(object me, string arg)
{
        int     value, n;
        string  num, bet, type;
        mapping quests, my_q;

        seteuid(getuid(me));

        if (!arg)
          return notify_fail ("请用 help bet 查压钱的方法。\n");
        else if (sscanf (arg, "%s %s", num, bet) != 2)
          return notify_fail ("请用 help bet 查压钱的方法。\n");
        type = "money";
        if (sscanf (bet, "%s %s", bet, type) == 2)
          // 不是钱一定是完成够多的任务才有资格
          if (type != "money" && type != "cash") {
            quests = "/cmds/std/quests"->query_quests();
            my_q = me->query("quests");
            if (sizeof(my_q)*10 < sizeof(quests) * 7)
              return notify_fail ("你没有资格自由选定赌注型态, 请多完成几个任务后再来。\n");
          }
        if (member_array(type, bet_type) != -1 &&
            !catch(load_object(GAMBLE_ROOM)))
        {
if(type=="bellicosity" && (me->query("family/family_name")=="魔刀门" ||
me->query("family/family_name")=="魔刀莫测") &&
me->query("bellicosity")>4000)
return notify_fail ("你杀气大于4000够用了不能再赌。\n");
if(type=="atman"&&me->query("class")!="dancer" && me->query("atman")>100000)
return notify_fail ("你灵力大于100000够用了不能再赌。\n");
if(type=="atman"&&me->query("class")=="dancer" && me->query("atman")>150000)
return notify_fail ("你灵力大于150000够用了不能再赌。\n");
          if (me->query_temp("gamble")) return notify_fail("你已经压好离手了。\n");
          if (sscanf (bet, "%d", value) != 1 || value < 0) return
                notify_fail ("赌注一定要正数, 请用 help bet 查压钱的方法。\n");
        if(type == "cash" && value < 300)
          return notify_fail ("本赌场只接收三百张以上的千两银票的赌注,小赌注一律不接收!!\n");
        if(type == "cash" && (num=="大" || num=="小"))
          return notify_fail("本赌场不接受银票赌大小，要赌就赌点数!!!\n");

          return GAMBLE_ROOM->player_bet(me, num, value, type);
        }
        else return notify_fail("不是赌注型态不对, 就是赌场出问题.\n");
}

int help(object me)
{
        me->start_more(@HELP
指令格式 : bet <大/小/点数/7> 钱数
指令说明 :
           这个指令可以让你压赌，对于赌徒来说，是一项又方便又
         有趣的玩意儿。如果想赌博，请打开赌博频道，方法是直接
         输入 gamble。 如果不想听赌博讯息，请关掉赌博频道，方
         法是输入 tune gamble。

赌的方式是 bet <大/小/点数/7> <多少> [种类]
其中 小 表示骰子出 1，2，3
     大 表示骰子出 4，5，6
     赌大小有限制都是以1000000为上限, 但是cash不能赌大小
     新增加押点数, 一到六点, 赔率是一赔六, 可以用cash赌, 不过一次最少要300 cash
     7  表示骰子靠壁站的状况，俗称ㄎㄧㄚV 豆，这儿称为
        Ｌｕｃｋｙ　Ｓｅｖｅｎ
其中的种类不给的话是金钱，可用的有:
        money             :       钱(预设选项)
        cash              :       千两银票(赌术二十以上)
        food，water       :       食物饮水(赌术十以上)
        force             :       内力(赌术四十五以上)
        bellicosity       :       杀气(赌术在五十以上)
        atman，man        :       灵力，法力(赌术六十以上)
        potential         :       潜能(赌术八十以上)
限制条件如右: 完成一定数目的任务(总任务数的 70% (含)以上)，再加上
              赌技够的话，可以赌钱以外的东西:
  赌技 <  10    --> 钱
  赌技 <  45    --> 食物，饮水
  赌技 >  50    --> 杀气，内力，食物，饮水
  赌技 >  60    --> 食物，饮水，灵力，内力，法力

PS: 如果赌场没开，请去赌场下 "start" 命令
PS: 钱以外的特殊种类必须要有完成任务总数的七成才行，
    此外，还需要一定的赌技
PS: 最多下 1000000，还是 money 都是如此
PS: 赌cash的话没有限制下的数量
HELP
    );
    return 1;
}
