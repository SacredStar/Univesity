#include <conio.h>;
#include <stdio.h>;
#include <locale.h>;
#include <iostream>;
 

//Вариант 7 Работы по языкам программирования высокого уровня задание 2

using namespace std;

//Написания функции выравнивая по левому краю, если кол-во символом меньше чем длина выравнивания то возвращаем входную строку , если кол-во символов больше то урезаем входной массив
// Если входной массив равен нулю то возвращаем 0, если все окей то возвращаем 1. 



int i,j;
char mass[20];

int Pmyleft(char* scr,int count)
{
	char *pMass = new char[count];
	
	int i,j;
	j = 0;
	i = 0;
	// Сделаем внутренний динамический массив , посомтрим счетчик для выведения 3 типов
	
	while (!(scr[i] == '\0'))
		{
			pMass[i] = scr[i];
			i++;
		}
	//1ый тип что scr = count
	if (i == count)
	{
		
		for (j = 0; j < i; j++)
		{
			cout << scr[j];
		}
		
		return 1;
	}

	//2ой  если входной массив больше чем count
	if (i < count)
		{
			
			for (j = 0; j < i; j++)
			{
				cout << scr[j];
			}
			
			return 1;
		}
	
	//Третий - Что count > входного массива
	if (i > count)
	{
		
			for (i = 0; i < count; i++)
			{
				cout << pMass[i];

			}
			
			return 1;
	}
	else
	{
		 return 0;
	}
	

}



void main()
{
	setlocale(LC_ALL, "RUS");
	
	//Заполняем	 его
	for (i = 0; i < 20; i++)
	{
		//	cin >> mass[i];					 Если нужен ручной ввод начального массива
		mass[i] = '1';					//заполним единицами для более легкого тестирования программы
		if (i == 19)
		{
			mass[i] = '\0';
		}
	}
	cout << "Входная строка равна :"<< endl;
	for (i = 0; i < 20; i++)
	{
		cout << mass[i];
	}
	cout << endl;
	
	Pmyleft(mass, 13);
	cout << "\t Посмотрим работу функцию при count < размера массива :" << endl;
	
	Pmyleft(mass, 40);
	cout  << "\t Посмотрим работу функцию при count > размера массива : " << endl;
	
	Pmyleft(mass, 20);
	cout  << "\t Посмотрим работу функцию при count = размера массива :" << endl;
	
	
	_getch();
	
	
	

}
