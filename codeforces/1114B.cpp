#include<cstdio>
#include<algorithm>
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
ll n,m,k,a[200009],b[200009],js=0,kk[200009],zz=0,ans=0,ks=0;
int main()
{
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		if(i>=n-m*k+1)
		ans+=a[i],js=a[i];
		if(i<n-m*k+1)if(a[i]==js)ks++;
	}
	printf("%lld\n",ans);
	zz=1;
	for(int i=1;i<=n;i++)
	{
		if(b[i]>js)kk[zz]++;
		if(b[i]==js&&ks==0)kk[zz]++;
		if(b[i]==js&&ks!=0)ks--;
		if(kk[zz]==m)printf("%d ",i),zz++;
		if(zz==k)return 0;
		
	}
} 
