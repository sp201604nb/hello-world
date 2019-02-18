#include<cstdio>
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
ll b,k,f;long long ans=0;
int main()
{
	b=read(),k=read();f=k;
	for(int i=1;i<=k;i++)
	{
		ll a=read();
		a%=10;
		ll x=pow(b,--f);
		x%=10;
		ans+=a*x;//printf("%lld\n",ans);
		ans%=10;
	}
	
	if(ans%2==0)printf("even\n");
	else printf("odd\n");
	return 0;
} 
