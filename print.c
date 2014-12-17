
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
	for(i=0;i<=q->diannum;i++)
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
		printf("%s",q->dian[m].shuoming);
	}
}

