#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 50	//定义顶点
#define maxlong 500000	//定义最远距离

//定义图点信息
typedef struct dian1
{
	char name[20];
	char shuoming[200];
}dian1;


//定义矩阵
typedef struct adj
{
	int diannum;
	int xiannum;
	dian1 dian[max];
	int xian[max][max];	
}adj;


//从文件中读入图的信息
void scanffile(adj *q)
{
	int i;
	int m,n;

	FILE *fp;
	fp=fopen("file.txt","rt");
	
	//图点信息
	fscanf(fp,"%d",&q->diannum);
	for(i=1;i<=q->diannum;i++)
	{
		fscanf(fp,"%s",q->dian[i].name);
		fscanf(fp,"%s",q->dian[i].shuoming);
	}

	//图线信息
	fscanf(fp,"%d",&q->xiannum);
	for(i=1;i<=q->xiannum;i++)
	{
		fscanf(fp,"%d",&m);
		fscanf(fp,"%d",&n);
		fscanf(fp,"%d",&q->xian[m][n]);
		q->xian[n][m]=q->xian[m][n];
	}
	
	fclose(fp);
}

//名字返回编号
int change1(adj *q,char name[])
{
	int i;
	for(i=1;i<=q->diannum;i++)
	{
		if(strcmp(name,q->dian[i].name)==0)
		{
			return i;
		}
	}
	return -1;
}


















