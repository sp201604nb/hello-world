#include<cstdio>
using namespace std;
int e[2000][2000];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		e[a][b]=e[b][a]=c;
	}
	int z[2000]={0};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			
		}
	}
}
