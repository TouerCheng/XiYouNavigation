#include "1.c"
#include "print.c"
main()
{
	char a[20];
	print1();
	adj q;
	adj *p=&q;
	scanffile(p);
	print2(p);
	scanf("%s",a);
	print3(p,a);

}
