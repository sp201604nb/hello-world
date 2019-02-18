#include<bits/stdc++.h>
#define M 100009
using namespace std;
int f[M],ch[M][2],root=0,sz=0,size[M],cnt[M],key[M];
inline int get(int x)
{
	return ch[f[x]][1]==x;
}
inline void clear(int x)
{
	ch[x][0]=ch[x][1]=f[x]=size[x]=key[x]=cnt[x]=0;
	if(f[x])ch[f[x]][get(x)]=0;
} 
inline void updata(int x)
{//if(x==root)printf("%d\n",x);
	if(x)
	{
		size[x]=cnt[x];
		
		if(ch[x][0])size[x]+=size[ch[x][0]];
		if(ch[x][1])size[x]+=size[ch[x][1]];
	}
}
inline int read()
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
inline void rotata(int x)
{
	int old=f[x],oldf=f[old],which=get(x);
	ch[old][which]=ch[x][which^1];f[ch[old][which]]=old;
	f[old]=x;ch[x][which^1]=old;f[x]=oldf;
	if(oldf)ch[oldf][ch[oldf][1]==old]=x;
	updata(old);updata(x);
}
inline void splay(int x)
{
	for(int fa=f[x];(fa=f[x]);rotata(x))
	if(f[fa])
	rotata((get(x)==get(fa)?fa:x));
	
	root=x;
}
inline void insert(int x)
{
	if(root==0)
	{
		sz++;root=sz;ch[sz][1]=ch[sz][0]=0;key[sz]=x;cnt[sz]=1;f[sz]=0;return ;
	}
	int now=root,fa=0;
	while(1)
	{
		if(key[now]==x)
		{
			cnt[now]++;updata(now);updata(fa);splay(now);break;
		}
		fa=now;
		now=ch[fa][key[fa]<x];
		if(now==0)
		{
			sz++;
			now=sz; 
			cnt[now]=1;
			ch[now][0]=ch[now][1]=0;f[now]=fa;
			key[now]=x;size[now]=1;ch[fa][key[fa]<x]=now;
			updata(fa);
			splay(sz);
			
			break ;
		}
	}
}
inline int find(int x)
{
	int ans=0,now=root;
	while(1)
	{
		if(x<key[now])now=ch[now][0];
		else
		{
			ans+=(ch[now][0]?size[ch[now][0]]:0);
			if(x==key[now])
			{
				splay(now);return ans+1;
			}
			ans+=cnt[now];
			now=ch[now][1];
		}
	}
}
inline int pre()
{
	int now=ch[root][0];
	while(ch[now][1])now=ch[now][1];
	return now;
}
inline int next()
{
	int now=ch[root][1];
	while(ch[now][0])now=ch[now][0];
	return now;
}
inline void del(int x)
{
	find(x);
	if(cnt[root]>1)
	{
		cnt[root]--;updata(root);return ;
	}
	if(!ch[root][0]&&!ch[root][1])
	{
		clear(root);root=0;return ;
	}
	if(!ch[root][0])
	{
		int oldroot=root;root=ch[root][1];f[root]=0;clear(oldroot);return ;
	}
	if(!ch[root][1])
	{
		int oldroot=root;root=ch[root][0];f[root]=0;clear(oldroot);return ;
	}
	int leftbig=pre(),oldroot=root;
	
	splay(leftbig);
	ch[root][1]=ch[oldroot][1];
	f[ch[oldroot][1]]=root;
	f[root]=0;
	clear(oldroot);
	updata(root);
}
inline int findx(int x)
{
	int now=root;
	while(1)
	{
		if(ch[now][0]&&x<=size[ch[now][0]])
		now=ch[now][0];
		else
		{
			int temp=(ch[now][0]?size[ch[now][0]]:0)+cnt[now];
			if(x<=temp)return key[now];
			x=x-temp;
			now=ch[now][1];
		}
	}
}
int main()
{
	int n;
	n=read();
	for(int i=n;i>=1;i--)
	{
		int opt,x;
		opt=read(),x=read();
		if(opt==1)
		{
			insert(x);
		}
		else if(opt==2)
		{
			del(x);
		}
		else if(opt==3)
		{
			printf("%d\n",find(x));
		}
		else if(opt==4)
		{
			printf("%d\n",findx(x));
		}
		else if(opt==5)
		{
			insert(x);printf("%d\n",key[pre()]),del(x);
		}
		else 
		{
			insert(x);printf("%d\n",key[next()]),del(x);
		}
	}
	return 0;
}
