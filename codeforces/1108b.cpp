#include<cstdio>
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
int n,t[10009],x=1,y=1,mm=0;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int d=read();
		if(d>mm)mm=d;
		t[d]++;
		if(t[d]==2)
		{
			//printf("%d %d %d\n",y,d,gcd(y,d));
			y*=d/gcd(y,d);
		}
		else x*=d/gcd(x,d);
	}
	int xx=x,yy=y;
	if(y>x)xx=y,yy=x;
	if(xx>mm)
	{
		int ac;
		if(xx%mm==0)ac=xx/mm,xx=mm,yy*=ac;
		else ac=mm/yy,yy=mm,xx/=ac;
	}
	printf("%d %d\n",xx,yy);
	return 0;
}
