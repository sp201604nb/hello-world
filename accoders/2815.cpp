#include<cstdio>
#include<iostream>
using namespace std;
int c,n,a[11],f[1001];
int main()
{
    scanf("%d%d",&c,&n);
    for(int i=0;i<=1001;i++) f[i]=10000001;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        f[a[i]]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=a[i];j<=c;j++){
             f[j]=min(f[j],f[j-a[i]]+1);
        }
    }
    printf("%d",f[c]);
}

