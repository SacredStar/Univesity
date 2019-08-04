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
	void set(double, double, double);;
	void print(void);
	void run(void);
	double getx() { return x; }
	double gety() { return y; }
	double getz() { return z; }
private:
	double x, y, z, gamma;
};

void MyClass::set(double pub_x, double pub_y, double pub_z)
{
	//cout << "������� �������� X: " << endl;
	//cin >> pub_x;
	x = pub_x;
	//cout << "������� �������� Y: " << endl;
	//cin >> pub_y;
	y = pub_y;

	//cout << "������� �������� Z: " << endl;
	//cin >> pub_z;
	z = pub_z;
}
void MyClass::print()
{
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "Z: " << z << endl;
	getch();
	// cout << "gamma = 5 * arctg(x) - arccos(x) * (x+3|x-y|+x^2)/(4*(|x-y|*z + x^2)" << gamma << endl;
}

void MyClass::run()
{
	double module1, module2;
	module1 = atan(x);
	module2 = acos(x);
	double module = 0;
	module = abs(x - y);
	gamma = 5 * atan(x) - 0.25 * acos(x) *((x + 3.0 * module + x * x) / (module * z + x * x));
	cout << "gamma = " << gamma << endl;;
	getch();
}



void main()
{
	setlocale(LC_ALL, "RUS");
	
	cout << "_______________________________________________________________" << endl;

	MyClass Function; //
	Function.set(0.1722, 6.33, 0.000325);
	Function.print();
	Function.run();
	getch();

	cout << "_______________________________________________________________" << endl;

	MyClass *f1 = &Function;
	f1->set(0.1722, 6.33, 0.000325);
	f1->print();
	f1->run();
	getch();


	cout << "_______________________________________________________________" << endl;

	MyClass *d1 = new MyClass;
	d1->set(0.1722, 6.33, 0.000325);
	d1->print();
	d1->run();
	getch();



}
