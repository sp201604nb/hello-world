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
int q;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	q=read();
	for(int i=1;i<=q;i++)
	{
		int a=read(),ans=0,b=0,yh,yu,xxx=0;
		int f=a,h[30]={0},hs[20]={0},hh=0;
		for(int j=25;j>=0;j--)
		{
			int x=pow(2,j);
			if(f>=x&&xxx==0)xxx=j;
			if(f>=x)f=f-x,h[j]=1;
		}
		for(int j=0;j<=xxx;j++)
		{
			if(h[j]==0)hs[j]=1;
			else hs[j]=0;
		}
		for(int j=xxx;j>=0;j--)
		{
			if(hs[j]==1)hh+=pow(2,j);
		}
		
		ans=gcd(a^hh,a&hh);
		if(hh==0)printf("1\n");
		else
		printf("%d\n",ans);
	}
} 
