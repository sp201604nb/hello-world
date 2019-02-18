// luogu-judger-enable-o2
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1e6+5e5+10;
bool ed[N],cir[N],zd=0,hs=0;
int n,i,j,m,x,y,c,st[N],tp,zx,lst=2e9,hui,lb[N<<1][2],s[N],sj[N<<1][2],lj[N<<1],nxt[N<<1],fir[N],pre[N<<1],bs;
inline void read(int &x)
{
    c=getchar();
    while ((c<48)||(c>57)) c=getchar();
    x=c^48;c=getchar();
    while ((c>=48)&&(c<=57))
    {
        x=x*10+(c^48);
        c=getchar();
    }
}
void findcir(int x,int y)
{
    ed[x]=1;
    st[++tp]=x;
    int i;
    for (i=fir[x];i;i=nxt[i]) if (lj[i]!=y)
    {
        if (ed[lj[i]])
        {
            while (st[tp+1]!=lj[i]) cir[st[tp--]]=1;
            zd=1;
            return;
        }
        else
        {
            findcir(lj[i],x);
            if (zd) return;
        }
    }
    --tp;
}
void dfs(int x)
{
    printf("%d ",x);
    ed[x]=1;
    int i,j;
    j=fir[x];
    if ((cir[x])&&(!hui))
    {
        while (nxt[j]) j=nxt[j];
        while ((j)&&(ed[lj[j]])) nxt[j=pre[j]]=0;
        if (j==0) return;
        j=bs+1;
        for (i=fir[x];i;i=nxt[i]) if ((cir[lj[i]])&&(!ed[lj[i]]))
        {
            j=i;
            break;
        }
        if (j>bs)
        {
            for (i=fir[x];i;i=nxt[i]) if (!ed[lj[i]]) dfs(lj[i]);
            return;
        }
        for (i=fir[x];i!=j;i=nxt[i]) if (!ed[lj[i]]) dfs(lj[i]);
        if ((nxt[j]==0)&&(lj[j]>lst))
        {
            hui=1;
            return;
        }
        if (nxt[j])
        {
            i=nxt[j];
            while (ed[lj[i]]) i=nxt[i];
            lst=lj[i];
        }
        dfs(lj[j]);
        for (i=nxt[j];i;i=nxt[i]) if (!ed[lj[i]]) dfs(lj[i]);
        return;
    }
    for (i=fir[x];i;i=nxt[i]) if (!ed[lj[i]]) dfs(lj[i]);
}
int main()
{
    read(n);read(m);
    for (i=1;i<=m;i++)
    {
        read(lb[i][0]);read(lb[i][1]);
        lb[i+m][0]=lb[i][1];
        lb[i+m][1]=lb[i][0];
        ++s[lb[i][0]];++s[lb[i][1]];
    }
    for (i=n-1;i;i--) s[i]+=s[i+1];
    m<<=1;
    for (i=1;i<=m;i++)
    {
        sj[s[lb[i][1]]][0]=lb[i][0];
        sj[s[lb[i][1]]--][1]=lb[i][1];
    }
    for (i=1;i<=m;i++)
    {
        lj[++bs]=sj[i][1];
        nxt[bs]=fir[sj[i][0]];
        fir[sj[i][0]]=bs;
    }
    for (i=1;i<=m;i++) pre[nxt[i]]=i;
    findcir(1,1);
    memset(ed,false,sizeof(ed));
    dfs(1);
}
