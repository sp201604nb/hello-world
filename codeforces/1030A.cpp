#include<cstdio>
using namespace std;
int n,a;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(a==1)
		{
			printf("HARD\n");
			return 0;
		}
	}
	printf("easy\n");
	return 0;
}
