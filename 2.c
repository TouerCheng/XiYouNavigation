void hanshu0(adj *q)
{
	system("clear");

	int a,b;
	int i,j;
	int qidian;
	
	//
	while(1)
	{
		printf("是否查看景点及其编号(查看输入1，不查看输入2，退出输入0：)");
		scanf("%d",&a);
		if(a==1)
		{
			system("clear");
			print5(q);
			printf("\n");
			break;
		}
		else if(a==2)
		{
			system("clear");
			break;
		}
		else if(a==0)
		{
			return;
		}
		else
		{
			printf("输入错误!\n");
		}
	}

	while(1)
	{
		printf("请选择编号或者名称输入(编号输入1，名称输入2，退出输入0：)");
		scanf("%d",&a);
		if(a==1)
		{
			//system("clear");
			while(1)
			{
				printf("请输入编号:");
				scanf("%d",&qidian);
				if(qidian<=q->diannum && qidian>=1)	break;
				printf("输入错误，请重新输入!\n");
			}
		/*	while(1)
			{
				printf("请输入终点编号:");
				scanf("%d",&zhdian);
				if(zhdian<=q->diannum && zhdian>=1)     break;
                                printf("输入错误，请重新输入!\n");

			}
		*/
			break;
		}
		else if(a==2)
		{
			//system("clear");
			char qi[20];
			while(1)
			{
				printf("请输入名称:");
				scanf("%s",qi);
				qidian=change1(q,qi);
				if(qidian!=-1)	break;
				printf("输入错误，请重新输入!\n");
			}
		/*
			while(1)
			{
				printf("请输入终点名称:");
				scanf("%s",zh);
				zhdian=change1(q,zh);
                                if(qidian!=-1)  break;
                                printf("输入错误，请重新输入!\n");

			}
		*/
			break;
		}
		else if(a==0)
		{
			return;
		}
		else
		{
			printf("输入错误!\n");
		}
	}
	
	print4(q,qidian);
	
	printf("继续查询按1,其他数字键退出:");
	scanf("%d",&a);
	if(a==1)	hanshu0(q);
	return;
}
void hanshu1(adj *q)
{	
	system("clear");
	print2(q);
	printf("\n");
	printf("输入任意键返回上层.....\n");
	getchar();
	return;
}

void hanshu2()
{
	system("clear");
	print1();
	printf("\n");
        printf("输入任意键返回上层.....\n");
        getchar();
        return;
}

void hanshu3(adj *q)
{
	system("clear");

	int a,b;
	int i,j;
	int qidian,zhdian;
	
	//
	while(1)
	{
		printf("是否查看景点及其编号(查看输入1，不查看输入2，退出输入0：)");
		scanf("%d",&a);
		if(a==1)
		{
			system("clear");
			print5(q);
			printf("\n");
			break;
		}
		else if(a==2)
		{
			system("clear");
			break;
		}
		else if(a==0)
		{
			return;
		}
		else
		{
			printf("输入错误!\n");
		}
	}

	while(1)
	{
		printf("请选择编号或者名称输入(编号输入1，名称输入2，退出输入0：)");
		scanf("%d",&a);
		if(a==1)
		{
			//system("clear");
			while(1)
			{
				printf("请输入起点编号:");
				scanf("%d",&qidian);
				if(qidian<=q->diannum && qidian>=1)	break;
				printf("输入错误，请重新输入!\n");
			}
			while(1)
			{
				printf("请输入终点编号:");
				scanf("%d",&zhdian);
				if(zhdian<=q->diannum && zhdian>=1)     break;
                                printf("输入错误，请重新输入!\n");

			}
			break;
		}
		else if(a==2)
		{
			//system("clear");
			char qi[20],zh[20];
			while(1)
			{
				printf("请输入起点名称:");
				scanf("%s",qi);
				qidian=change1(q,qi);
				if(qidian!=-1)	break;
				printf("输入错误，请重新输入!\n");
			}
			while(1)
			{
				printf("请输入终点名称:");
				scanf("%s",zh);
				zhdian=change1(q,zh);
                                if(qidian!=-1)  break;
                                printf("输入错误，请重新输入!\n");

			}
			break;
		}
		else if(a==0)
		{
			return;
		}
		else
		{
			printf("输入错误!\n");
		}
	}
	
	//调用迪杰斯特拉最短路径的输出
	int prev[max];
	int dist[max];
	system("clear");
	Dijkstra(q,qidian,dist,prev);
	
	int lu[max];//记录路径
	i=1;
	printf("从%s到%s的最短距离为%d，路径为:",q->dian[qidian].name,q->dian[zhdian].name,dist[zhdian]);
	while(1)
	{
		lu[i++]=zhdian;
		zhdian=prev[zhdian];
		if(zhdian==qidian)
		{
			lu[i]=zhdian;
			break;
		}
	}
	for(;i>1;i--)
	{
		printf("%s->",q->dian[lu[i]].name);
	}
	printf("%s\n",q->dian[lu[i]].name);


	printf("输入1继续查询，输入其他任意键退出:");
	scanf("%d",&a);
	if(a==1)	hanshu3(q);
	return;
}



















































