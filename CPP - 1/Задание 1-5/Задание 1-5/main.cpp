#include <conio.h>;
#include <stdio.h>;
#include <locale.h>;
#include <iostream>;
#include <stdlib.h>;
//������� 7 ������ �� ������ ���������������� �������� ������ ������� 1-5
//��������� ������� ��������� ����� ������ �� 16
int loppfact;

int facrotial(int loppfact)
{
	int score,i ;
	score = 1;
	for (i = 1; i < loppfact+1; i++)
	{
	   	score = score * i;
	}
	return score;
}

using namespace std;
void main()
{
	setlocale(LC_ALL, "RUS");
	cout << "������� ��������� ������ ����� �� ������ �����!" << endl;
	if (!(cin >> loppfact))
	{
		cout << "�� ����� ��� �� ����������!��������� ���������!" << endl;
		return ;
	}
	else
	{
		cout << "��������� ����� �����:  " << facrotial(loppfact) << endl << "������� �� ������������� ������ �������!" << endl;
		_getch();
	}
}


