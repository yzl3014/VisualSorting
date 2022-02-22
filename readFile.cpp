#pragma once
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream readFile("build.txt");
	char temp[1024] = { 0 };
	readFile >> temp; //遇到空格输出停止，空格后的内容无法输出，'\0'是截止符，如图3所示
	//readFile.getline(temp, 8, 0); //可以输出空格，遇到delim符号才截止。 最后一个参数0表示文本框遇到空字符（ASCLL码为32，文本框不可能有空字符）截止符。不加第三个参数0时，表示'\n'为截止符('\n'也是换行符)。如图4所示
	cout << temp << endl;
	readFile.close();
	return 0;
}