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
int n,a;
int main()
{
	n=read();
	for(int i=9;i>=1;i--)
	{
		if(n%i==0&&(n!=i||n==1))
		{
			a=n/i;
			printf("%d\n",a);
			for(int j=1;j<=a;j++)printf("%d ",i);
			printf("\n");
			return 0;
		}
	}
	int g=n/2,h=n%2;int ak=g+h;
	printf("%d\n",ak);
	if(h!=0)printf("%d ",h);
	for(int i=1;i<=g;i++)printf("2 ");
	printf("\n");
	return 0;
} 
