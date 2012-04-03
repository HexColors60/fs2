inherit ROOM;
void create() {
	set( "short", "$CYN$威洛$NOR$的$MAG$研$YEL$究$HIW$室$NOR$" );
	set( "light_up", 1 );
	set( "owner", "welo" );
	set( "exits", ([
		"south"     : "/open/clan/red_fire/room/room115",
	]) );
	set( "long", @LONG
这是$HIW$大侠$CYN$威洛$NOR$的个人专属$MAG$研$YEL$究$HIW$室$NOR$，$CYN$威洛$NOR$平常在这里
研究各种武学的奥妙，包括最新的$YEL$剑术口诀$NOR$，$CYN$内功心法$NOR$
，他派的$RED$咒术$MAG$法术$NOR$，以及一些令人为之惊叹的$RED$特殊攻击$NOR$
。不要误会，$CYN$威洛$NOR$并不是想要转投他派，只是他觉得多
接触其他的武术对自己功夫的精进绝对是有帮助的。$MAG$研
$YEL$究$HIW$室$NOR$里面有着一张$HIW$大桌子$NOR$，桌子上放着凌乱的$CYN$纸张$NOR$，你
定眼一看纸上的内容，竟然全是$CYN$威洛$NOR$破解他派武术的$RED$心
$RED$得$NOR$，找个机会应该把这些$CYN$威洛$NOR$行走江湖多年的$MAG$心血结晶$NOR$
偷偷抄写一份下来才对。
LONG);
	setup();
	replace_program(ROOM);
}
