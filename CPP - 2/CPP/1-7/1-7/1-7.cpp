#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <cmath>
#include <ostream>
#include <fstream>
// name,type,page_count,books_month
using namespace std;

class PeriodicBase
{
public:
	PeriodicBase();
	//PeriodicBase(char,char,int,int);
	~PeriodicBase();
	virtual void set(char* name_new, char* type_new, int page_count_new, int books_month_new) = 0;
	virtual void print() = 0;
	//friend virtual void Run() = 0;
	char* name;
	char* type;
	int books_month;
private:

};

PeriodicBase::PeriodicBase(){}
PeriodicBase::~PeriodicBase(){}

class PeriodicBasePage
{
public:
	PeriodicBasePage() {};
	~PeriodicBasePage() {};
	int page_count;
	void virtual print() = 0;
private:
};


class Child: public PeriodicBase,public PeriodicBasePage
{
	public:
		Child();
		~Child();
		Child(char*, char*, int, int);
		friend  void Run(Child &obj);
		void print();
		void print_to_file();
		void set(char* name_new, char* type_new, int page_count_new, int books_month_new);

	private:
		int books_year;
};

Child::Child()
{
	name = new char[265];
	name = "Undefined";
	type = new char[265];
	type = "undefined";
	page_count = 300;// ����������� ���-��
	books_month = 1;
}
Child::Child(char* name_new, char* type_new, int page_count_new, int books_month_new)
{
	name = new char[strlen(name_new)];
	strcpy(name, name_new);
	type = new char[strlen(name_new)];
	strcpy(type, type_new);
	page_count = page_count_new;
	books_month = books_month_new;
}

void Run(Child &obj)
{
	obj.books_year = obj.books_month * 12;
}

void Child::print()
{
	cout << "��������: " << name << endl;
	cout << "��� �������: " << type << endl;
	cout << "�������: " << page_count << endl;
	cout << "���� � �����: " << books_month << endl;
	cout << "���� � ���: " << books_year << endl; //��������� ��� ��� ��������
}

void Child::print_to_file()
{
	
	ofstream file_out;
	
	try
	{
		file_out.open("test.txt", ios::_Nocreate); // ������ ��� �����
		if (!file_out.is_open())
		{
			throw "File not created";
		}
	}

	catch (char a)
	{
		cout << a << endl;
		file_out.open("test.txt");
	}
	try
	{
		file_out << name << endl;
		file_out << type << endl;
		file_out << page_count << endl;
		file_out << books_month << endl;
		file_out << books_year << endl;
	}
	catch (const std::exception&)
	{

	}
		
		file_out.close();

}

void Child::set(char* name_new, char* type_new, int page_count_new, int books_month_new)
{
	strcpy(name, name_new);
	strcpy(type, type_new);
	page_count = page_count_new;
	books_month = books_month_new;
}


Child::~Child(){}


void main()
{
	try
	{
		setlocale(LC_ALL, "RUS");
		Child Shildt("�����", "������� �������", 356, 2);
		Run(Shildt);
		Shildt.print();
		Shildt.print_to_file();
		getch();
	}
	catch (const std::exception&)
	{
		cout << " �� �� ����� ��� ������" << endl;
	}
	

	

	
}

	
