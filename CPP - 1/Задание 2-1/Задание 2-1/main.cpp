#include <conio.h>;
#include <stdio.h>;
#include <locale.h>;
#include <iostream>;
 

//������� 7 ������ �� ������ ���������������� �������� ������ ������� 2

using namespace std;

//��������� ������� ���������� �� ������ ����, ���� ���-�� �������� ������ ��� ����� ������������ �� ���������� ������� ������ , ���� ���-�� �������� ������ �� ������� ������� ������
// ���� ������� ������ ����� ���� �� ���������� 0, ���� ��� ���� �� ���������� 1. 



int i,j;
char mass[20];

int Pmyleft(char* scr,int count)
{
	char *pMass = new char[count];
	
	int i,j;
	j = 0;
	i = 0;
	// ������� ���������� ������������ ������ , ��������� ������� ��� ��������� 3 �����
	
	while (!(scr[i] == '\0'))
		{
			pMass[i] = scr[i];
			i++;
		}
	//1�� ��� ��� scr = count
	if (i == count)
	{
		
		for (j = 0; j < i; j++)
		{
			cout << scr[j];
		}
		
		return 1;
	}

	//2��  ���� ������� ������ ������ ��� count
	if (i < count)
		{
			
			for (j = 0; j < i; j++)
			{
				cout << scr[j];
			}
			
			return 1;
		}
	
	//������ - ��� count > �������� �������
	if (i > count)
	{
		
			for (i = 0; i < count; i++)
			{
				cout << pMass[i];

			}
			
			return 1;
	}
	else
	{
		 return 0;
	}
	

}



void main()
{
	setlocale(LC_ALL, "RUS");
	
	//���������	 ���
	for (i = 0; i < 20; i++)
	{
		//	cin >> mass[i];					 ���� ����� ������ ���� ���������� �������
		mass[i] = '1';					//�������� ��������� ��� ����� ������� ������������ ���������
		if (i == 19)
		{
			mass[i] = '\0';
		}
	}
	cout << "������� ������ ����� :"<< endl;
	for (i = 0; i < 20; i++)
	{
		cout << mass[i];
	}
	cout << endl;
	
	Pmyleft(mass, 13);
	cout << "\t ��������� ������ ������� ��� count < ������� ������� :" << endl;
	
	Pmyleft(mass, 40);
	cout  << "\t ��������� ������ ������� ��� count > ������� ������� : " << endl;
	
	Pmyleft(mass, 20);
	cout  << "\t ��������� ������ ������� ��� count = ������� ������� :" << endl;
	
	
	_getch();
	
	
	

}
