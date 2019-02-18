
#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	/*这个是有对拍次数的*/
	int t=这里是检查（对拍）次数;
	while(--t)
    {
		system("这里写数据生成器名称.exe > 这里写数据生成器名称.txt");
		system("这里写程序1名称.exe < 这里写数据生成器名称.txt > 这里写程序1名称.txt");
		system("这里写程序2名称.exe < 这里写数据生成器名称.txt > 这里写程序2名称.txt");
		if(system("fc 这里写程序2名称.txt 这里写程序1名称.txt"))
			break;
	}
	if(t==0)
		cout<<"no error"<<endl;
	else
		cout<<"error"<<endl;
	/*下面这个没有对拍次数，直到错了为止*/
	/*
	while(1)
    {
		system("这里写数据生成器名称.exe > 这里写数据生成器名称.txt");
		system("这里写程序1名称.exe < 这里写数据生成器名称.txt > 这里写程序1名称.txt");
		system("这里写程序2名称.exe < 这里写数据生成器名称.txt > 这里写程序2名称.txt");
		if(system("fc 这里写程序2名称.txt 这里写程序1名称.txt"))
			break;
	}
	*/
	return 0;
}

