#include <conio.h>;
#include <stdio.h>;
#include <locale.h>;
#include <iostream>;
#include <math.h>;

// ������� 7 ������ �� ������ ���������������� �������� ������ ������� 1-6
// � ����� � ��� ��� �� ������� �� ����� �������� ��� �������� ����� � ����������� ������ �������� � ����� 0:0  ������ ��� ��� ���� . �� ������� ������ ���������.
// ��������� ������ y = kx + c ,�� ������ ��������� c=0, ���� ������� y=0/5 x, y=0.5 -x
// ��������� ��� �������� � ���� y = sqrt(1-pow(x,2));

float y, x, dotX,dotY;
using namespace std;

void main()
{
	  setlocale(LC_ALL, "RUS");

	  //������ ���������� �����
	  cout << "�������  ���������� X ������� ����� : " << endl;
	  if (!(cin >> dotX))
	  {
		  cout << "�� ����� ������� ���-�� �� ��!�� ���� ���!��������� ���������" << endl;
		  _getch();
		  return;
	  }
	  cout << "�������  ���������� Y ������� ����� : " << endl;
	  if (!(cin >> dotY))
	  {
		  cout << "�� ����� ������� ���-�� �� ��!�� ���� ���!��������� ���������" << endl;
		  _getch();
		  return;
	  }
	  //�������� ������ �� � �������
	  if ((dotY <= sqrt(1-pow(x, 2))) && ((dotY >=0.5 * dotX) && (dotY >= -0.5 *  dotX)))
	  {
		  cout << "����� �������� � ������. ������� ����� ���������� �����." << endl;								//������� ����� �����
		  _getch();
		  
	  }

	  if ((dotY >= sqrt(1-pow(x, 2)) || (dotY >= -sqrt(1-pow(x, 2)))) && ((dotY > 0.5 *  dotX) && (dotY <- 0.5 *  dotX)))
	  {
		  cout << "����� �������� � ������. ����� ����� �� ������." << endl;				 // ����� ����� �� ������
		  _getch();
		  
	  }
	  if ((dotY >= -sqrt(1-pow(x, 2))) && ((dotY < 0.5 *  dotX) && (dotY < -0.5 *  dotX)))
	  {
		  cout << "����� �������� � ������. ������ ����� ����������� �����." << endl;				 // ������ ����� �����
		  _getch();
		  
	  }

	  if ((dotY >= sqrt(1-pow(x, 2)) || (dotY >= -sqrt(1-pow(x, 2)))) && ((dotY < 0.5 *  dotX) && (dotY > -0.5 * dotX)))
	  {
		  cout << "����� �������� � ������. ������ ����� �� ������." << endl;				 // ������ ����� �� ������
		  _getch();
		  
	  }
	  else cout << "����� ��� �������, �������� �� ����������� �����)" << endl;
	  _getch();
}







