// Room : /open/clan/ou-cloud-club/room/hall.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
一踏入此地．．．便有一股傲情侠骨的气息朝你直扑而来
．．．原来这便是传说中仙意灵地的$HIY$傲$HIC$云$HIB$山$HIR$庄$NOR$，据说当年乃此
庄主剑君十二恨召集武林上赫赫有名的$HIC$雪苍$NOR$、$HIR$泷山$NOR$、$HIM$圣火$NOR$、仙
剑、$MAG$儒门$NOR$、$HIG$段家$NOR$、$YEL$舞者$NOR$、杀手、$CYN$恶人$NOR$、$HIB$魔刀$NOR$、$HIY$金刀$NOR$的各派的第
一强者，穷尽毕生功力合力所创出来的空间，而庄主也为了武
林的安危，便立下重誓，要帮众一生除$HIR$恶$NOR$惩$HIC$奸$NOR$，如此情操早已
令$HIY$傲$HIC$云$HIB$山$HIR$庄$NOR$成为全天下第一大帮了．．．
 

                       $HIC$ ;;;;''
                          ,
                         ,;;,;'''';;;
                  , ,,;''';; ,,  '''
                ;;       ;; ;;
                ;;   ;;  ;' ,;'
                            ,
                       ,;;'''',,,,
                        ,,,;''''  '
                  ,,;;'',;;   ,
                        ,;',,,;';,
                      ';;;''   ' $NOR$

LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 7 */
		"enter"     : "/open/clan/ou-cloud-club/room/room162.c",
		"northup"   : "/open/clan/ou-cloud-club/room/room118.c",
		"up"        : "/open/clan/ou-cloud-club/room/room117.c",
		"north"     : "/open/clan/ou-cloud-club/room/room7",
		"west"      : "/open/clan/ou-cloud-club/room/room2.c",
		"east"      : "/open/clan/ou-cloud-club/room/room6.c",
		"south"     : "/open/clan/ou-cloud-club/room/room126.c",
		"down"      : "/open/clan/ou-cloud-club/room/room131.c",
]) );
	set( "no_clean_up", 0 );
	set( "light_up", 1 );
	set( "short", "$HIY$傲$HIC$云$HIB$山$HIR$庄$NOR$" );
	set( "item_desc", ([
		"statue" : @ITEM

[0;1;5;37m□[1;5mJ[1;5m□[1;5m□[1;5m□[1;5mo[1;5m□[1;5mX[1;5m□[1;5mU[1;5m□[1;5mD[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5mH[1;5m□[1;5m□[1;5m,[1;5m [1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5mk[1;5m□[1;5mH[1;5m-[1;5m-[1;5m□[1;5mC[1;5m□[1;5mg[1;5m□[1;5mQ[1;5m□[1;5mG[1;5m□[1;5m□[1;5m□[1;5mX[1;5m□[1;5m{[1;5m□[1;5mF[1;5m![1;5m![0m

[0;1;33m□[1mC[1m□[1mg[1m□[1mQ[1m□[1mG[1m□[1m□[1m□[1m□[1m□[1mY[1m□[1mj[1m□[1m□[1m:[1m [1m□[1mu[1m [1m□[1mA[1m□[1mo[1m□[1mo[1m□[1m□[1m□[1mp[1m□[1m□[1m□[1m□[1m□[1mQ[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m~[1m,[1m [1m□[1mu[1m□[1mn[1m□[1m□[1m□[1m□[1m□[1mb[1m□[1m□[1m□[1m@[1m□[1m□[1m,[1m□[1m@[1m□[1m□[1m□[1m□[1m□[1mK[1m□[1mS[1m□[1mi[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1mC[1m□[1mv[0m

[0;1;31m□[1m□[1m□[1m□[1m□[1mC[1m□[1mg[1m□[1mQ[1m□[1mG[1m□[1m□[1m□[1mQ[1m□[1m□[1m□[1m□[1m□[1mA[1m□[1mT[0m

[0;1m□[1mu[1m□[1m□[0m剑君十二恨[0;1m□[1m□[1m□[1m][1m□[1ms[1m□[1m□[1m□[1mP[1m□[1m□[1m□[1ma[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1mX[1m□[1m@[1m□[1mP[1m□[1mA[1m□[1m□[1m□[1mX[1m□[1my[1;36m□[1mH[1m□[1mB[1;31m□[1mP[1m□[1m□[1;34m□[1mx[1;37m□[1mz[1m□[1mV[1m□[1mp[1m□[1mg[1m□[1m□[1m□[1m□[1m□[1mh[1m□[1mC[0m
( 你[31m已经陷入半昏迷状态，随时都可能摔倒晕去。[0m )
[0;1m□[1mu[1m□[1m□[0m剑君十二恨[0;1m□[1m□[1m□[1m][1m□[1ms[1m□[1m□[1m□[1mP[1m□[1m□[1m□[1ma[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1mX[1m□[1m@[1m□[1mP[1m□[1mA[1m□[1m□[1m□[1mX[1m□[1my[1;36m□[1mH[1m□[1mB[1;31m□[1mP[1m□[1m□[1;34m□[1mx[1;37m□[1mz[1m□[1mV[1m□[1mp[1m□[1mg[1m□[1m□[1m□[1m□[1m□[1mh[1m□[1mC[0m
( 你[31m已经陷入半昏迷状态，随时都可能摔倒晕去。[0m )
[0;1m□[1mu[1m□[1m□[0m剑君十二恨[0;1m□[1m□[1m□[1m][1m□[1ms[1m□[1m□[1m□[1mP[1m□[1m□[1m□[1ma[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1mX[1m□[1m@[1m□[1mP[1m□[1mA[1m□[1m□[1m□[1mX[1m□[1my[1;36m□[1mH[1m□[1mB[1;31m□[1mP[1m□[1m□[1;34m□[1mx[1;37m□[1mz[1m□[1mV[1m□[1mp[1m□[1mg[1m□[1m□[1m□[1m□[1m□[1mh[1m□[1mC[0m
( 你[31m已经陷入半昏迷状态，随时都可能摔倒晕去。[0m )
[0;1m□[1mu[1m□[1m□[0m剑君十二恨[0;1m□[1m□[1m□[1m][1m□[1ms[1m□[1m□[1m□[1mP[1m□[1m□[1m□[1ma[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1mX[1m□[1m@[1m□[1mP[1m□[1mA[1m□[1m□[1m□[1mX[1m□[1my[1;36m□[1mH[1m□[1mB[1;31m□[1mP[1m□[1m□[1;34m□[1mx[1;37m□[1mz[1m□[1mV[1m□[1mp[1m□[1mg[1m□[1m□[1m□[1m□[1m□[1mh[1m□[1mC[0m
( 你[31m已经陷入半昏迷状态，随时都可能摔倒晕去。[0m )
[0;1m□[1mu[1m□[1m□[0m剑君十二恨[0;1m□[1m□[1m□[1m][1m□[1ms[1m□[1m□[1m□[1mP[1m□[1m□[1m□[1ma[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1mX[1m□[1m@[1m□[1mP[1m□[1mA[1m□[1m□[1m□[1mX[1m□[1my[1;36m□[1mH[1m□[1mB[1;31m□[1mP[1m□[1m□[1;34m□[1mx[1;37m□[1mz[1m□[1mV[1m□[1mp[1m□[1mg[1m□[1m□[1m□[1m□[1m□[1mh[1m□[1mC[0m
( 你[31m已经陷入半昏迷状态，随时都可能摔倒晕去。[0m )
[0;1m□[1mu[1m□[1m□[0m剑君十二恨[0;1m□[1m□[1m□[1m][1m□[1ms[1m□[1m□[1m□[1mP[1m□[1m□[1m□[1ma[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1mX[1m□[1m@[1m□[1mP[1m□[1mA[1m□[1m□[1m□[1mX[1m□[1my[1;36m□[1mH[1m□[1mB[1;31m□[1mP[1m□[1m□[1;34m□[1mx[1;37m□[1mz[1m□[1mV[1m□[1mp[1m□[1mg[1m□[1m□[1m□[1m□[1m□[1mh[1m□[1mC[0m
( 你[31m已经陷入半昏迷状态，随时都可能摔倒晕去。[0m )
[0;1m□[1mu[1m□[1m□[0m剑君十二恨[0;1m□[1m□[1m□[1m][1m□[1ms[1m□[1m□[1m□[1mP[1m□[1m□[1m□[1ma[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1mX[1m□[1m@[1m□[1mP[1m□[1mA[1m□[1m□[1m□[1mX[1m□[1my[1;36m□[1mH[1m□[1mB[1;31m□[1mP[1m□[1m□[1;34m□[1mx[1;37m□[1mz[1m□[1mV[1m□[1mp[1m□[1mg[1m□[1m□[1m□[1m□[1m□[1mh[1m□[1mC[0m
( 你[31m已经陷入半昏迷状态，随时都可能摔倒晕去。[0m )
[0;1m□[1mu[1m□[1m□[0m剑君十二恨[0;1m□[1m□[1m□[1m][1m□[1ms[1m□[1m□[1m□[1mP[1m□[1m□[1m□[1ma[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1mX[1m□[1m@[1m□[1mP[1m□[1mA[1m□[1m□[1m□[1mX[1m□[1my[1;36m□[1mH[1m□[1mB[1;31m□[1mP[1m□[1m□[1;34m□[1mx[1;37m□[1mz[1m□[1mV[1m□[1mp[1m□[1mg[1m□[1m□[1m□[1m□[1m□[1mh[1m□[1mC[0m
( 你[31m已经陷入半昏迷状态，随时都可能摔倒晕去。[0m )
[0;1m□[1mu[1m□[1m□[0m剑君十二恨[0;1m□[1m□[1m□[1m][1m□[1ms[1m□[1m□[1m□[1mP[1m□[1m□[1m□[1ma[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1mX[1m□[1m@[1m□[1mP[1m□[1mA[1m□[1m□[1m□[1mX[1m□[1my[1;36m□[1mH[1m□[1mB[1;31m□[1mP[1m□[1m□[1;34m□[1mx[1;37m□[1mz[1m□[1mV[1m□[1mp[1m□[1mg[1m□[1m□[1m□[1m□[1m□[1mh[1m□[1mC[0m
( 你[31m已经陷入半昏迷状态，随时都可能摔倒晕去。[0m )
[0;1m□[1mu[1m□[1m□[0m剑君十二恨[0;1m□[1m□[1m□[1m][1m□[1ms[1m□[1m□[1m□[1mP[1m□[1m□[1m□[1ma[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1mX[1m□[1m@[1m□[1mP[1m□[1mA[1m□[1m□[1m□[1mX[1m□[1my[1;36m□[1mH[1m□[1mB[1;31m□[1mP[1m□[1m□[1;34m□[1mx[1;37m□[1mz[1m□[1mV[1m□[1mp[1m□[1mg[1m□[1m□[1m□[1m□[1m□[1mh[1m□[1mC[0m
( 你[31m已经陷入半昏迷状态，随时都可能摔倒晕去。[0m )

[0;1;31m□[1mA[1m□[1m□[1m□[1m□[1m□[1me[1m□[1m@[1m□[1m□[1m□[1mM[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[1m][1m□[1m□[1m□[1m□[1m□[1mD[1m□[1mF[1m.[1m.[1m.[1m.[1m [0m
 
你死了

[31m阴曹入口  [0m-
    你已经来到了阴间的入口。虽然距离地府还有一段距离，但是你已经
感受到阵阵刺骨的阴风。四周一片荒凉，但是却鬼影幢幢，看来这边的夜
总会蛮热闹的，应该不愁没伴。南边和上面好像是和人世间相通的管道，
不过好像有一股无形的力量隔开这两个不同的世界，看来要从这两个方向
回去不是那么简单的事情。

    这里明显的出口是 [0;1mn[1mo[1mr[1mt[1mh[0m
ITEM,
	]) );
	set( "object", ([
		"amount4"  : 1,
		"file1"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file9"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount5"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file10"   : "/open/magic-manor/obj/hwa-je-icer",
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount3"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount7"  : 1,
		"amount10" : 1,
		"file7"    : "/open/magic-manor/obj/fon-sky-sword",
	]) );
	set( "build", 13149 );
	set( "no_transmit", 1 );
	setup();                                             
	call_other( "/obj/board/ou-cloud-club_b", "???" );
	}
