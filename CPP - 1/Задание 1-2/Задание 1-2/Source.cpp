// new_delete_array2.cpp: определяет точку входа для консольного приложения.


#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
	srand(time(0)); // генерация случайных чисел
					// динамическое создание двумерного массива вещественных чисел на десять элементов
	float **ptrarray = new float*[m]; // две строки в массиве
	for (int count = 0; count < m; count++)
		ptrarray[count] = new float[n]; // и пять столбцов
										// заполнение массива
	for (int count_row = 0; count_row < m; count_row++)
		for (int count_column = 0; count_column < n; count_column++)
			ptrarray[count_row][count_column] = (rand() % 10 + 1) / float((rand() % 10 + 1)); //заполнение массива случайными числами с масштабированием от 1 до 10
																							  // вывод массива
		// удаление двумерного динамического массива
	for (int count = 0; count < 2; count++)
		delete[]ptrarray[count];
	system("pause");
	return 0;
}