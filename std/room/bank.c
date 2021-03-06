// made by funkcat, copy and re-edit by ccat, modify by ice..
// 修正加上领取上限 By Swy
// 1.上限二十万两黄金
// 2.取消银票的制度
// 3.只能兑换黄金、银子及铜钱
// 4.fix by chan
inherit ROOM;
string kind;
void init() 
{
        add_action("account_check","balance") ;
        add_action("withdraw_money","withdraw"); 
        add_action("deposit_money","deposit");
        add_action("do_convert","convert");
        add_action("lend_money", "lend");
        add_action("relend_money", "relend");
}
                                                   
int account_check(string arg)
{
        int t_gold, gold, silver, coin;
        object ob;

        if(arg && wizardp(this_player()))
        {
          if(find_player(arg))
          {
            ob=find_player(arg);
            tell_object(this_player(),sprintf("你在看%s(%s)的存款!!\n",ob->query("name"),arg));
          }
          else
            return notify_fail("没有这个人!!\n");
        }
        else
        {
          ob=this_player();
        }
        t_gold = ob->query("bank/silver");
        if(t_gold >0)                        //若有二十万两黄金银票的人取消他的钱
           ob->delete("bank/silver");
       
          //只留银子,金子及铜钱
        coin   = ob->query("bank/coin"); 
        t_gold = coin;
        gold   = (int) coin / 10000;
        coin   = (int) coin % 10000;
        silver = (int) coin / 100;
        coin   = (int) coin % 100;
        write(sprintf("\n您一共存了\n    %7d  锭黄金\n    %7d  两银子\n    %7d  文铜钱\n",
         gold, silver, coin), this_player());
        if(t_gold < 0)   //有存超过溢位的, 就把钱变零, by bss
        {
           ob->delete("bank");
           tell_object(ob,"你的钱变负的了, 系统帮你把它归零!!\n");
        }

        return 1;
}                       
                        
int withdraw_money(string arg)
{
        int amount, value;
        object me = this_player(), n_money;                        
        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
                return notify_fail("\nwithdraw <数量> <种类>\n");

        if( amount + me->query_encumbrance() > me->query_max_encumbrance() )
                return notify_fail("你拿不动那么重的钱。\n");

        n_money = present(kind + "_money", me);
          
        if( !n_money && file_size("/obj/money/" + kind + ".c") < 0 )
                return notify_fail("你没有这种钱。\n");                      
                                                        
        if( amount < 1 )             
                return notify_fail("你不能提这种数量的钱。\n");
        if( amount > 9000 )
                return notify_fail("留些钱买老本吧，别提光了。\n");

        value = n_money ? n_money->query("base_value") : call_other("/obj/money/" + kind, "query", "base_value" );

        value *= amount;
        if(value <0 && wizardp(me)) printf("value=%d\n",value);
        if(value < 0) return notify_fail("你没有这么多钱!!!\n");
        if(me->query("bank/coin") < value) {
                if( !me->query("bank/silver") )
                        return notify_fail("你没有这么多钱\n");
                else {
                        me->add("bank/silver", -1);
                        value = 2000000000 - value;
                        value += me->query("bank/coin");     
                        me->set("bank/coin", value);
                }
        }
        else me->set("bank/coin", me->query("bank/coin")-value);
   
        if( !n_money ) {
                n_money = new("/obj/money/" + kind);
                n_money->move(me);
                n_money->set_amount(amount);
        } 
        else
                n_money->set_amount(n_money->query_amount()+amount);    
                                                    
        write(sprintf("你一共提出%s%s%s\n",
   chinese_number(amount),n_money->query("base_unit"),n_money->query("name")));
                        
        return 1;
} 
                
int deposit_money(string arg)
{
        int amount;
        object n_money, gold_money, silver_money, coin_money, me = this_player();
        int value, gold, silver, coin;
                        
        if(!arg)
                return notify_fail("\ndeposit <数量> <种类> || deposit all \n");   
                                                        
        if( arg == "all" )
        {
                gold = 0; silver = 0; coin = 0;
                if( gold_money = present("gold_money", me) )
                {
                        gold = gold_money->query_amount();
                        gold_money->set_amount(0);
                }
                if( silver_money = present("silver_money", me) )
                {
                        silver = silver_money->query_amount();
                        silver_money->set_amount(0);
                }
                if( coin_money = present("coin_money", me) )
                {
                        coin = coin_money->query_amount();
                        coin_money->set_amount(0);
                }
                value = gold * 10000 + silver * 100 + coin;
                value += me->query("bank/coin");
                if( value >= 2000000000 ){ //上限为二十万两黄金
                        value = 2000000000;
                write("您的存款超过狂想上限二十万两黄金,所以钱庄自动帮您多的钱发给穷困老人\n");
                }
                if(value <0){
                  value=0;
                  write("你存的钱被偷走了, 你现在并没有存任何的钱!!\n");
                }
                me->set("bank/coin", value);
                write(sprintf("您一共存入 %d 锭黄金 %d 两银子 %d 文铜钱\n",
                        gold, silver, coin));
                return 1;
        } 

        if( sscanf(arg, "%d %s", amount, kind) != 2 )
                return notify_fail("\ndeposit <数量> <种类> || deposit all \n");

        n_money = present(kind + "_money", me);
          
        if( !n_money || file_size("/obj/money/"+kind+".c") < 0 )
                return notify_fail("你没有这种钱。\n");                      

        if( amount < 1 )             
                return notify_fail("你不能存这种数量的钱。\n");
                
        if( n_money->query_amount() < amount)
                return notify_fail("你没有这么多钱\n");
        if( n_money->query_amount() == amount)
                return notify_fail("你要全存吗?留点吃饭钱吧!\n");

        n_money->set_amount(n_money->query_amount()-amount);    

        value = n_money ? n_money->query("base_value") : call_other("/obj/money/" + kind, "query", "base_value" );
        value = value*amount + me->query("bank/coin");

        if( value >= 2000000000 ) {
                value = 2000000000;
        write("您的存款超过狂想上限二十万两黄金,所以钱庄自动帮您多的钱发给穷困老人\n");
        }
        if(value<0){
          value=0;
          write("你存的钱被偷走了, 你的存款都没了!!!\n");
        }
        me->set("bank/coin", value);                      
        write(sprintf("你一共存入%s%s%s\n",chinese_number(amount),n_money->query("base_unit"),n_money->query("name")));

        return 1;
}
                                                           
int do_convert(string arg)
{                                                            
        string from, to;
        int amount, bv1, bv2;
        object from_ob, to_ob;

        if( !arg || sscanf(arg, "%d %s to %s", amount, from, to)!=3 )
                return notify_fail("指令格式：convert <数量> <货币> to <货币>\n");

        from_ob = present(from + "_money", this_player());
        to_ob = present(to + "_money", this_player());

        if( !to_ob && file_size("/obj/money/" + to + ".c") < 0 )
                return notify_fail("你想兑换哪一种钱？\n");
        if( !from_ob )          
                return notify_fail("你身上没有这种货币。\n");
        if( amount < 1 )        
                return notify_fail("兑换货币一次至少要兑换一个。\n");
        if( (int)from_ob->query_amount() < amount )
                return notify_fail("你身上没有那么多" + from_ob->query("name") +".\n");
        if( !bv1 = from_ob->query("base_value") )
                return notify_fail("这种东西不值钱。\n");

        bv2 = to_ob ? to_ob->query("base_value") : call_other("/obj/money/" + to, "query", "base_value" );

        if( bv1 < bv2 ) 
                amount -= amount % (bv2 / bv1);
        if( amount==0 ) 
                return notify_fail("这些" + from_ob->query("name") + "的价值太低了，换不起。\n");
        if(amount*bv1/bv2 <=0)
          return notify_fail("换钱失败, 一次换太多钱不好喔!!!\n");
        if( !to_ob ) {
                to_ob = new("/obj/money/" + to);
                to_ob->move(this_player());
                to_ob->set_amount(amount * bv1 / bv2);
        } else   
                to_ob->add_amount(amount * bv1 / bv2);
        message_vision( sprintf("$N从身上取出%s%s%s，换成%s%s%s。\n",        
                chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
                chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"),to_ob->query("name")),
                this_player() );      
        from_ob->add_amount(-amount);
        return 1;
}    

int lend_money(string arg)
{
        int lend;
        object me = this_player();

        if( me->query("combat_exp") < 50000 )
                return notify_fail("你的实战经验至少要 50000 才可以借钱.\n");
        if( !arg || sscanf(arg, "%d coin", lend) != 1 )
                return notify_fail("你想要向钱庄借多少钱, 请打 lend <数量> coin\n");
        if( lend < 1 )
                return notify_fail("你想要借多少钱呀?\n");
        if(me->query("bank/lend")>=me->query("combat_exp")/10000*5000 )
                return notify_fail("你已经不能再向钱庄借钱了.\n");
        if( lend > me->query("combat_exp")/10000*5000 - me->query("bank/lend") )
                return notify_fail(sprintf("你最多只能借 %d 文钱.\n",me->query("combat_exp")/10000*5000-me->query("bank/lend")));

        me->pay_player(lend);
        me->add("bank/lend", lend);
        write(sprintf("你向钱庄借贷了 %d 文钱.\n", lend));
        return 1;
}

int relend_money(string arg)
{
        int lend;
        object me=this_player();

        if( me->query("bank/lend") <= 1 )
                return notify_fail("你现在并没有欠钱.\n");
        if( !arg || sscanf(arg, "%d coin", lend) != 1 )
                return notify_fail("如果你要还钱庄钱的话请打 relend <数量> coin\n");
        if( lend < 1 )
                return notify_fail("你想要还多少文钱?\n");
        if( lend*20/21 > me->query("bank/lend") )
                return notify_fail("你并没有借这么多文钱.\n");
        if( !me->can_afford(lend) )
                return notify_fail("你身上没有那么多文钱.\n");

        me->add("bank/lend", -lend*20/21);
        me->pay_money(lend);
        write(sprintf("你还了 %d 文钱给钱庄.\n", lend));
        return 1;
}
