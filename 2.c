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

void hanshu4(adj *q)
{
	int a,b;
	int i,j;
	int xnum;//定义多景点个数
	
	system("clear");
	while(1)
	{
		printf("请输入要游览的学校景点个数:");
		scanf("%d",&xnum);
		if(xnum>=2 && xnum<=max)	break;
		printf("请至少输入2个景点并且小于最大景点数\n");
	}
	int jd[max];//用来保存景点编号
	
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
				scanf("%d",&jd[1]);
				if(jd[1]<=q->diannum && jd[1]>=1)	break;
				printf("输入错误，请重新输入!\n");
			}
			for(i=2;i<=xnum;i++)
			{
				while(1)
	                        {
	                                printf("请输如第%d个编号:",i);
	                                scanf("%d",&jd[i]);
	                                if(jd[i]<=q->diannum && jd[i]>=1)       break;
	                                printf("输入错误，请重新输入!\n");
	                        }

			}
		
			break;
		}
		else if(a==2)
		{
			//system("clear");
			char qi[20];
			while(1)
			{
				printf("请输入起点名称:");
				scanf("%s",qi);
				jd[1]=change1(q,qi);
				if(jd[1]!=-1)	break;
				printf("输入错误，请重新输入!\n");
			}
			for(i=2;i<=xnum;i++)
			{
				
				while(1)
                	        {
                	                printf("请输入%d景点名称:",i);
                        	        scanf("%s",qi);
                                	jd[i]=change1(q,qi);
                               		if(jd[i]!=-1)   break;
                               		printf("输入错误，请重新输入!\n");
                        	}
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
	
	//利用最短路径和贪心来计算最佳路线
	int dist[max];
	int prev[max];
	int tmp;
	int tmplong;
 
	for(i=1;i<xnum;i++)
	{
		Dijkstra(q,jd[i],dist,prev);
		tmp=i+1;
		tmplong=dist[jd[i+1]];
		for(j=i+2;j<=xnum;j++)
		{
			if(dist[jd[j]]<tmplong)
			{
				tmplong=dist[jd[j]];
				tmp=j;
			}

		}
		//交换jd[i+1]&jd[tmp]

		tmplong=jd[i+1];
		jd[i+1]=jd[tmp];
		jd[tmp]=tmplong;
	}

	//输出
	int zhdian;//临时变量
	int lu[max];
	printf("您的最佳游览路线如下所示:\n");
	for(i=1;i<xnum;i++)
	{
		j=1;
		Dijkstra(q,jd[i],dist,prev);
		printf("从%s到%s,距离为%d，路径为:",q->dian[jd[i]].name,q->dian[jd[i+1]].name,dist[jd[i+1]]);
		zhdian=jd[i+1];
		while(1)
		{
			lu[j++]=zhdian;
			zhdian=prev[zhdian];
			if(zhdian==jd[i])
			{
				lu[j]=zhdian;
				break;
			}
		}
		for(;j>1;j--)
		{
			printf("%s->",q->dian[lu[j]].name);
		}
		printf("%s\n",q->dian[lu[j]].name);

	}
	printf("输入1继续查询，输入其他任意数字键退出:");
	scanf("%d",&a);
	if(a==1)	hanshu4(q);
	return;
}

void hanshu5(adj *q)
{

}

void hanshu6(adj *q)
{
	int a,b;
	int i,j;
	int qidian;

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
				printf("请输入广度遍历起点编号:");
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
				printf("请输入广度遍历起点名称:");
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

	//建立一个队列
	struct duilie
	{
		int date[500];
		int top;
		int now;
	};
	
	struct duilie dui;
	int vist[max];
	int tmp;
	
	tmp=0;
	dui.now=1;
	dui.top=1;
	for(i=0;i<500;i++)
	{
		dui.date[i]=0;
	}
	for(i=0;i<=q->diannum;i++)
	{
		vist[i]=0;
	}
	
	vist[qidian]=1;
	printf("根据广度遍历的是:\n");
	printf("%d%s  ",qidian,q->dian[qidian].name);
	tmp++;
	//进队列
	dui.date[dui.now]=qidian;
	dui.now++;
	while(dui.top!=dui.now)
	{
		//出队列
		i=dui.date[dui.top];
		dui.top++;
	
		for(j=1;j<=q->diannum;j++)
		{
			if(q->xian[i][j]<maxlong&& !vist[j])
			{
				vist[j]=1;
				printf("%d%s ",j,q->dian[j].name);
				tmp++;
				if(tmp%5==0) 	printf("\n");
				//进队列
				dui.date[dui.now]=j;
				dui.now++;
			}
		}	
	}
	 printf("输入1继续查询，输入其他任意数字键退出:");
        scanf("%d",&a);
        if(a==1)        hanshu6(q);
        return;

}

void hanshu7(adj *q)
{
	int a,b;
	int i,j;
	int qidian;

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
				printf("请输入深度遍历起点编号:");
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
				printf("请输入深度遍历起点名称:");
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
	
	int vist[max];

	for(i=1;i<=q->diannum;i++)
	{
		vist[i]=0;
	}

	printf("按照深度遍历搜索:\n");
	DFS(q,qidian,vist);
	printf("输入1继续查询，输入其他任意数字键退出:");
        scanf("%d",&a);
        if(a==1)        hanshu7(q);
        return;

}

void hanshu8(adj *q)
{

}



























































