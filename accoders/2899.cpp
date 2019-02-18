#include<cstdio>
using namespace std;
int a[110000],b[110000];
int main()
{
	int n,ans=0,bb=0,cc=0,dd=0,ee=0;
	scanf("%d",&n);
	a[0]=0;b[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>=a[i-1])
		{
			
			
			cc++;
			b[cc]=a[i];
			
		}
		else 
		{
			if(ans<cc)ans=cc;
			bb=0;cc=0;dd=0;ee=0;
			
		}
	}
	if(ans<cc)ans==cc;
	printf("%d",ans);
}
