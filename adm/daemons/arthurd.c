// arthurd.c
//
//      用来放不知道该放哪的 function
//
//                                              Created by Arthur

void create()
{
        seteuid(ROOT_UID);
}

// 用来删除整个目录, 包括目录下的档案
int remove_all_dir(string dir)
{
        mixed   *files;
        int     i;

        // 设定 euid
        seteuid(geteuid(previous_object()));

        if( dir[<0] != '/' )
                dir += "/";

        files   = get_dir(dir, -1);
        i       = sizeof(files);

        while(i--) 
        {
                // 目录喔, 那就使用传说中的递回
                if( files[i][1] == -2 )
                        remove_all_dir( dir+files[i][0] );
                else 
                        rm( dir+files[i][0] );
        }
        rmdir(dir);
        return 1;
}
