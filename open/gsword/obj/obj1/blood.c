#include <weapon.h>
  inherit ITEM;
void create()
{
set_name("魔 血",({"blood"}));
set("unit","滩");
set("long","这滩奇怪的血渍竟被一道道奇怪的符咒包围...你可以试着解开它

      (tear taoistfigure)
\n");
  set("no_get",1);
        setup();
}
