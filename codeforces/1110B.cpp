#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
#define Max 200000
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
int n,m,k,a[Max],xx,xy[Max];long long ans=0;
struct edge
{
	int a,x;
}e[Max];
int cmp(edge a,edge b)
{
	return a.x<b.x;
}
int main()
{
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		e[i].a=read();
		a[i]=e[i].a;
		e[i].x=e[i].a-e[i-1].a;
		if(i!=1)ans+=e[i].x;
	}
	sort(e+2,e+n+1,cmp);
	for(int i=n;i>=n-k+2;i--)
	{
		ans-=e[i].x;
	}
	printf("%lld\n",ans+k);
	return 0;
} 
