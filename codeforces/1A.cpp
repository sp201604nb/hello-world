#include<cstdio>
using namespace std;
int n,m,a;
int main()
{
	scanf("%d%d%d",&n,&m,&a);
	int h=n/(double)a,g=m/(double)a;
	if(a*h<n)h++;
	if(a*g<m)g++;
	long long hg=h*g;
	printf("%lld\n",hg);
	return 0;
} 
