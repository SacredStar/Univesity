// new_delete_array2.cpp: ���������� ����� ����� ��� ����������� ����������.


#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
	srand(time(0)); // ��������� ��������� �����
					// ������������ �������� ���������� ������� ������������ ����� �� ������ ���������
	float **ptrarray = new float*[m]; // ��� ������ � �������
	for (int count = 0; count < m; count++)
		ptrarray[count] = new float[n]; // � ���� ��������
										// ���������� �������
	for (int count_row = 0; count_row < m; count_row++)
		for (int count_column = 0; count_column < n; count_column++)
			ptrarray[count_row][count_column] = (rand() % 10 + 1) / float((rand() % 10 + 1)); //���������� ������� ���������� ������� � ���������������� �� 1 �� 10
																							  // ����� �������
		// �������� ���������� ������������� �������
	for (int count = 0; count < 2; count++)
		delete[]ptrarray[count];
	system("pause");
	return 0;
}