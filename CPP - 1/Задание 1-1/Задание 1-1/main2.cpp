#include <conio.h>;
#include <stdio.h>;
#include <locale.h>;
#include <iostream>;
//������� 7 ������ �� ������ ���������������� �������� ������ ������� 1-1

double number, minNumber;
int loop;	  //����� /��� �����/����
int i;

void main()
{
	using namespace std;
	setlocale(LC_ALL, "RUS");
	cout << "������ ���-�� �����: " << endl;
	if (!(cin >> loop))
	{
		if (loop > 1)
		{
			cout << " all good, ���-��  �����  = " << loop << endl;;
		}
		else
		{
			cout << " �� ������� ��� ���-�� ����� ������������� ���� �� ����� 1!�� ���� ���!��������� ��������.";
			_getch();
			return;
		}
	}
	char test;			 //    /�������� ��� �� ������� ���-�� ���������� ��� 4.5
	test = cin.peek();
	cout << "������� ������ ��� �� ����������" << endl;;
	while (!(test == ' '))
		{
			test = cin.peek();
			cin.ignore();
		}

		cout << "����� ������������� �����" << endl;

		A:for (i = 0; i != loop; i++)						  //���� ��� �����
		{
			if (!(cin >> number))
			{
				cout << "������ �����!�� ���� ������� ���-�� ����������!" << endl;
				getch();
				break;
			}
			else if (number > 0)
			{

				cout << "�������� ����� ������ ����!�� ���� ��� ������!����� ������������� �����! ����� ��������� �����" << endl;
				cin.clear();
				continue;
			}
			else
			{
				//cin >> number;
				cout << " ��� �����!�������! ���������! ��������� ����� = " << number << endl;
				cin.clear();

				//��������� �� ���.
				if (number < minNumber)
				{
					minNumber = number;
				}
			}
		}

		if (i == loop)						   //��� �� ��� ������ ����
			{
					cout << "������ ����������? ���� �� ����� ����� �����, ���� ��� ����� ���������" << endl;
					if (!(cin >> loop))
					{
						cin.clear();
						cout << "����������� ����� = " << minNumber << endl;
						getch();
					}
					else
					{
						i = 0; goto A;
					}
			}

		_getch();
}