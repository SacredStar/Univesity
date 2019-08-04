// Dz_4.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <string.h>

using namespace std;


class X
{
public:
	X();
	X(char *);
	~X();
	char* Run();
	void Set(char *);
	friend void print(X &);
	friend char* Run(X &);

private:
	char *str, *str_return;
};

X::X() 
{
	str = new char[265];
	str[0] = '\0';
	str_return = new char[265];
	str_return[0] = '\0';
}

X::X(char *s)
{
	str = new char[265];
	strcpy(str, s);
	str_return = new char[265];
	str_return[0] = '\0';
}

X::~X()
{
	delete[]str;

	cout<<"EXTERMINATE!"<<endl;
}

void X::Set(char *s1)
{
	int i = 0;
	for (int i = 0; i < strlen(s1); i++)
	{
		str[i] = s1[i];
	}
	i = strlen(s1);
	str[i] = '\0';
}
char* X::Run() //��� ��� �����
{
	int j = 0;
	if (strlen(str)>10) {
		for (unsigned int i = 0; i<strlen(str); i++) 
			
};



char* Run(X &obj){
	return obj.Run();
}

void print(X &obj)
{
	cout << obj.str << ' ' << obj.str_return << endl;

};


void main()
{
	char s[265];
	cout << "Type anything and press \"Enter\":" << endl;
	cin.getline(s, 256); //��������� ��������� ��� ������
	X str(s); //������ � ������� ������ ��������������� ����� ����������,
	//��������� �������� ������������� ����� �����������
	cout << "You have type:" << endl;
	print(str);
	cout << "Output string:" << endl;
	cout << Run(str) << endl;
	cout << "Type anything and press \"Enter\":" << endl;
	cin.getline(s, 256);
	X *pstr; //������ � ������� ������ ����� ���������
	pstr = new X();
	pstr->Set(s);
	cout << "You have type:" << endl;
	print(*pstr);
	cout << "Output string:" << endl;
	cout << Run(*pstr) << endl;
	delete pstr;

}

