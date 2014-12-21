#include "1.c"
#include "print.c"
#include "2.c"
main()
{
	char a[20];
	print1();
	adj q;
	adj *p=&q;
	scanffile(p);
	print2(p);
	print5(p);
	hanshu0(p);
}
