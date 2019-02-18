#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
ll read()
{
	ll f=0,x=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')x=-1;ch=getchar();
	}
	while(ch>='0'&&ch<='9')f=(f<<1)+(f<<3)+ch-'0',ch=getchar();
	return f*x;
}
ll n,b,ys,g=0,ans=1000000000,zz,n1,js=0,zy=0,ss=0,aa=0,yy,ssq=0,yz;
int main()
{ys=0;
	n=read();b=read();
	for(ll i=2;i*i<=b;i++)
	{
		if(b%i==0)
		{
			g++;ssq=0;yz=0;yy=0;
			while(b%i==0)
			{
				b=b/i;
				yz=i;
				yy*=i;
				ssq++;
				//printf("%d\n",i);
			}
			if(yy>aa)ys=yz,aa=yy,ss=ssq;
		}
	}
	if(b>1)
	{
		if(b>aa)ys=b,ss=1;
	}
	n1=n;
	while(n>=ys)
	{
		n=n/ys;
		zz++;
		
	}
	js=n;
	n=n1;
	for(int i=zz;i>=1;i--)
	{
		ll x=pow(ys,i);
		//printf(" %d\n",zz);
		if(i==zz)
		{
			zy+=js*i;
		//	printf("%d\n",zy);
		}
		else 
		{
			zy+=(n/x-js)*i;
		//	printf("%d\n",x);
			js=n/x;
			
		}
	}
	
	zy/=ss;
	ans=zy;
	printf("%lld\n",ans);
	return 0;
} 
