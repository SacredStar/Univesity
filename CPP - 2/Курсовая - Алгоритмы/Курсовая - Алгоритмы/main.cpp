#include <conio.h>
#include <time.h>
#include <iostream>
#include <ostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Globar var
int operation = 0;
int SIZE =10000000;

int* create_massive(int, int, int);
int* shell_sort(int*,int);

class Que
{
public:
	//static const int SIZE = 100; // кол - во элементов - 1, тк хеад не определен
	Que();
	~Que();
	bool is_empty();
	bool push(int); //добавить tail
	bool pop(); //Удалить head
	void print();
	bool init(int);
	int size();	
	int head_ret();
	int tail_ret();
	void set(int ,int);
	int get(int);
	friend void shell_sort(Que &);
	bool print_to_file();
	bool read_fr_file();
private:
	int* que;
	int head;
	int tail;
};

Que::Que() //5
{
	operation += 5;
	que = new int[SIZE];//пока работаем с SIZE элементами
	head = tail = 0;
	//TEST::вначале очередь состоит из одного 0  = FALSE 
	//que[head] = que[tail] = 0; 
}

Que::~Que()
{
}

bool Que::is_empty() //2
{
	operation += 2;
	if (head == tail) //1
	{
		return false; //1
	}
	return true; //1
}

bool Que::push(int new_el) // 9 || 8
{
	operation += 9;
	if (tail + 1 == head || (tail + 1 == SIZE && !head)) // 7 
	{
		return false; //очередь заполнена //2
	}
	else
	{
		tail++; //2
		if (tail == SIZE) tail = 0; //3
		que[tail] = new_el; //1
	}
	return true; // успешно добавлен элемент в хвост //2
}

bool Que::pop() // 6||3
{
	operation += 6;
	if (head == tail) //1
	{
		return false; //очередь пустая //2
	}
	else
	{
		head++; //2
		if (head == SIZE) //1
		{
			head = 0; //прошли весь que //1
		}
	}
	return true; //2
}

void Que::print() //n+4
{
	operation += SIZE+4;
	cout << "Вывод очереди: " << endl; //2
	for (int i = head+1;i < tail+1;i++) // n
	{
		cout << " " << que[i]; //2
	}
}

bool Que::init(int count) // 19n-2
{
	operation += 19*SIZE - 2;
	int* mass1 = new int[count]; //2
	mass1 = create_massive(count, 100000,-100000); //1 +10n+3
	//заполняем список
	for (int i = 0;i < count - 1;i++)  //n-1
	{
		push(mass1[i]); //9 || 8 
	}
	return false; //1
}

int Que::size() // 2n+3
{
	operation += 2*SIZE +3;
	int count = 0; //2
	for (int i = head; i < tail; i++) //n 
	{
		count++; //2
	}
	return count; //1
}

int Que::head_ret()
{
	operation += 1;
	return que[head+1];
}

int Que::tail_ret()
{
	operation += 1;
	return que[tail];
}

void Que::set(int i,int j)
{
	operation += 2;
	que[i] = j;
}

int Que::get(int i)
{
	operation += 1;
	return que[i];
}

bool Que::print_to_file() // 2n+1
{
	operation += 2*SIZE +1;
	ofstream file_out; //1
	file_out.open("test.txt"); //1
	if (!file_out.is_open()) //4
	{
		cout << "file cant be opened" << endl;
		getch();
		return false;
	}
	else
	{
		for (int i = head + 1;i < tail + 1;i++) // n
		{
			file_out << " " << que[i]; //2
		}
		file_out.close();
		return true;
	}
}

bool Que::read_fr_file()
{
	operation += 1;
	ifstream file;
	file.open("test.txt"); // меняем название при изменение кол-ва SIZE
	if (file.is_open())
	{
		for (int i = 1; i < SIZE; i++)
		{
			int q;
			file >> q;
			push(q);
		}
		file.close();
		return true;
	}

	return false;
}

void shell_sort(Que &q) // n/2*n(6+(n/n-3)*4) =  4n/n +21 * n^2/2 =  25n/n*n^2/2 = 25n^2/2
						//сортировка для очереди
						//Переделать что бы не было произвольного доступа или нет?
{
	operation += 12.5 * SIZE + 1;
	int count = q.size(); //2
	int i, j, step; 
	int mass_change; 
	for (step = count / 2; step > 0; step /= 2) // n/2
 		for (i = step; i <= count; i++) //n
		{
			mass_change = q.get(i); //3
			for (j = i; j >= step; j -= step) // n /n-3
			{
				if (mass_change < q.get(j - step)) //3
				{
					q.set(j, q.get(j - step)); //3+ +1
				}
					
				else
					break; //1
			}
			q.set(j, mass_change); //3
		}
}

void main()
{
	auto start = steady_clock::now();
	int count = SIZE; //изменяем вместе с SIZE
	setlocale(LC_ALL, "RUS");
	Que pQ;
	pQ.init(count);
	pQ.print();
	pQ.print_to_file();
	shell_sort(pQ);
	pQ.print();
	pQ.print_to_file();
	cout << endl;
	cout << pQ.head_ret() << endl;
	cout << pQ.tail_ret() << endl;
	auto finish = steady_clock::now();
	cout << duration_cast<milliseconds>(finish - start).count() << "ms" << endl;
	cout << operation << endl;
	getch();
	/*TEST:массив = TRUE
	for (int i = 0;i < count;i++)
	{
		cout << " " << mass1[i];
		file_out << " " << mass1[i];
	}
	cout << endl << endl;
	shell_sort(mass1,count);
	for (int i = 0;i < count;i++)
	{
		cout << " " << mass1[i];
		file_out << " " << mass1[i];
	}
	getch();
	*/
}

int* create_massive(int count, int range_max, int range_min) //10n+3
{
	int i;
	int *p;
	p = new int[count];  //выделяем память для count элементного массива //2

	srand((unsigned)time(NULL)); //1
	for (i = 0; i < count; i++) //n*10
	{
		p[i] = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min; // 10
		p[i + 1] = '\0'; //2
	}
	return p;//2
}

int* shell_sort(int* mass, int count)
{
	int i, j, step;
	int mass_change;
	for (step = count / 2; step > 0; step /= 2)
		for (i = step; i < count; i++)
		{
			mass_change = mass[i];
			for (j = i; j >= step; j -= step)
			{
				if (mass_change < mass[j - step])
					mass[j] = mass[j - step];
				else
					break;
			}
			mass[j] = mass_change;
		}
	return mass;
}

	/* TEST:: шел сорт при установленном d = FALSE
	for (d1=count/2;d1>0;d1=d1/2)//пробегаем половину элементов +1 на всякий
	{
		for (int j = d1;j <count/2;j++)
		{
			mass_change = mass[j];
			//cout << j << " прическа d1: ";
			for (i = j;i >= d1;i = i - d1)
			{
				if (mass_change <mass[i + d1])
				{
					mass[i] = mass[i + d1];
				}
				else break;
			}
			mass[i] = mass_change;
		}
	*/	


