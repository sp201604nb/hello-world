#include<cstdio>
#include<algorithm>
#include<cstring>
#define Max 8*1000000+9
#define ll long long
using namespace std;
int read()
{
	int f=0,x=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')x=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')f=(f<<1)+(f<<3)+ch-'0',ch=getchar();
	return f*x;
} 
int n,m;
struct segtree
{
	int l,r;ll w;
}tree[Max];
void pulldown(int p)
{
	int mid=(tree[p].l+tree[p].r)>>1;
	tree[p*2].l=tree[p].l;tree[p*2].r=mid;
	tree[p*2+1].l=mid+1;tree[p*2+1].r=tree[p].r;
}
void build(int l,int r,int x,int p)
{
	tree[p].l=l;tree[p].r=r;
	if(l==r)
	{
		tree[p].w+=1;return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid)build(l,mid,x,p*2);
	else build(mid+1,r,x,p*2+1);
	tree[p].w=tree[p*2].w+tree[p*2+1].w;
}
void del(int l,int r,int x,int p)
{
	if(l==r)
	{
		tree[p].w-=1;
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid&&tree[p*2].w>=0)del(l,mid,x,p*2);
	if(x>mid&&tree[p*2+1].w>=0)del(mid+1,r,x,p*2+1);
	tree[p].w=tree[p*2].w+tree[p*2+1].w;
}
int sma(int p)
{
	if(tree[p].l==tree[p].r)
	{
		return tree[p].l;
	}
	int mid=(tree[p].l+tree[p].r)>>1;
	pulldown(p);
	if(tree[p*2].w!=0)return sma(p*2);
	else if(tree[p*2+1].w!=0)return sma(p*2+1);
	else return -1;
}
int big(int p)
{
	if(tree[p].l==tree[p].r)
	{
		return tree[p].l;
	}
	pulldown(p);
	int mid=(tree[p].l+tree[p].r)>>1;
	if(tree[p*2+1].w!=0)return big(p*2+1);
	else if(tree[p*2].w!=0)return big(p*2);
	else return -1;
}
int flag=0,ans;
void qq(int x,int p)
{
	if(tree[p].l==tree[p].r)
	{
		if(tree[p].l==x)return ;
		ans=tree[p].l;
		flag=1;
		return ;
	}
	pulldown(p);
	int mid=(tree[p].l+tree[p].r)>>1;
	if(x<=mid&&tree[p*2].w!=0)qq(x,p*2);
	if(x>mid)
	{
		if(tree[p*2+1].w!=0)qq(x,p*2+1);
		if(flag==0)
		if(tree[p*2].w!=0)qq(x,p*2);
	}
}
void hj(int x,int p)
{
	if(tree[p].l==tree[p].r)
	{
		if(tree[p].l==x)return ;
		ans=tree[p].l;
		flag=1;return ;
	}
	pulldown(p);
	int mid=(tree[p].l+tree[p].r)>>1;
	if(x>mid&&tree[p*2].w!=0)hj(x,p*2+1);
	if(x<=mid)
	{
		if(tree[p*2].w!=0)hj(x,p*2);
		if(flag==0)
		if(tree[p*2+1].w!=0)hj(x,p*2+1);
	}
}
int find(int x,int p)
{
	pulldown(p);
	if(tree[p].l==x&&tree[p].r==x)
	{
		return 1;
	}
	int mid=(tree[p].l+tree[p].r)>>1;
	if(x<=mid&&tree[p*2].w!=0)return find(x,p*2);
	else if(x>mid&&tree[p*2+1].w!=0)return find(x,p*2+1);
	else return -1;
}
int ggs=0;
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		int op=read();flag=0;ans=0;
		//if(ggs==40970&&op!=1&&op!=2)printf("%d\n",op);
		if(op==1)
		{
			int x=read();
			build(0,n,x,1);
		}
		else if(op==2)
		{
			int x=read();
			del(0,n,x,1);
		}
		else if(op==3)
		{ggs++;
		//if(sma(1)==1)printf("%d\n",op); 
			printf("%d\n",sma(1));
		}
		else if(op==4)
		{ggs++;//if(big(1)==1)printf("%d\n",op); 
			printf("%d\n",big(1));
		}
		else if(op==5)
		{ggs++;
			int x=read();
			qq(x,1);
			if(flag==0)ans=-1;//if(ans==1)printf("%d\n",op); 
			printf("%d\n",ans);
		}
		else if(op==6)
		{ggs++;
			int x=read();
			hj(x,1);
			if(flag==0)ans=-1;//if(ans==1)printf("%d\n",op); 
			printf("%d\n",ans);
		}
		else if(op==7)
		{ggs++;
			int x=read();//if(find(x,1)==1)printf("%d\n",op); 
			printf("%d\n",find(x,1));
		}
	}
}
