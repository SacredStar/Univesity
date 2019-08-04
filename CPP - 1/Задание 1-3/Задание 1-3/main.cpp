#include <conio.h>;
#include <stdio.h>;
#include <locale.h>;
#include <iostream>;
#include <stdlib.h>;
#include <math.h>;
//Вариант 7 Работы по языкам программирования высокого уровня задание 1-3


using namespace std;
int i,count1;
char convert;
char mass[2]; //16 -ое число
int endNumber;
bool close;

void main()
{
	close = true;
	endNumber = 0;
	setlocale(LC_ALL, "RUS");
	cout << "Введите 16-ичное число" << endl;
	//Считываем записываем в массив чаров
	for (i = 0; i < 2; i++)
		{
			cin >> mass[i];
		}
	for (i = 0; i < 2; i++) 
		{
		switch (mass[i])
				{
			case 'A':  mass[i] = 10; break;
			case 'B':  mass[i] = 11; break;
			case 'C':  mass[i] = 12; break;
			case 'D':  mass[i] = 13; break;
			case 'E':  mass[i] = 14; break;
			case 'F':  mass[i] = 15; break;
			case '1':  mass[i] = 1; break;
			case '2':  mass[i] = 2; break;
			case '3':  mass[i] = 3; break;
			case '4':  mass[i] = 4; break;
			case '5':  mass[i] = 5; break;
			case '6':  mass[i] = 6; break;
			case '7':  mass[i] = 7; break;
			case '8':  mass[i] = 8; break;
			case '9':  mass[i] = 9; break;
			default: cout << "Вы ввели неверный символ!не надо так!" << endl; close = false;break;
			break;
				} 
		}
	
	//переводим в 2-ичную
	
	if (!(close == false))
	{
		for (i = 1, count1 = 0; i >= 0; i--, count1++)
		{
			endNumber = endNumber + mass[i] * pow(16, count1);
		} 
		cout << "Число в 10ичной системе равно: " << endNumber << endl;
	}
	else cout << " Ну что же ты делаешь!Не надо так! программа завершена" << endl;

	_getch();



}