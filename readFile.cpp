#pragma once
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream readFile("build.txt");
	char temp[1024] = { 0 };
	readFile >> temp; //�����ո����ֹͣ���ո��������޷������'\0'�ǽ�ֹ������ͼ3��ʾ
	//readFile.getline(temp, 8, 0); //��������ո�����delim���ŲŽ�ֹ�� ���һ������0��ʾ�ı����������ַ���ASCLL��Ϊ32���ı��򲻿����п��ַ�����ֹ�������ӵ���������0ʱ����ʾ'\n'Ϊ��ֹ��('\n'Ҳ�ǻ��з�)����ͼ4��ʾ
	cout << temp << endl;
	readFile.close();
	return 0;
}