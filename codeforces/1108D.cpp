#include<cstdio>
#include<algorithm>
#define Max 200000+100
using namespace std;
int read()
{
	int f=0,x=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')x=-1;ch=getchar();
	}
	while(ch>='0'&&ch<='9')f=(f<<1)+(f<<3)+ch-'0',ch=getchar();
	return f*x;
}
int n;
int g[Max],co[4],ans=0,gss=0,gus[4];
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		char col=getchar();
		if(col=='R')g[i]=1;
		if(col=='B')g[i]=2;
		if(col=='G')g[i]=3;
	}
	for(int i=1;i<=n;i++)
	{
		if(g[i]==g[i-1])
		{
			ans++;
			int x[4]={0};
			x[g[i]]++;x[g[i+1]]++;
			for(int j=1;j<=3;j++)if(x[j]==0)g[i]=j;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		if(g[i]==1)printf("R");
		if(g[i]==2)printf("B");
		if(g[i]==3)printf("G");
	}
	return 0;
}
