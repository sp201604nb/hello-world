#include<cstdio>
using namespace std;
int father[70000];
int find(int x)
{
	return father[x]==x?x:father[x]=find(father[x]);
}
int main()
{
	int n,m;
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		father[find(b)]=find(a);
	}
	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(father[i]==i)ans++;
	}
	printf("%d",ans);
}
