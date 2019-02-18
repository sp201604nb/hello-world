#include<cstdio>
#include<algorithm>
#include<string.h>
#include<iostream>
#define Max 200000+100
using namespace std;
int read()
{
	int f=0,x=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')x=-1;ch=getchar();
	}
	while(ch>='0'&&ch<='9')f=(f<<1)+(f<<3)+ch-'0',ch=getchar();
	return f*x;
}
int n;char col;
int g[Max],co[4],x[4][4],ans=0,gss=0,gus[4];int mni=300000,wz=0;
string t[10],s;
int main()
{
	
	int n;
    cin>>n;
    cin>>s;
    int i,j,k;
    for (j=0;j<=100000;j++)
    {
        t[0]+="RGB";
    }
    for (j=0;j<=100000;j++)
    {
        t[1]+="RBG";
    }
    for (j=0;j<=100000;j++)
    {
        t[2]+="BRG";
    }
    for (j=0;j<=100000;j++)
    {
        t[3]+="BGR";
    }
    for (j=0;j<=100000;j++)
    {
        t[4]+="GRB";
    }
    for (j=0;j<=100000;j++)
    {
        t[5]+="GBR";
    }
    
    for (i=0;i<6;i++)
    {
        int now=0;
        for (j=0;j<n;j++)
        {
            if(s[j]!=t[i][j])
            now++;
        }
        if (now<mni)
        {
            mni=now;
            wz=i;
        }
    }

    cout<<mni<<endl;
    for(i=0;i<n;i++)
    {
        cout<<t[wz][i];
    }
    cout<<endl;
    return 0;
}

