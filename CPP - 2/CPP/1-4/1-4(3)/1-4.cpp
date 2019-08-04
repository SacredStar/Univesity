#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <iostream>
#include <ostream>
#include <fstream>


using namespace std;;


class String
{
public:
	
	String();
	String(char *);
	~String();
	void Set(char *);
	void Run();
	void print();
	String &operator=(String *);
	char* getstr() { return str; };
	char* getstr_ret() { return str_return; };
private:
	char *str, *str_return;
};

String::String()  //��� ������ ��� ��������
{
	str = new char[265];
	str[0] = '\0';
	str_return = new char[265];
	str_return[0] = '\0';
}

String::String(char *str_in)
{
	str = new char[265];
	strcpy(str, str_in);
	str_return = new char[265];
	str_return[0] = '\0';
}

String::~String()
{
	delete[]str;
	delete[]str_return;
	cout << "Destruction Complete!!";
}

void String::Set(char *s1)
{
	int i = 0;
	for (int i = 0; i < strlen(s1); i++)
	{
		str[i] = s1[i];
	}
	i = strlen(s1);
	str[i] = '\0';
}
void String::Run()
{
	int i, j = 0;
	char str_inner[10];
	if (strlen(str) == 10)
	{
		for (i = 0; i < 10; i++)
		{
			if ((int)str[i] <= 90 && (int)str[i] >= 65)
			{
				continue;
			}
			else
			{
				str_return[j] = str[i];
				j++;
			}
		}
		str_return[j] = '\0';
	}

	else strcpy(str_return, str);

}

String &String::operator=(String *other)
{
	strcpy(str, other->str_return);
	return *this;
}

void String::print()
{
	ofstream file_out;
	file_out.open("test.txt", ios::app);
	if (!file_out.is_open())
	{
		cout << "File cant be oppened" << endl;
		getch();
	}
	
	file_out.seekp(0, ios::end); //������������ � ����� �����
	file_out << str;
	file_out << '\n';
	file_out << str_return;
	file_out << '\n';
	file_out.close();
	

}
//�������� �����

void main()
{
	setlocale(LC_ALL, "ENG");
	cout << " Programm works only with english words!Thx for your attention." << endl;
	char s[265] = "QWE543eqwrew"; // ��� ������ ����� �� ����� 10 //12
	ofstream file_out;
	file_out.open("test.txt", ios::out); //��� ������ ������� ������� ����� ����
	if (!file_out.is_open())
	{
		cout << "File cant be oppened" << endl;
		getch();
	}
	file_out.close();

								/* -------- ����� ��������� ---------------*/
	String *str = new String();
	str->Set(s);
	cout << "Before:      ";
	cout << str->getstr() << endl;
	str->Run();
	cout << "After :      ";
	cout << str->getstr_ret() << endl;
	//getch();
	//delete str;
	getch();
	cout << endl << endl << endl;
	cout << "_____________________________________" << endl << endl;
	/*----------- ����� � ���� ------------- */
	str->print();
	/*-----------����� ���������� ------------- */
	char s2[265] = "123432DS40"; // ��� ������ ����� ����� 10
	String TryPer(s2); // 
					   // ������ ������ ����� ��� ���� ����� 
					   //TryPer.Set(s);
	cout << "Before:      ";
	cout << TryPer.getstr() << endl;
	TryPer.Run();
	cout << "After :      ";
	cout << TryPer.getstr_ret() << endl;
	getch();
	cout << endl << endl << endl;
	cout << "_____________________________________" << endl << endl;
	/*----------- ����� � ���� ------------- */
	TryPer.print();
	/*----------- ���������� ��������� = ------------- */
	/*----------- ������������ = ��� ���� ������ ������ String ------------- */
	/*----------- ������������ str ������� � str_return ������� ------------- */
	cout << "Before:      ";
	cout << TryPer.getstr() << endl;

	TryPer = str;
	cout << "After :      ";
	cout << TryPer.getstr() << endl;
	
	getch();
	delete str;
	getch();
}
