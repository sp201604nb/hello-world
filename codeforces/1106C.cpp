#include<cstdio>
#include<algorithm>
using namespace std;
long long read()
{
	long long f=0,x=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')x=-1;ch=getchar();
	}
	while(ch>='0'&&ch<='9')f=(f<<1)+(f<<3)+ch-'0',ch=getchar();
	return f*x;
}
long long n,a[300009],ans=0;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n/2;i++)
	{
		ans+=(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
	}
	printf("%lld\n",ans);
	return 0;
}
