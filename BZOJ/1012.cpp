#include<cstdio>
#include<cstring>
struct nod{int l,r,ll,rr;long long c;}a[400010];
int len,len2=0;long long t=0,m;int n;
long long max(long long x,long long y){return x>y?x:y;}
void bt(int l,int r)
{
    len++;int now=len;
    a[len].l=l;a[len].r=r;a[len].ll=a[len].rr=a[len].c=-2147483647;
    if(l<r)
    {
        int mid=(l+r)/2;
        a[now].ll=len+1;bt(l,mid);
        a[now].rr=len+1;bt(mid+1,r);
        a[now].c=max(a[a[now].ll].c,a[a[now].rr].c);
    }
}
void change(int now,int x,long long k)
{
    if(a[now].l==a[now].r) 
    {
        a[now].c=k;
        return;
    }
    int ll=a[now].ll,rr=a[now].rr,mid=(a[now].l+a[now].r)/2;
    if(x<=mid) change(ll,x,k);
    else if(x>mid) change(rr,x,k);
    a[now].c=max(a[ll].c,a[rr].c);
}
long long findsum(int now,int l,int r)
{
    if(a[now].l==l&&a[now].r==r) return a[now].c;
    int ll=a[now].ll,rr=a[now].rr,mid=(a[now].l+a[now].r)/2;
    if(r<=mid) return findsum(ll,l,r);
    else if(l>mid) return findsum(rr,l,r);
    else return max(findsum(ll,l,mid),findsum(rr,mid+1,r));
}
int main()
{
    scanf("%d %lld",&n,&m);
    len=0;bt(1,n); 
    for(int i=1;i<=n;i++)
    {
        char v[10];scanf("%s",v);
        if(v[0]=='A')
        {
            long long c;scanf("%lld",&c);
            ++len2;change(1,len2,(c+t)%m);
        }
        else
        {
            int x;scanf("%d",&x);if(x==0){printf("0\n");continue;}
            t=findsum(1,len2-x+1,len2);t%=m;printf("%lld\n",t);
        }
 
    }
    return 0;
}


