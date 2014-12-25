void printmain()
{
	printf("         输入编号查询信息       \n");
	printf("      0.查询单个景点信息\n");
	printf("      1.查询所有景点及其信息  \n");
	printf("      2.查询校园图景\n");
	printf("      3.查询俩景点之间点最短路径                 \n");
	printf("      4.查询多景点之间的最佳访问路径\n");
	printf("      5.查询俩景点之间的所有访问路径\n");
	printf("      6.广度优先搜索校园全部景点        \n");
	printf("      7.深度优先搜索校园全部景点\n");
	printf("      8.添加（删除）景点或者线路\n");
	printf("      9.退出\n");
	printf("      请输入：");
}
void print1(void)
{
printf("                |  |                 超市 \n");
printf("                |  |                  |    \n");                       
printf("                |  |         宿舍——旭日院——西宿舍—————— \n");   
printf("                |  |         |          |             |  \n");  
printf("                |  |       体育场       |            美广  \n");
printf("                |天|         |          |             |     \n");
printf("  教师公寓————— |  |—————  图书馆 ——————篮球场———————医院    \n");
printf("         |      |桥|         |              |         |     \n");
printf("         |      |  |       大活             |         |     \n");
printf(" 澡堂 —饭堂     |  |         |              实       西浴池   \n");
printf("  |             |  |         |              验         \n");
printf("东宿            |  |         |              楼         \n");
printf("区舍            |  |         |              |          \n");
printf("  东教学楼—东门 |  |  行政楼—————————————西教学楼——交流中心 \n");
printf("         |      |  |         |              |    \n");
printf("      东操场    |  |        喷泉—————————————   \n");
printf("                |  |         |      \n");
printf("                |  |        西门  \n");
return;
}

//显示所有图点信息
void print2(adj *q)
{
	int i,j;
	int m;
	//对齐输出
	for(i=1;i<=q->diannum;i++)
	{
		printf("%s",q->dian[i].name);
		m=strlen(q->dian[i].name);
		m=m/3;
		for(j=6-m;j>0;j--)
		{
			printf("  ");
		}	
		printf("%s\n",q->dian[i].shuoming);
	}
}

//给站点名字输出信息
void print3(adj *q,char name[])
{
	int m;
	m=change1(q,name);
	if(m==-1)
	{
		printf("不存在这个地点\n");
	}
	else
	{
		printf("%s  %s\n",q->dian[m].name,q->dian[m].shuoming);
	}
}

//给编号输出信息
void print4(adj *q,int n)
{
	if(n<1||n>(q->diannum))
	{
		printf("不存在这个编号\n");
	}
	else
	{
	        printf("%s %s\n",q->dian[n].name,q->dian[n].shuoming);
	}
}


//所有站点编号输出

void print5(adj *q)
{
	
	int i,j;
	int m;
	
	//对齐输出
	for(i=1;i<=q->diannum;i++)
        {
                printf("%d%s",i,q->dian[i].name);
                m=strlen(q->dian[i].name);
                m=m/3;
                for(j=6-m;j>0;j--)
                {
                        printf("  ");
                }
		if(i>=10)	printf("\b");
		if(i%5==0)	printf("\n");

        }

		
}


















