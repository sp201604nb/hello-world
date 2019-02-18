#include<cstdio>
using namespace std;
int a[120000];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int c,cc;
		for(int i=1;i<=n;i++)a[i]=0;
		for(int i=1;i<=n;i++)
		{
			
			scanf("%d%d",&c,&cc);
			for(int j=c;j<=cc;j++)
			a[j]++;
		}
		for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
		printf("\n");
	}
}
