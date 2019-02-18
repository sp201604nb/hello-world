#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int s[100009],zz=0;
char a[100009];
int js=0;
int main()
{
	
	gets(a);
	int h=strlen(a);
	zz++;s[zz]=a[0];
	for(int i=1;i<=h-1;i++)
	{
		
		if(s[zz]==a[i])
		{
			zz--;js++;
		}
		else zz++,s[zz]=a[i];
		
	}
	if(js%2==0)printf("No\n");
	else printf("Yes\n");
	return 0;
}
