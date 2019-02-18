//90
#include<cstdio>
using namespace std;
int a[6000];
int b[20040]={1};
int main()
{
	for(int i=1;i<=20000;i++)b[i]=1;
	for(int i=2;i<=20000;i++)
	{
		if(b[i]==1)
		for(int j=2;;j++)
		{
			if(i*j>20000)break;
			else b[i*j]=0;
		}
	}
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=20000;i>=2;i--)
	{
		if(b[i]==true)
		for(int j=1;j<=n;j++)
		{
			if(a[j]%i==0)
			{
				printf("%d",a[j]);
				return 0;
			}
		}
	}
	printf("1");
}
