#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
    char ch=getchar();int f=0;
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
    return f;
}
struct node
{
    int from;
    int to;
    int next;
    int w;
}edge[500005];
int head[200005],tot,cnt=1;
struct segtree
{
    int ls;
    int rs;
    int sum;
    int mark;
}tree[800005];
void add(int u,int v)
{
    edge[tot].from=u;
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int n,m,mod,pos[100005],npos[100005],dep[100005],son[100005],fa[100005],top[100005],rt,num;
int a[100005],size[100005];
void build(int p,int l,int r)
{
    int mid=l+r>>1;
    if(l==r)
    {
        tree[p].sum=a[npos[mid]];
        return;
    }
    tree[p].ls=++cnt;
    tree[p].rs=++cnt;
    build(tree[p].ls,l,mid);
    build(tree[p].rs,mid+1,r);
    tree[p].sum=(tree[tree[p].ls].sum+tree[tree[p].rs].sum)%mod;
}
void dfs1(int x)
{
    size[x]=1;
    dep[x]=dep[fa[x]]+1;
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        if(edge[i].to!=fa[x])
        {
            fa[edge[i].to]=x;
            dfs1(edge[i].to);
            size[x]+=size[edge[i].to];
            if(size[edge[i].to]>=size[son[x]])
            son[x]=edge[i].to;
        }
    }
}
void dfs2(int x)
{
    //cout<<x<<endl;
    pos[x]=++num;
    npos[num]=x;
    if(son[fa[x]]==x) top[x]=top[fa[x]];
    else top[x]=x;
    if(son[x]) dfs2(son[x]);
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        if(edge[i].to!=fa[x]&&edge[i].to!=son[x])
        {
            dfs2(edge[i].to);
        }
    }
}
void modify(int p,int l,int r,int x,int y,int k)
{
    int mid=l+r>>1;
    if(l==x&&r==y)
    {
        //cout<<"l r:"<<l<<" "<<r<<endl;
        tree[p].sum+=1LL*(r-l+1)*k%mod;
        tree[p].sum%=mod;
        tree[p].mark+=k;
        tree[p].mark%=mod;
        return;
    }
    if(tree[p].mark)
    {
        tree[tree[p].ls].sum+=1LL*(mid-l+1)*tree[p].mark%mod;
        tree[tree[p].ls].sum%=mod;
        tree[tree[p].rs].sum+=1LL*(r-mid)*tree[p].mark%mod;
        tree[tree[p].rs].sum%=mod;
        tree[tree[p].ls].mark+=tree[p].mark;
        tree[tree[p].ls].mark%=mod;
        tree[tree[p].rs].mark+=tree[p].mark;
        tree[tree[p].rs].mark%=mod;
        tree[p].mark=0;
    }
    if(y<=mid) modify(tree[p].ls,l,mid,x,y,k);
    else if(x>mid) modify(tree[p].rs,mid+1,r,x,y,k);
    else
    {
        modify(tree[p].ls,l,mid,x,mid,k);
        modify(tree[p].rs,mid+1,r,mid+1,y,k);
    }
    tree[p].sum=(tree[tree[p].ls].sum+tree[tree[p].rs].sum)%mod;
}
int query(int p,int l,int r,int x,int y)
{
    int mid=l+r>>1;
    if(l==x&&r==y)
    {
        return tree[p].sum;
    }
    if(tree[p].mark)
    {
        tree[tree[p].ls].sum+=1LL*(mid-l+1)*tree[p].mark%mod;
        tree[tree[p].ls].sum%=mod;
        tree[tree[p].rs].sum+=1LL*(r-mid)*tree[p].mark%mod;
        tree[tree[p].rs].sum%=mod;
        tree[tree[p].ls].mark+=tree[p].mark;
        tree[tree[p].ls].mark%=mod;
        tree[tree[p].rs].mark+=tree[p].mark;
        tree[tree[p].rs].mark%=mod;
        tree[p].mark=0;
    }
    if(y<=mid) return query(tree[p].ls,l,mid,x,y);
    else if(x>mid) return query(tree[p].rs,mid+1,r,x,y);
    else return (query(tree[p].ls,l,mid,x,mid)+query(tree[p].rs,mid+1,r,mid+1,y))%mod;
}
void modify(int x,int y,int z)
{
    int fx=top[x],fy=top[y];
    while(fx!=fy)
    {
        if(dep[fx]<dep[fy]) swap(fx,fy),swap(x,y);
        //cout<<pos[fx]<<" "<<pos[x]<<endl;
        modify(1,1,n,pos[fx],pos[x],z);
        //cout<<fx<<" "<<x<<endl;
        x=fa[fx],fx=top[x];
    }
    if(dep[x]<dep[y]) swap(x,y);
    modify(1,1,n,pos[y],pos[x],z);
    //cout<<y<<" "<<x<<endl;
}
int query(int x,int y)
{
    int fx=top[x],fy=top[y],ans=0;
    while(fx!=fy)
    {
        if(dep[fx]<dep[fy]) swap(fx,fy),swap(x,y);
        ans+=query(1,1,n,pos[fx],pos[x]);
        ans%=mod;
        //cout<<fx<<" "<<x<<" "<<ans<<endl;
        x=fa[fx],fx=top[x];
        //cout<<ans<<" ";
    }
    if(dep[x]<dep[y]) swap(x,y);
    ans+=query(1,1,n,pos[y],pos[x]);
    ans%=mod;
    return ans;
}
int main()
{
    memset(head,-1,sizeof(head));
    n=read(),m=read(),rt=read(),mod=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
    }
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        add(u,v);
        add(v,u);
    }
    dfs1(rt);
    
    dfs2(rt);//cout<<"Ok";
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int op=read();
        if(op==4)
        {
            int x=read();
            printf("%d\n",query(1,1,n,pos[x],pos[x]+size[x]-1));
        }
        else if(op==3)
        {
            int x=read(),y=read();
            modify(1,1,n,pos[x],pos[x]+size[x]-1,y);
        }
        else if(op==1)
        {
            int x=read(),y=read(),z=read();
            modify(x,y,z);
        }
        else
        {
            int x=read(),y=read();
            printf("%d\n",query(x,y));
        }
    }
}
