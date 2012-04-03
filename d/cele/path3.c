#include <ansi.h>

inherit ROOM;
string show_word(object me);

string *great = ({
               "        故事妖精开讲啰....  "NOR, 
            HIY"    最后之梦幻传说开始~~~~~ "NOR,
            HIW" 漂漂筱岚美眉有天走路走到犛田..."NOR,
            HIW" 因为太懒了,不想起来, 但是感觉到有种异样眼光看着她"NOR,
            HIW" dean的邪恶眼神不断着看着她, 口水都快流出来了..:D~~"NOR,
            HIW" dean大喊 : 我要劫色 !! 给我脱~~~~~~"NOR,
            HIW" Anmy 以纯洁的眼神看着小恩恩, 想了好久好久.... "NOR,
            HIW" dean恶狠狠的瞪着她, 似乎像大野狼般一口吃下岚岚.. "NOR,
            HIW" 此时民族..的救星 不~Mud的奇才Lum登场...." NOR,
            HIC"     光 芒 四 射    闪 闪 动 人       "NOR,
            HIW" 小拉姆看着小恩恩, 二人似乎一触待发, 一旦动手.."NOR,
            HIW" 将势必是 一时勾动天雷地火 一发不可收拾 !!! "NOR,
            HIG"                 可是... "NOR,
            HIW" 邪恶小恩不停地看着小拉姆上下很多次, 好似想着什么.."NOR,
            HIW"                          to be continue... "NOR,
});

void create ()
{
  set ("short", "[1;35m过去时空[0m 葬剑亭");
  set ("long", @LONG

你现在来到一个山腰靠近山顶的亭子，亭子前立着一个两丈多高的
石碑(monolith)，从亭子里远眺北方连绵不尽的大山，使你不禁感到胸
臆之间一股英雄情怀油然而生，葬剑亭据说每到夏日夜晚，野风吹过，
会产生一阵阵呜呜的哭泣声，这也是水烟十景中的「孤亭剑泣”。出了
亭子，往南便是直通虹台的石阶。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"path2",
]));
  set("item_desc", ([ /* sizeof() == 2 */
  "word" : " 在你眼前似乎有人以浑厚的内力将一些刻字
以沙覆盖过去 , 想要看清楚 , 可能得花点气力 ..
",
  "monolith" : "石碑上龙飞凤武地刻着几个大字：

    风波剑神黎红药前辈葬剑于此，水烟阁第四代七长老比武
    不胜，以奸计害人而自取其辱，武者皆不齿其小人行径，
    合力击杀于此，甲辰年立此亭书铭其事以为后人殷鉴。
                        第三代水烟阁主 于兰玫音
                        第四代水烟阁主 聂    言   合立
                        第五代水烟阁主 段 柏 山

     你隐隐的看到石碑的右后处似乎模糊地写了几个字 ...
",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/executioner" : 1,
]));

  setup();
}
void init()
{
   add_action("start_great","show");
}
int start_great()
{
  call_out("show_great",1,this_player(),0);
  return 1;
}
int show_great(object me,int x)
{
   int i;
   string msg;
   msg = great[x];
   message_vision(msg+"\n",me);
   if( ++x < sizeof(great) ) {
             call_out("show_great", 1 ,me,x);
    }
}
