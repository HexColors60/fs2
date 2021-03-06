// Room: /open/center/room/bank.c

inherit BANK;

void create ()
{
  set ("short", "钱庄");
  set ("long", @LONG
这是一间皇家特约钱庄............的分行，自从附近马贼
强盗危害人间后，这儿已经没人敢来掌柜了，不过中央驿站多的
是不怕死的小子，这儿一年到头二十四小时无休的经营。
    右边墙角贴着一张说明书(sign)。
LONG);

set("item_desc",([
  "sign" : "这里是钱庄，目前我们提供的服务有：

balance		查钱庄有多少存款
withdraw	领取存在钱庄的钱
deposit		把钱存进钱庄
convert    	兑换钱币。

balance
withdraw <数量> <种类>
deposit <数量> <种类> || deposit all
convert <数量> <货币> to <货币>

范例:       convert 10 silver to coin

钱币种类有  1 gold == 100 silver == 10000 coin

",
]));

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road4",
  "enter" : __DIR__"auroom",
]));

  set("objects", ([
      "/open/gsword/mob/officer" : 1,
     ]) );
  set("light_up", 1);

  setup();
}
