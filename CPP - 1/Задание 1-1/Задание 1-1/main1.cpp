/* #include <conio.h>;
#include <stdio.h>;
#include <locale.h>;
#include <iostream>;

//������� 7 ������ �� ������ ���������������� �������� ������ ������� 1-1

using namespace std;
int mass[300]; //������ ����� ���������

int ascii; //��� ��������� � �������� �����
int i, j;
bool answ = true;
void que()
{
	
	setlocale(LC_ALL, "RUS");
	cout << "������� ������������������ ������������� ����� �����,��� ���������� ����� ������� '0000' " ;
	
	int i = 0;
	int j = 0;
	do
		{
		  A:cin >> mass[i];
		    
		j = abs(mass[i]);
		if (isdigit(j)) //���� ����� �� ����������
			{
				if (mass[i] < 0)
				{
					cout << "��������� ����� ������ " << endl;
					i++;
					goto A;
				}
				if (mass[i] > 0)
				{
					cout << "������� ������������� �����! " << endl;
					goto A;
				}
				else
				{
					cout << "������� ������ �����! " << endl;
					goto A;
				}
			}
			
		else
			{
				cout << "������� �����!" << endl;
				goto  A;
			}
		} 
	while (mass[i] == '0000');
}
*/
		
		
		


