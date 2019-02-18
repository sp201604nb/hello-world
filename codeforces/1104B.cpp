#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
stack<int> s;
char a[100009];
int js=0;
int main()
{
	
	gets(a);
	int h=strlen(a);
	s.push(a[0]);
	for(int i=1;i<=h-1;i++)
	{
		
		if(s.top()==a[i])s.pop(),js++;
		else s.push(a[i]);
	}
	if(js%2==0)printf("No\n");
	else printf("Yes\n");
	return 0;
}
