
#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	/*������ж��Ĵ�����*/
	int t=�����Ǽ�飨���ģ�����;
	while(--t)
    {
		system("����д��������������.exe > ����д��������������.txt");
		system("����д����1����.exe < ����д��������������.txt > ����д����1����.txt");
		system("����д����2����.exe < ����д��������������.txt > ����д����2����.txt");
		if(system("fc ����д����2����.txt ����д����1����.txt"))
			break;
	}
	if(t==0)
		cout<<"no error"<<endl;
	else
		cout<<"error"<<endl;
	/*�������û�ж��Ĵ�����ֱ������Ϊֹ*/
	/*
	while(1)
    {
		system("����д��������������.exe > ����д��������������.txt");
		system("����д����1����.exe < ����д��������������.txt > ����д����1����.txt");
		system("����д����2����.exe < ����д��������������.txt > ����д����2����.txt");
		if(system("fc ����д����2����.txt ����д����1����.txt"))
			break;
	}
	*/
	return 0;
}

