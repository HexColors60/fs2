inherit EQUIP;
void create()
{
        set_name("幽冥臂环 ",({"ghost armband","armband"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","传说此臂环，乃是叶秀杀在18岁时，进入炼妖壶中，所取得的\n");
        set("unit","个");
        set("value",10000);
        set("material","crimsonsteel");
        set("armor_type","armbands");
        set("armor_prop/armor",5);
        set("armor_prop/throwing",5);
        }
        setup();
}