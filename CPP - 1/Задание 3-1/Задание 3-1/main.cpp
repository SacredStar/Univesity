#include <conio.h>;
#include <stdio.h>;
#include <locale.h>;
#include <iostream>;

//������� 7 ������ �� ������ ���������������� �������� ������ ������� 3-1
// ��� - ���������������� ���������
// ������� - Int
// ����� ����� ����� �� �����, ���������� � ���������� � ����� ����	�������� ����� �����.


typedef struct listing
	{
		//struct listing  *prev;
		int value;
		struct listing  *next;	 //��������� �� ����  �������
	} List1 ;  




using namespace std;

List1* push(List1 **head,List1 **p, int data) 												//������� ��� ����� ������ �� ��������
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




void print ( List1 **head)														 //����� �� ������
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

List1* find(List1 **head,int data)									 //������� ������ ������������ ����� ������
{
	List1 *test = (List1*)malloc(sizeof(List1));
	int count = 0;
	int i = 0;
	//bool flag = false;
	do {
		 if ((*head)->value == data)
			{
				//cout << "������ �������" <<(*head)->value << " ����������� � ���������, ��������� ��� �����." << endl;
				//flag = true;
				return (*head);
			}
		  else count++; (*head) = (*head)->next;
	} while (!((*head) == test));
	return *head;
		
} 

void enter(List1 **head,List1 ** starthead, int data)							  //������� ������� �������� ��  ��� ������� ���������
{
	List1 *temp = NULL;										   //����������  � Push
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
	List1 *head = NULL;	 //��������� �� ������ ���������� ����� ����
	List1* Shead = NULL; //������ ������
	//List1 *p = (List1*)malloc(sizeof(List1));
	//ist1 *p2 = (List1*)malloc(sizeof(List1));
	
	int value;
	for (i = 0; i <10; i++)		 //������ �������� � ������
	{
		if (i==0)
		{
		  Shead =  push(&head,&Shead,i);
		}
		else push(&head,&Shead ,i);
				//value = i;
		
		/*	cout << "������� ������� ������" << endl;
			if (!(cin >> value))
			{
				push(&head, value);				 // ������ �����. ��� �������� ������������ �������� ���������� �� 0 �� 10
			}
			else continue;
		} */
	}
	(Shead)->next = (head);	  //������ ���� ������ ���?

	
	
	print(&head);
	cout << endl;
	List1 *pt = NULL;
    pt = find(&head,2) ;
	enter(&pt, &Shead, 99);
//	push(&pt, &Shead, 999);
	print(&head);
	_getch();



}