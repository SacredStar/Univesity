#include <conio.h>;
#include <stdio.h>;
#include <locale.h>;
#include <iostream>;
#include <stdlib.h>;
//������� 7 ������ �� ������ ���������������� �������� ������ ������� 1-2

int count_ROW, count_column;//������ - �������


//int count;	  //����� /��� �����/����
int i,j,tryINT;
int minNumber; //��� �����
//int range_max, range_min; //��� ������ ������� rand.���-���� ��������




using namespace std;
void main()
{	
	setlocale(LC_ALL, "RUS");
	// ������ ������
	cout << "������� ���-�� ����� �������: " << endl;
	if (!(cin >> count_ROW))
	{
		cout << "�� ����� ����� �� ��������� �����, �� ���� ���!" << endl;
		_getch();
	}
	else if (count_ROW < 0)
	{
		cout << "�� �� ����� ���� ������������� ���-�� �����!�� ���� ���!" << endl;
		cin.clear();
		_getch();
	}
	else cout << "���-�� ����� ���������:" << count_ROW << endl << endl;
	
	//������ �������
	cout << "������� ���-�� �������� �������: " << endl;
	if (!(cin >> count_column))
	{
		cout << "�� ����� ����� �� ��������� �����, �� ���� ���!" << endl;
		cin.clear();
		_getch();
	}
	else if (count_column < 0)
	{
		cout << "�� �� ����� ���� ������������� ���-�� �����!�� ���� ���!" << endl;
		cin.clear();
		_getch();
	}
	else cout << "���-�� �������� ���������:" << count_column << endl << endl;
    
	
	cout << "�������� ������: " << endl;
	//�������� ������ count_ROW x count_column
	int **pmass1 = new int* [count_ROW]; // ���-�� �����
	for (int i = 0; i < count_ROW; i++)
	{
	   pmass1[i] = new int [count_column]; // ���-�� ��������
	}
	
	cin.clear();
	// ��������� ������
	for (i = 0; i < count_ROW; i++)
	{
		for (j = 0; j < count_column; j++)
		{
			if (!(cin >> tryINT))
			{
				
				cout << "����� ���������� ����� � ���� ���!��������� ���������!";
				break;
			}
			else
			{
				pmass1[i][j] = tryINT;
				continue;
			}
		}
	}

	// ������� ������ �� �����
	for (i = 0; i < count_ROW; i++)
	{
		for (j = 0; j < count_column; j++)
		{
			
			cout << pmass1[i][j] << "\t";
		}
		cout << endl;
	}
	
	//������ ���������� �������������
	
	for (i = 0; i < count_ROW; i++)
	{
		minNumber = pmass1[i][0];
		for (j = 0; j < count_column; j++)
		{

			if (pmass1[i][j] < 0)
			{
				continue;
			}
			else if(minNumber > pmass1[i][j]) {
				minNumber = pmass1[i][j];
			}
		}
		cout << "����������� ������������� ����� � ������ " << i << " ���������: " << minNumber << endl;
	}


	//������ ������ �� ������ 
	/* for (int i = 0; i < count_ROW; i++)
	{
		delete []pmass1[i]; // ���-�� ��������
	}
		 */
	_getch();
	

} 
   




