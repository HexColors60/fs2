// edit.c

varargs int edit(function callback, string text)
{
	write("结束离开用 '.'，取消输入用 '~q'，使用内建列编辑器用 '~e'。\n");
	write("─────────────────────────────\n");
	if (!text) input_to("input_line", "", callback);
	else {
	  write (text);
	  input_to("input_line", text, callback);
	}
	return 1;
}

void input_line(string line, string text, function callback)
{
	if( line=="." ) {
		(*callback)(text);
		return;
	} else if( line=="~q" ) {
		write("输入取消。\n");
		return;
	} else if( line=="~e" ) {
	} else
		text += line + "\n";
	input_to("input_line", text, callback);
}
