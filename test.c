#include "1.c"
#include "print.c"
#include "2.c"
main()
{
	adj p;
	adj *q=&p;
	scanffile(q);

	int a;
	
	while(1)
	{		
		system("clear");
		printmain();
		scanf("%d",&a);
		if(a==0)	hanshu0(q);
		if(a==1)	hanshu1(q);
		if(a==2)	hanshu2(q);
		if(a==3)	hanshu3(q);
		if(a==4)	hanshu4(q);
		if(a==5)	hanshu5(q);
		if(a==6)	hanshu6(q);
		if(a==7)	hanshu7(q);
		if(a==8)	hanshu8(q);
		if(a==9)	break;
		
	}

	
}
