#include<cstdio>
#include<cstring>
using namespace std;
int a[2],hx=0,zx=0;
int read()
{
	char ch=getchar();
	while(ch>'1'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='1')a[ch-'0']++;
	return 0;
}
int main()
{
	char ch;
	while(1)
	{
		ch=getchar();
		if(ch<'0'||ch>'1')return 0;
		if(ch=='1')
		{
			if(hx==0)printf("1 1\n"),hx=1;
			else printf("1 3\n"),hx=0;
		}
		if(ch=='0')
		{
			if(zx==0)printf("3 4\n"),zx=1;
			else printf("1 4\n"),zx=0;
		}
	}
	
}
