#include <stdio.h>
#include <iostream>
#include <time.h>
#include <ctime>
#include <locale.h>
#include <conio.h>

using namespace std;


int* create_massive(int, int, int);


void main()
{
	setlocale(LC_ALL, "RUS");;
	int i;
	int mass1_count = 0;
	int	mass2_count = 0;
	int *mass1, *mass2;
	int count;
	cout << "enter count" << endl;
	cin >> count;


	mass1 = create_massive(count, 100, -100);
	mass2 = create_massive(count, 10, -60);

	for (i = 0; i < count; i++) //������� ����� �������� 
	{

		if (mass1[i] < 0)
		{
			mass1_count++;
		}
		if (mass2[i] < 0)
		{
			mass2_count++;
		}
	}

	cout << "mass1count:" << mass1_count << endl;
	cout << "mass2count:" << mass2_count << endl;

	if (mass1_count >= mass2_count)
	{
		cout << "mass 1:" << endl;
		for (i = 0; i < count; i++)
		{
			cout << mass1[i] << '|' << ' ';
		}
		cout << endl;
		for (i = 0; i < count; i++)
		{
			cout << mass2[i] << '|' << ' ';
		}
	}

	else
	{
		cout << "mass 2 >:" << endl;
		for (i = 0; i < count; i++)
		{
			cout << mass2[i] << '|' << ' ';
		}
		cout << endl;
		for (i = 0; i < count; i++)
		{
			cout << mass1[i] << '|' << ' ';
		}
	}
	cin.clear();
	_getch();
}




int* create_massive(int count, int range_max, int range_min)
{
	int i;
	int *p;
	p = new int[count];  //�������� ������ ��� count ����������� �������

	srand((unsigned)time(NULL));
	for (i = 0; i < count; i++)
	{
		p[i] = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;

	}
	return p;
}