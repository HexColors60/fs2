inherit ITEM;

void create()
{
        set_name( "锦扇",({"fan"}));
        set_weight(300);
        if( clonep() )
          set_default_object(__FILE__);
        else {
          set("unit", "面");
          set("long","
一面圆形的小扇子，上面绘着一对鸳鸯戏水的图样。\n");
          set("value", 80);
}
        setup();
}
