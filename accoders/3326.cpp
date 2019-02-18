#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
#define Max 1000000
using namespace std;
stack<int> s;
struct edge
{
	int to,next;
}e[Max];
int t,n,m,head[Max],cnt,zt[Max],dfn[Max],low[Max],inx,ins[Max],gs,cast[Max];
void adde(int a,int b)
{
	cnt++;
	e[cnt].to=b;
	e[cnt].next=head[a];
	head[a]=cnt;
}
void tarjan(int x)
{
	inx++;
	dfn[x]=low[x]=inx;
	s.push(x);
	ins[x]=1;
	int v;
	for(int i=head[x];~i;i=e[i].next)
	{
		v=e[i].to;
		if(dfn[v]==0)
		{
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(ins[v]==1)low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x])
	{
		v=Max;
		gs++;
		while(v!=x)
		{
			v=s.top();
			s.pop();
			cast[v]=gs;
			ins[v]=0;
		}
	}
}
int main()
{
	scanf("%d",&t);
	while(t!=0)
	{
		memset(head,-1,sizeof(head));
		memset(dfn,0,sizeof(dfn));
		t--;cnt=0;gs=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&zt[i]);
		for(int i=1;i<=m;i++)
		{
			int cs,a,b;
			scanf("%d",&cs);
			scanf("%d",&b);
			for(int j=2;j<=cs;j++)
			{
				scanf("%d",&a);
				int va=zt[a],vb=zt[b];
				if(va==1&&vb==1)adde(b,a),adde(a+n,b+n);
				if(va==0&&vb==1)adde(a,b+n),adde(b,a+n);
				if(va==1&&vb==0)adde(a+n,b),adde(b+n,a);
				if(va==0&&vb==0)adde(a,b),adde(b+n,a+n);
				b=a;
			}
		}
		for(int i=1;i<=n*2;i++)if(dfn[i]==0)tarjan(i);
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			printf("%d %d\n",cast[i],cast[i+n]);
			if(cast[i]<=cast[i+n])
			{
				printf("NO\n");
				flag=1;
				break;
			}
		}
		if(flag==0)printf("YES\n");
	}
	return 0;
} 
