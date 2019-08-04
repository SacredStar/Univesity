/* #include <conio.h>;
#include <stdio.h>;
#include <locale.h>;
#include <iostream>;

//Вариант 7 Работы по языкам программирования высокого уровня задание 1-1

using namespace std;
int mass[300]; //массив чисел начальный

int ascii; //для сравнения с таблицей аскай
int i, j;
bool answ = true;
void que()
{
	
	setlocale(LC_ALL, "RUS");
	cout << "Введите последовательность отрицательных целых чисел,для завершения ввода введите '0000' " ;
	
	int i = 0;
	int j = 0;
	do
		{
		  A:cin >> mass[i];
		    
		j = abs(mass[i]);
		if (isdigit(j)) //Если число то продолжить
			{
				if (mass[i] < 0)
				{
					cout << "Вввденное число верное " << endl;
					i++;
					goto A;
				}
				if (mass[i] > 0)
				{
					cout << "Введите отрицательное число! " << endl;
					goto A;
				}
				else
				{
					cout << "Введите верное число! " << endl;
					goto A;
				}
			}
			
		else
			{
				cout << "Введите число!" << endl;
				goto  A;
			}
		} 
	while (mass[i] == '0000');
}
*/
		
		
		


