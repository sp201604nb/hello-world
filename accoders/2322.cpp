
#include<iostream>
using namespace std;
const long long mod=9901;
long long f[20010];
int quick_mod(int x,int p)
{
    long long ans=1,tp=x;
    while(p)
    {
        if(p&1)
        {
            ans=ans*tp%mod;
        }
        tp=tp*tp%mod;
        p/=2;
    }
    return ans;
}
int main()
{
    int m,n;
    cin>>n>>m;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    if(m<n-m)  m=n-m;
    f[0]=1;
    for(int i=1;i<=n;i++)    
    {
        f[i]=f[i-1]*i%mod;
        if(f[i]==0)   f[i]=i%mod;
    }
    cout<<f[n]*quick_mod(f[m],mod-2)%mod*quick_mod(f[n-m],mod-2)%mod;
    return 0;
}

