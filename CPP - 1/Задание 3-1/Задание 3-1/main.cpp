#include <conio.h>;
#include <stdio.h>;
#include <locale.h>;
#include <iostream>;

//Вариант 7 Работы по языкам программирования высокого уровня задание 3-1
// ТИП - Однонаправленный кольцевой
// Элемент - Int
// Найти целое число по числу, введенному с клавиатуры и после него	добавить новое число.


typedef struct listing
	{
		//struct listing  *prev;
		int value;
		struct listing  *next;	 //Указатель на след  елемент
	} List1 ;  




using namespace std;

List1* push(List1 **head,List1 **p, int data) 												//Функция для сбора списка из значений
{	
	List1 *tmp = (List1*)malloc(sizeof(List1));
	
	 if (data == 0)
	 {
		
		 tmp->value = data;
		 tmp->next = (*head);
		 (*p) = tmp;
		 (*head) = tmp;			
	}
	 
	else
	{
		tmp->value = data;
		tmp->next = (*head);
		(*head) = tmp;	
	}

	return *p;
}




void print ( List1 **head)														 //Вывод на печать
{	
	List1 *test = (List1*)malloc(sizeof(List1));
	test = *head;
	do
	{   
			cout << (*head)->value << "\t";
			(*head) = (*head)->next;
	 } 
	 while (!((*head) == test));

}

List1* find(List1 **head,int data)									 //Функция поиска возвращающая адрес списка
{
	List1 *test = (List1*)malloc(sizeof(List1));
	int count = 0;
	int i = 0;
	//bool flag = false;
	do {
		 if ((*head)->value == data)
			{
				//cout << "найдем елемент" <<(*head)->value << " совпадающий с введенным, вовзращаю его адрес." << endl;
				//flag = true;
				return (*head);
			}
		  else count++; (*head) = (*head)->next;
	} while (!((*head) == test));
	return *head;
		
} 

void enter(List1 **head,List1 ** starthead, int data)							  //Функция вставки значения за  тем которое передаете
{
	List1 *temp = NULL;										   //Аналогично  с Push
	temp = (List1*)malloc(sizeof(List1));
	
	temp->value = data;
	temp->next = (*head)->next;
	(*head)->next = temp;
	(*head) = temp;

} 

void main()
{	
	setlocale(LC_ALL, "RUS");
	int i;
	List1 *head = NULL;	 //Указатель на голову изначально равен нулю
	List1* Shead = NULL; //Первый список
	//List1 *p = (List1*)malloc(sizeof(List1));
	//ist1 *p2 = (List1*)malloc(sizeof(List1));
	
	int value;
	for (i = 0; i <10; i++)		 //Вводим елементы в список
	{
		if (i==0)
		{
		  Shead =  push(&head,&Shead,i);
		}
		else push(&head,&Shead ,i);
				//value = i;
		
		/*	cout << "Введите елемент списка" << endl;
			if (!(cin >> value))
			{
				push(&head, value);				 // Ручной вовод. Для удобства тестирования заполним елементами от 0 до 10
			}
			else continue;
		} */
	}
	(Shead)->next = (head);	  //Почему блин нельзя так?

	
	
	print(&head);
	cout << endl;
	List1 *pt = NULL;
    pt = find(&head,2) ;
	enter(&pt, &Shead, 99);
//	push(&pt, &Shead, 999);
	print(&head);
	_getch();



}