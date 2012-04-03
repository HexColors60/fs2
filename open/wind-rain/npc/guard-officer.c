#include <ansi.h>

inherit F_WIND_GUARD;

void create()
{
	set_name("掌兵使",({"soldier officer","officer"}));
	set("gender","男性");
          set("attitude","heroism");
	set("combat_exp",440);
        set("age",47);
		set("str", 44);
		set("cor", 24);
		set("cps", 18);
		set("per", 24);
		set("int", 42);
	set("soldier_list",([
	"gold-guard":"金护卫(gold-guard)",
	"wind-guard":"风护卫(wind-guard)",
        "thin-guard":"细护卫(thin-guard)",
        "rain-guard":"雨护卫(rain-guard)",
	]));
	set("soldier_lv",([
	"gold-guard":30,
	"wind-guard":25,
	"thin-guard":20,
        "rain-guard":15,
	]));
	setup();
}

