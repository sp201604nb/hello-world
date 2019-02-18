#include<cstdio>
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
int n,l1,l2,r1,r2;
int main() 
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		l1=read();r1=read();l2=read();r2=read();
		if(l1<=l2)printf("%d %d\n",l1,r2);
		else printf("%d %d\n",r1,l2);
		
	}
	return 0;
}
