#include <conio.h>;
#include <stdio.h>;
#include <locale.h>;
#include <iostream>;
//Вариант 7 Работы по языкам программирования высокого уровня задание 1-1

double number, minNumber;
int loop;	  //Число /мин Число/цикл
int i;

void main()
{
	using namespace std;
	setlocale(LC_ALL, "RUS");
	cout << "Ввведи кол-во чисел: " << endl;
	if (!(cin >> loop))
	{
		if (loop > 1)
		{
			cout << " all good, кол-во  чисел  = " << loop << endl;;
		}
		else
		{
			cout << " Вы сказали что кол-во чисел отрицательное либо же равно 1!не надо так!Программа звершена.";
			_getch();
			return;
		}
	}
	char test;			 //    /Проверка что не введено что-то непонятное аля 4.5
	test = cin.peek();
	cout << "Введите пробел что бы продолжить" << endl;;
	while (!(test == ' '))
		{
			test = cin.peek();
			cin.ignore();
		}

		cout << "Введи отрицательное число" << endl;

		A:for (i = 0; i != loop; i++)						  //Цикл для круга
		{
			if (!(cin >> number))
			{
				cout << "Ввведи число!Не надо вводить что-то непонятное!" << endl;
				getch();
				break;
			}
			else if (number > 0)
			{

				cout << "Введеное число больше нуля!Не надо так делать!Введи отрицательное число! Вводи следующее число" << endl;
				cin.clear();
				continue;
			}
			else
			{
				//cin >> number;
				cout << " Все верно!Молодец! продолжай! Введенное число = " << number << endl;
				cin.clear();

				//сравнение на мин.
				if (number < minNumber)
				{
					minNumber = number;
				}
			}
		}

		if (i == loop)						   //Что бы был вечный ввод
			{
					cout << "Хочешь продолжить? Если да введи число чисел, если нет введи белеберду" << endl;
					if (!(cin >> loop))
					{
						cin.clear();
						cout << "Минимальное число = " << minNumber << endl;
						getch();
					}
					else
					{
						i = 0; goto A;
					}
			}

		_getch();
}