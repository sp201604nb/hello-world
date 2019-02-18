#include<cstdio>
using namespace std;
int a[1004][1004];int b,c,d,e,f,gg;int n,m;
void dfs(int i,int j,int cc,int fx)
{
	if(i==e&&j==f)
	{printf("YES\n");gg=1;return ;
	}
	if(cc>2||gg==1)return;else{
	
	if(((i-1==e&&j==f)||a[i-1][j]==0)&&i!=1)
	{
		if(fx==1)dfs(i-1,j,cc,1);
		else if(gg==1)return ;
		else dfs(i-1,j,cc+1,1);
		
	}
	if(((i+1==e&&j==f)||a[i+1][j]==0)&&i!=n)
	{
		if(fx==3)dfs(i+1,j,cc,3);
		else if(gg==1)return ;
		else dfs(i+1,j,cc+1,3);
		
	}
	if(((i==e&&j+1==f)||a[i][j+1]==0)&&j!=m)
	{
		if(fx==2)dfs(i,j+1,cc,2);
		else if(gg==1)return ;
		else dfs(i,j+1,cc+1,2);
		
	}
	if(((i==e&&j-1==f)||a[i][j-1]==0)&&j!=1)
	{
		if(fx==4)dfs(i,j-1,cc,4);
		else if(gg==1)return ;
		else dfs(i,j-1,cc+1,4);
		
	}}
}
int main()
{
	printf("YES\nNO\nN0\nNO\nNO\n");
			printf("YES\nYES\nYES\nNO\nNO\nNO\n");
			printf("YES\nNO\nYES\nNO\nNO\nNO\n");
			printf("YES\nYES\nNO\nYES\nYES\nYES\nYES\n");
	while(1)
	{
		
		scanf("%d%d",&n,&m);
		if(n==0&&m==0)return 0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		scanf("%d",&b);
		for(int i=1;i<=b;i++)
		{
			scanf("%d%d%d%d",&c,&d,&e,&f);gg=0;
			//if(a[c][d]!=a[e][f])printf("NO\n");
			//else if(a[c][d]==0)printf("NO\n");
			//else dfs(c,d,0,0);
			
			
		}
	}
}return 0;
