#include<cstdio>
#include<iostream>
using namespace std;
int a[1000][1000],n,ans=0;
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
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='.')a[i][j]=0;
			else a[i][j]=1;
			//printf("%d ",a[i][j]);
		}
		//printf
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==1&&a[i-1][j-1]==1&a[i-1][j+1]==1&&a[i+1][j-1]==1&&a[i+1][j+1]==1)
			ans++;
		}
	}
	printf("%d\n",ans);
	
 } 
