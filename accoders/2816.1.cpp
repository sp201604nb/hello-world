#include<cstdio>
using namespace std;
int z[2000][2000];int n,m;int ans=0;
void dfs(int x,int y,int v)
{
    if(y==n)
    {
        if(v>ans)ans=v;
    }
    for(int i=1;i<=n;i++)
    {
        if(z[y][i]!=0&&i!=x)dfs(y,i,v+z[y][i]);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    if(m==0)
    printf("-1");
    int a,b,c;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(z[a][b]<c&&z[b][a]<c)z[a][b]=z[b][a]=c;
    }
    dfs(1,1,0);
    printf("%d",ans);
}
