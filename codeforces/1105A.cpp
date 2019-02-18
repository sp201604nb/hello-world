#include<cstdio>
#define Max 10000
using namespace std;
int n,a[Max],anss=100000,k;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=100;i++)
	{
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]>i+1)ans+=a[j]-i-1;
			if(a[j]<i-1)ans+=i-1-a[j];
		}
		if(ans<anss)anss=ans,k=i;
	}
	printf("%d %d\n",k,anss);
	return 0;
} 
