#include<cstdio>
#include<algorithm>
#include<queue>
#define Max 100000+9
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
struct cc
{
	int a,c;
}cai[Max];
int n,m,a[Max],c[Max],ans=0,zz=0;
int cmp(cc a,cc b)
{
	return a.c<b.c;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)cai[i].a=read();
	for(int i=1;i<=n;i++)cai[i].c=read();
	sort(cai+1,cai+n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int t=read(),d=read(),flag=0;ans=0;
		
		printf("%d\n",ans);
	}
	
	return 0;
}
