// tar 0.1 11/30/1999
// 用来将整个 mud 压成一个档的
// 目前还没有压缩功能，只有 tar 功能。
// wade@Fantasy.Space

inherit NPC;

string *dirs, *files;   // 存在缓冲区内的目录, 存在缓冲区内的档案
int    ndirs, nfiles;   // 缓冲区内的目录与档案位置
string  fn;             // tar file name
int     start, tfiles;  // start 指示是否还在压，tfiles 指示压了多少档

int extract (string sub_dir);

void create()
{
  mixed *get_dirs;
  int   cur;

  set_name( "tar", ({ "tar" }) );
  set("long", "档案压缩机\n");
  set_heart_beat (1);
  dirs = allocate (1000);       // 给大一点又如何？！
  files= allocate (1000);
  ndirs = nfiles = start = tfiles = 0;

  // 要注意，如果不是根目录，要像下面的格式：
  // get_dir ("/obj/.", -1);
  // 这样才能取回 /obj 目录所有档案的资料, 如果是：
  // get_dir ("/obj", -1);
  // 只会取回 /obj 的资料，而不是目录下的。
  //
  // 根目录比较特殊，不要用 extract() 来做。
  get_dirs = get_dir ("/", -1);

  for (cur=0; cur < sizeof (get_dirs); cur++)   // 将档案与目录分开
  {
    if (get_dirs[cur][1] == -2) {               // 有些目录不要压
      if (get_dirs[cur][0] != "tmp" &&
          get_dirs[cur][0] != "log" &&
          get_dirs[cur][0] != "ftp" &&
          get_dirs[cur][0] != "bin")
      {
        dirs[ndirs++] = "/" + get_dirs[cur][0] + "/";   // 目录保持有斜线
      }                                                 // 从根目录开始
    }
    else
      files[nfiles++] = "/" + get_dirs[cur][0];
  }
  write ("已经有："+nfiles+"/"+ndirs+" 在缓冲区中…\n");

  setup();
}

// 设定可以启动或关闭，启动时设定档名
void init ()
{
  add_action ("tar", "tar");
  add_action ("stoptar", "stoptar");
}

// 这个是将 sub_dir 目录下的档案分成 dirs, 跟 files
int extract (string sub_dir)
{
  mixed *get_dirs;
  int   cur;
 
  ndirs--;      // 少给它前进一格再说。

  // 要注意，如果不是根目录，要像下面的格式：
  // get_dir ("/obj/.", -1);
  // 这样才能取回 /obj 目录所有档案的资料, 如果是：
  // get_dir ("/obj", -1);
  // 只会取回 /obj 的资料，而不是目录下的。
  get_dirs = get_dir (sub_dir, -1);

  if (sizeof (get_dirs) > 0)    // 不是空目录压才有意思
    for (cur=0; cur < sizeof (get_dirs); cur++) // 将档案与目录分开
    {
      if (get_dirs[cur][1] == -2)                       // 有些目录不要压
        dirs[ndirs++] = sub_dir + get_dirs[cur][0] + "/";// 目录保持有斜线
      else
        files[nfiles++] = sub_dir + get_dirs[cur][0];
    }
  return 1;
}

// 下命令时像：tar /fs.tar      参数是压成该档的档名
// 自己要注意压缩档是不是已经在了，不要给压进去。
int tar (string arg)
{
  if (!arg) {   // 用来查询还有多少没进行…
    if (start) {
      write ("还有："+nfiles+"/"+ndirs+" 在缓冲区中…\n");
    }
    else
      write ("语法：tar tar_file_name  --> tar /mud.tar\n");
    return 1;
  }

  if (!start) { // 如已开始，就不要吵它了。
    fn = arg;
    // rm (fn); // 已存在的话，就给他清掉？我看还是手动清好了。
    start = 1;
  }
  write ("压缩中……\n");
  return 1;
}

int stoptar (string arg)
{
  if (start) start = 0;
  write ("停止压缩。\n");
  return 1;
}

void heart_beat()
{
  string buf;
  string        *tmp_buf;       // 为了存成行数而不是档案大小
  int           ln;             // # of lines in a file.

  if (start) {
    if (nfiles > 0) {     // 表示还有档案还没压完
      if (files[nfiles-1] != fn) {      // 不能压自己吧！
        buf = read_file (files[nfiles-1]);      // 记得，指标的位置。
        if (sizeof (buf) > 0) {// 不要读空档出来
          tmp_buf = explode (buf, "\n");
          // 记得先把档名存进去
          write_file (fn, files[nfiles-1]+"\n"+sizeof (tmp_buf) + "\n"+ buf);
        }
        nfiles--;               // 不论如何，总要愈来愈少档嘛！
      }
    }
    else if (ndirs > 0) {       // 已经压完了，请再从目录中读出要压的档名来。
      extract (dirs [ndirs-1]);
    }
    else {
      start = 0;
    }
    write ("还有："+nfiles+"/"+ndirs+" 在缓冲区中…\n");
  }
}
