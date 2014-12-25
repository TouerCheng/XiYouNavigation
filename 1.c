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

	int i,j;
	int m,n;

	//初始化
	for(i=0;i<max;i++)
	for(j=0;j<max;j++)
	{
		q->xian[i][j]=maxlong;
	}


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


//最短路径

void Dijkstra(adj *a, int v, int *dist, int *prev)
{   
     int i,j;
     int s[max];    // 判断是否已存入该点到S集合中
     for(i=1; i<=a->diannum; i++)
     {
         dist[i] = a->xian[v][i];
         s[i] = 0;     // 初始都未用过该点
         if(dist[i] == maxlong)
             prev[i] = 0;
         else
             prev[i] = v;
     }
     dist[v] = 0;
     s[v] = 1;
  
     // 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
     // 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
     for(i=2; i<=a->diannum; ++i)
     {
         int tmp = maxlong;
         int u = v;
         // 找出当前未使用的点j的dist[j]最小值
         for( j=1; j<=a->diannum; ++j)
             if((!s[j]) && dist[j]<tmp)
             {
                 u = j;              // u保存当前邻接点中距离最小的点的号码
                 tmp = dist[j];
             }
         s[u] = 1;    // 表示u点已存入S集合中
  
         // 更新dist
         for( j=1; j<=a->diannum; ++j)
             if((!s[j]) && (a->xian[u][j])<maxlong)
             {
                 int newdist = dist[u] + a->xian[u][j];
                 if(newdist < dist[j])
                 {
                     dist[j] = newdist;
                     prev[j] = u;
                 }
             }
     }
}

//深度遍历
void DFS(adj *q,int i,int vist[])
{
	static tmp=0;
	int j;
	vist[i]=1;
	printf("%d%s ",i,q->dian[i].name);
	tmp++;
	if(tmp%5==0)
	{
		printf("\n");
	}
	for(j=1;j<=q->diannum;j++)
	{
		if(q->xian[i][j]<maxlong && !vist[j])
		{
			DFS(q,j,vist);
		}
	}
}











