#include <conio.h>;
#include <stdio.h>;
#include <locale.h>;
#include <iostream>;
#include <stdlib.h>;
//Вариант 7 Работы по языкам программирования высокого уровня задание 1-5
//Программа считает факториал числа вплоть до 16
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
	cout << "Введите факториал какого числа вы хотите найти!" << endl;
	if (!(cin >> loppfact))
	{
		cout << "Вы ввели что то непонятное!Программа завершена!" << endl;
		return ;
	}
	else
	{
		cout << "Факториал числа равен:  " << facrotial(loppfact) << endl << "Спасибо за использование нашего сервиса!" << endl;
		_getch();
	}
}


