#include <conio.h>;
#include <stdio.h>;
#include <locale.h>;
#include <iostream>;
#include <stdlib.h>;
//������� 7 ������ �� ������ ���������������� �������� ������ ������� 1-4 
//�������� ���������, ������� ������ �� ������� � ���������� ���������
//������ � ��������� ����� ��� ��������� �� ��������.




							
int i, j;


using namespace std;


void main()
{
	setlocale(LC_ALL, "RUS");
	int pMasstry[20];
	int row;
	int column;
	i = 0;
	do
	{
	   cout << "������� "<< i << "������ �������: " << endl;
		gets_s(pMasstry, 20);
	} while (pMasstry == '\n');
	
	
	
	
	/*for (i = 0; i < 20; i++)
	{
		if (pMasstry[i] == ' ')
		{
			column++;
		}
	}

		
	/*	int **pmass1 = new int*[n]; 
	for (int i = 0; i < count_ROW; i++)
	{
		pmass1[i] = new int[count_column]; // ���-�� ��������
	}
	i = 0;
	*/	  

}
