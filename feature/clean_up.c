// clean_up.c
// by Annihilator@ES2

int clean_up()
{
	object *inv;
	int i;

	if( !clonep() && this_object()->query("no_clean_up") )
		return 1;

	if( interactive(this_object()))
		return 1;

	// by babe
	// 若此物件已被其他物件所包含, 就不再重复 clean_up, 以节省时间
	// 请勿再 environment()->query("no_clean_up");
	if(environment())
		return 1;

	inv = all_inventory();
	for( i=sizeof(inv)-1; i>=0; i-- )
		if(interactive(inv[i]))
			return 1;

	destruct(this_object());

	return 0;
}
