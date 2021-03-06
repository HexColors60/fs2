// buy.c

inherit F_CLEAN_UP;

int help(object);
int delay_buy(object ppl);

int main(object me, string arg)
{
  string item, targ;
  object ob, owner,*living;
  int price, afford, n,i;

  seteuid(getuid());
  if( !arg ) return help(me);
  if( sscanf(arg, "%s from %s", item, targ)!=2 )
  {
   item = arg;
   living=all_inventory(environment(me));
    for(i=0;i<sizeof(living);i++){
      if(living[i]->query("vendor_goods")){
        owner=living[i];
        break;
      }
    }
  if(!owner) return help(me);
  }
  else
  {
    targ = lower_case(targ);

    if( !objectp(owner = present(targ, environment(me))) ||
      userp(owner) || !living(owner))
    return notify_fail("只能跟非玩家的'人'买东西!!\n");
  }
  if(me->query_temp("wait_buy"))
    return notify_fail("卖东西的人正在忙, 等下再买吧!!!\n");
  else
  {
    me->set_temp("wait_buy",1);
    call_out("delay_buy",2,me);
  }
  return owner->sell_object(me, item);
}

int delay_buy(object ppl)
{
    if(!ppl) return 1;
    ppl->delete_temp("wait_buy");
    return 1;

}
int help(object me)
{
   write( @HELP
指令格式: buy [数量] <东西> from <生物>
指令说明 :
          这一指令让你可以从某些生物身上买到物品。
          当你要大量地买相同的东西的时候，记得给数量。
范    例 :
        buy torch from girl
        buy 100 bandage from vendor
警    告 :
	  大量买相同物件请不要用 <数量> buy <东西> from <生物>
	  因为这样会让您容易变成机器人, 上述的命令数视为 <数量> 个.
	  此外, 上述的方式也非常耗 CPU, 是前面说明的 <数量> 倍,
	  综合以上说明, 在此特别呼吁各位用本命令特别提供的语法买东西.
HELP
   );
   return 1;
}
