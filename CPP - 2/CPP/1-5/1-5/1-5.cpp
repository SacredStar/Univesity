#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <conio.h>

using namespace std;

class MyClass
{
public:
	MyClass();
	MyClass(int,int);
	~MyClass();
     int	ret_x1() { return x1; }
	 int	ret_x2() { return x2; }
	virtual void print();
    virtual  void set(int, int);

private:
	int x1, x2;
};

MyClass::MyClass()
{
	x1 = 0;
	x2 = 0;
	cout << " ќнструктор 1 сработал" << endl;
}
MyClass::MyClass(int x1_new,int x2_new)
{
	set(x1_new, x2_new);
	cout << "—–аботал конструктов из наследуемого класса" << endl;;
	getch();
}



MyClass::~MyClass()
{
	cout << "Destructin on work!Gl!" << endl; // —рабатывает после создани€ класса наследника
}

void MyClass::print()
{
	cout << "x1 равно:" << x1 << endl;
	cout << "x2 равно:" << x2 << endl;
	getch();
}
void MyClass::set(int x1_new, int x2_new)
{
	x1 = x1_new;
	x2 = x2_new;
	
}


class SecondMyClass : public MyClass
{
public :
	int y;
	void print();
	void set(int,int,int);
	void run();
	SecondMyClass();
	
	~SecondMyClass() { cout << "Destructin on 2nd class work!Gl!" << endl; };
};
SecondMyClass::SecondMyClass()
{
	y = 5;	
}
void SecondMyClass::print()
{
	MyClass::print();
	cout << "y равно:" << y << endl;
	getch();
	
}
void SecondMyClass::set(int y_new,int x1_new,int x2_new)
{
	MyClass::set(x1_new, x2_new);
	y = y_new;
}
void SecondMyClass::run()
{
	int summ,x1,x2;
	x1 = MyClass::ret_x1();
	x2 = MyClass::ret_x2();

	summ = x1 * y + x2;
	cout << summ << endl;
	getch();
}



void main()
{
	setlocale(LC_ALL, "RUS");

	SecondMyClass SecondMyclass_new;//—рабатывает деструктор нач класса :(
	MyClass *p;
	p = &SecondMyclass_new; //
	((SecondMyClass*)p)->print(); // принт производного класса
	((SecondMyClass*)p)->set(100,4,3); // —ет дочернего класса
	((SecondMyClass*)p)->print(); // принт дочернего класса
	((SecondMyClass*)p)->run(); // ран дочернего 
	getch();
}