#include <stdio.h>
#include <iostream>
//#include <time.h>
//#include <ctime>
#include <locale.h>
#include <conio.h>
#include <cmath>


using namespace std;

class MyClass
{
public:
	MyClass();
	MyClass(double, double, double);
	~MyClass();
	friend void print(MyClass &s);
	friend void run(MyClass &s);
	double getx() { return x; }
	double gety() { return y; }
	double getz() { return z; }
private:
	double x, y, z, gamma;
};

MyClass::MyClass()
{
	x = 0.1722;
	y = 6.33;
	z = 0.000325;

}
MyClass::MyClass(double pub_x, double pub_y, double pub_z)
{
	x = pub_x;
	y = pub_y;
	z = pub_z;
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "z: " << z << endl;
	getch();
}

MyClass::~MyClass()
{
	cout << "destruction on work" << endl;
}

void print(MyClass &s)
{
	cout << "X: " << s.x << endl;
	cout << "Y: " << s.y << endl;
	cout << "Z: " << s.z << endl;
	getch();
	// cout << "gamma = 5 * arctg(x) - arccos(x) * (x+3|x-y|+x^2)/(4*(|x-y|*z + x^2)" << gamma << endl;
}


void run(MyClass &s)
{
	double module = 0;
	module = abs(s.x - s.y);
	s.gamma = 5 * atan(s.x) - 0.25 * acos(s.x) *((s.x + 3.0 * module + s.x *s.x) / (module * s.z + s.x * s.x));
	cout << "gamma = " << s.gamma << endl;;
	getch();
}



void main()
{
	setlocale(LC_ALL, "RUS");

	cout << "  " << endl;
	cout << "_______________________________________________________________" << endl;

	MyClass *d1 = new MyClass;
	print(*d1);
	run(*d1);
	getch();
	delete d1;
	getch();

}

