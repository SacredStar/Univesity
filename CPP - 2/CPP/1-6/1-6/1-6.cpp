#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <cmath>

using namespace std;

template <typename T> 
class Mass
{
	T *mass_Ptr;
	int size;
	
public:
	 Mass();
	 ~Mass();
	void print();
	void set(T*);

private:

};

template <typename T> 
Mass<T>::Mass()
{

	int n = 10;
	size = n;
	mass_Ptr = new T[size];	
}

template <typename T>
Mass<T>::~Mass()
{
	delete[] mass_Ptr;
	cout << "сработал деструктор!" << endl;
}

template <typename T>
void Mass<T>::set( T* value) //Вставка элемента 
{
	int i = 0;
	
	
	int j;
	for(i=0,j=1;i<10;i++,j++)
	{
		if (std::is_same<T, char>::value) //Обработка чара
		{
			int change_int;
			change_int = (int)value[i] * j;
			mass_Ptr[i] = change_int%256;
			continue;
		}
		mass_Ptr[i] = value[i]* j;
	}
	
}


// вывод массива на экран
template <typename T>
void Mass<T>::print()
{
	for (int i = 0;i < 10;i++)
	{
		cout << "Элемент массива равен:  " << mass_Ptr[i] << endl;
	}
}

void main()
{
	setlocale(LC_ALL, "RUS");
	int i = 0;
	int mass_int[10] = { 1,2,3,4,5,6,7,8,9,0 };
	float mass_float[10] = { 1.2,2.3,3.4,4.2,5,6,7,8,9,0 };
	char mass_char[10] = {'Д','e','c','я','т','ь','б','у','к','в'};
	Mass <int> myMass;
	cout << "Введем интовый маcсив : " << endl;
	myMass.set(mass_int);
	myMass.print();
	_getch();
	cout << "_______________________________________________________" << endl;
	cout << "Введем float маcсив : " << endl;
	Mass <float> myMass_fl;
	myMass_fl.set(mass_float);
	myMass_fl.print();
	_getch();
	cout << "_______________________________________________________" << endl;
	cout << "Введем char масcив : " << endl;
	Mass <char> myMass_ch;
	myMass_ch.set(mass_char); //буквы преобразованы в цифры, то бишь в аскай код
	myMass_ch.print();
	_getch();

			
}
