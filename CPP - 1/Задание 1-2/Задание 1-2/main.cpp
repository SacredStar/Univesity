#include <conio.h>;
#include <stdio.h>;
#include <locale.h>;
#include <iostream>;
#include <stdlib.h>;
//Вариант 7 Работы по языкам программирования высокого уровня задание 1-2

int count_ROW, count_column;//Строки - столбцы


//int count;	  //Число /мин Число/цикл
int i,j,tryINT;
int minNumber; //мин Число
//int range_max, range_min; //Для работы функции rand.Мин-макс диапозон




using namespace std;
void main()
{	
	setlocale(LC_ALL, "RUS");
	// Вводим строки
	cout << "Введите кол-во строк массива: " << endl;
	if (!(cin >> count_ROW))
	{
		cout << "Вы ввели какую то неведомую штуку, не надо так!" << endl;
		_getch();
	}
	else if (count_ROW < 0)
	{
		cout << "Ну не может быть отрицательное кол-во строк!Не надо так!" << endl;
		cin.clear();
		_getch();
	}
	else cout << "Кол-во строк равняется:" << count_ROW << endl << endl;
	
	//Вводим столбцы
	cout << "Введите кол-во столбцов массива: " << endl;
	if (!(cin >> count_column))
	{
		cout << "Вы ввели какую то неведомую штуку, не надо так!" << endl;
		cin.clear();
		_getch();
	}
	else if (count_column < 0)
	{
		cout << "Ну не может быть отрицательное кол-во строк!Не надо так!" << endl;
		cin.clear();
		_getch();
	}
	else cout << "Кол-во столбцов равняется:" << count_column << endl << endl;
    
	
	cout << "Заполним массив: " << endl;
	//Создадим массив count_ROW x count_column
	int **pmass1 = new int* [count_ROW]; // кол-во строк
	for (int i = 0; i < count_ROW; i++)
	{
	   pmass1[i] = new int [count_column]; // кол-во столбцов
	}
	
	cin.clear();
	// Заполняем массив
	for (i = 0; i < count_ROW; i++)
	{
		for (j = 0; j < count_column; j++)
		{
			if (!(cin >> tryINT))
			{
				
				cout << "Вводи правильные числа в след раз!Программа завершена!";
				break;
			}
			else
			{
				pmass1[i][j] = tryINT;
				continue;
			}
		}
	}

	// Выведем массив на экран
	for (i = 0; i < count_ROW; i++)
	{
		for (j = 0; j < count_column; j++)
		{
			
			cout << pmass1[i][j] << "\t";
		}
		cout << endl;
	}
	
	//найдем наименьший положительный
	
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
		cout << "Минимальное положительное число в строке " << i << " равняется: " << minNumber << endl;
	}


	//Удалим массив из памяти 
	/* for (int i = 0; i < count_ROW; i++)
	{
		delete []pmass1[i]; // кол-во столбцов
	}
		 */
	_getch();
	

} 
   




