#include<cstdio>
#include<algorithm>
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
int x,y,z,a,b,c,ans=0;
int main()
{
	x=read();y=read();z=read();
	a=read();b=read();c=read();
	if(x>a)ans=1;
	else a=a-x;
	if(y>b+a)ans=1;
	else b=b-y;
	if(a+b+c<z)ans=1;
	if(!ans)printf("YES\n");
	else printf("NO\n");
	return 0;
} 
