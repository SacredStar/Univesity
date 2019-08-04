#include <conio.h>;
#include <stdio.h>;
#include <locale.h>;
#include <iostream>;
#include <stdlib.h>;
//Вариант 7 Работы по языкам программирования высокого уровня задание 1-4 
//Написать программу, которая вводит по строкам с клавиатуры двумерный
//массив и вычисляет сумму его элементов по столбцам.




							
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
	   cout << "Введите "<< i << "строку массива: " << endl;
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
		pmass1[i] = new int[count_column]; // кол-во столбцов
	}
	i = 0;
	*/	  

}
