#include <time.h>
#include <ctime>
#include <locale.h>
#include <conio.h>
#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

float RangedRandDemo1(int min, int max);
int RangedRandDemo(int min, int max);


using namespace std;

void main()
{
	string mystring[500];

	srand((unsigned)time(NULL)); // Rand number seed generator
	int date[15], summ[15];
	int i = 0;
	int k = 0;
	int j = 0;
	int flag;
	char newline = '\n';
	int byte_bel[16];
	int byte_uk[16];
	int byte_us[16];
	int byte_rus[16];
	double komm = 0.5;
	int BTC = 11000; // BTC Cost
	float satoshi = 0.00000001;
	float satoshi_doll = BTC * satoshi;
	//cout << satoshi_doll;
	
	ifstream file_inp;
	file_inp.open("test.txt");
	if (!file_inp.is_open())
	{
		cout << "File cant be oppened" << endl;
	}
	cout << "Reading transaction from bank  with ignoring cardnum:"<< endl;
	for(i=0;i < 15;i++) // Read from file/ ignoring cardnum
	{
		file_inp >> date[i];
		file_inp.ignore(13);
		file_inp >> summ[i];
		cout << "ID trx: " << i << "  ";
		cout << "Date: " << date[i] << "  ";
		cout <<"Summ: "<< summ[i] << endl;
		
	}
	file_inp.close();
	_getch();
	long double summ_new_y[5];
	// Massive for added drop with commision
	summ_new_y[0] = summ[0];
	summ_new_y[1] = summ[1] + summ[2];
	summ_new_y[2] = summ[3] + summ[4] + summ[5];
	summ_new_y[3] = summ[6] + summ[7] + summ[8] + summ[9];
	summ_new_y[4] = summ[10] + summ[11]+summ[12] + summ[13] + summ[14];
	
	
	cout << "______________________" << endl;
	cout << " Lets show the Drop status with commision what have been already taken by them" << endl;
	for (i = 0;i < 5;i++)
	{
		summ_new_y[i] = summ_new_y[i] * komm;	
		summ_new_y[i] = summ_new_y[i] * satoshi_doll;
		cout << "drop"<< i <<":  " << summ_new_y[i] << endl;
		summ_new_y[i] = summ_new_y[i] * pow(10, 8);
		cout << "drop" << i << " In BTC:  " << fixed << summ_new_y[i] * pow(10, 8) << endl;
	}
	
	
	file_inp.open("change.txt");
	if (!file_inp.is_open())
	{
		cout << "File cant be oppened" << endl;
		_getch();
	}
	
	//Read 32 bytes from file to country BTC exchange adress
	cout << endl << endl;
	cout << "_________________________________________________" << endl;
	cout << "show 32 bytes for BEL : " << endl;
	for (i = 0;i <16;i++)
	{
		file_inp >>hex>> byte_bel[i];
		cout <<" "<< hex <<byte_bel[i];
		if (i % 8 == 0)
		{
			if (i == 0)
			{
				continue;
			}
			cout << endl;
		}
	}
	cout << endl << endl << "_________________________________________________" << endl;
	cout << "show 32 bytes for UK : " << endl;
	for (i = 0;i < 16;i++)
	{
		file_inp >> byte_uk[i];
		cout << " " << hex <<byte_uk[i];
		if (i % 8 == 0)
		{
			if (i == 0)
			{
				continue;
			}
			cout << endl;
		}
	}
	cout << endl << endl << "_________________________________________________" << endl;
	cout << "show 32 bytes for US : " << endl;
	for (i = 0;i < 16;i++)
	{
		file_inp >>byte_us[i];
		cout << " " << hex << byte_us[i];
		if (i % 8 == 0)
		{
			if (i == 0)
			{
				continue;
			}
			cout << endl;
		}
	}
	cout << endl<<endl << "_________________________________________________" << endl;
	cout << "show 32 bytes for RUS : " << endl;
	for (i = 0;i < 16;i++)
	{
		file_inp >>byte_rus[i];
		cout << " " << hex << byte_rus[i];
		if (i % 8 == 0)
		{
			if (i == 0)
			{
				continue;
			}
			cout << endl;
		}
	}
	file_inp.close();
	//Open file for write information about trx
	ofstream file_out;
	file_out.open("good_result_test.txt");
	if (!file_out.is_open())
	{
		cout << "File cant be oppened" << endl;
	}
	// ________________________________________day+1________________________________
	//Lets write all information for good trx
	for (i = 0;i < 5;i++)
	{
		file_out <<dec<< RangedRandDemo(0, 7000); // ID number
		file_out << ";"; //For using scf file we use comma for separating collums
		file_out << "day+1";
		file_out << ";";
		for (j = 0;j < 16;j++)
		{
			file_out << hex << byte_bel[j] << " ";
		}
		file_out << ";";
		for (k = 0;k < 16;k++)
		{
			file_out << (hex) << RangedRandDemo(0, 256) << " ";
		}
		file_out << ";";
		file_out << summ_new_y[i];
		file_out << endl;
	}
	//Add some mistake information
	for (i = 0;i < 10;i++)
	{
		file_out << RangedRandDemo(0, 7000); // ID number
		file_out << ";"; //For using scf file we use comma for separating collums
		file_out << "day+1";
		file_out << ";";
		flag = RangedRandDemo(1, 6);
		
		// Write randon input bytes, but needed to test out, maybe need to change seed every time the script run
		if (flag == 1)
		{
			for (k = 0;k < 16;k++)
			{
				file_out << hex << RangedRandDemo(0, 256) << " ";
			}
		}
		if (flag == 2)
		{
			for (j = 0;j < 16;j++)
			{
				file_out << hex << byte_bel[j] << " ";
			}
		}
		if (flag == 3)
		{
			for (j = 0;j < 16;j++)
			{
				file_out << hex << byte_us[j] << " ";
			}
		}
		if (flag == 4)
		{
			for (j = 0;j < 16;j++)
			{
				file_out << hex << byte_uk[j] << " ";
			}
		}
		if (flag == 5)
		{
			for (j = 0;j < 16;j++)
			{
				file_out << hex << byte_rus[j] << " ";
			}
		}

		
	
		file_out << ";";
		for (k = 0;k < 16;k++)
		{
			file_out << hex << RangedRandDemo(0, 256) << " ";
		}
		file_out << ";";
		file_out << dec << RangedRandDemo1(10000, 600000000);
		file_out << endl;
	}
	//More Mistake information for day one,day+2
	for (i = 0;i < 15;i++)
	{
		file_out << RangedRandDemo(0, 7000); // ID number
		file_out << ";"; //For using scf file we use comma for separating collums
		file_out << "day";
		file_out << ";";
		flag = RangedRandDemo(1, 5);
		if (flag == 1)
		{
			for (k = 0;k < 16;k++)
			{
				file_out << hex << RangedRandDemo(0, 256) << " ";
			}
		}
		if (flag == 2)
		{
			for (j = 0;j < 16;j++)
			{
				file_out << hex << byte_bel[j] << " ";
			}
		}
		if (flag == 3)
		{
			for (j = 0;j < 16;j++)
			{
				file_out << hex << byte_us[j] << " ";
			}
		}
		if (flag == 4)
		{
			for (j = 0;j < 16;j++)
			{
				file_out << hex << byte_uk[j] << " ";
			}
		}
		if (flag == 5)
		{
			for (j = 0;j < 16;j++)
			{
				file_out << hex << byte_rus[j] << " ";
			}
		}
		file_out << ";";
		for (k = 0;k <16;k++)
		{
			file_out <<hex<< RangedRandDemo(0, 256);file_out << " ";
		}
		file_out << ";";
		file_out << dec << RangedRandDemo1(10000, 600000000);
		file_out << endl;
	}
	//For day+2
	for (i = 0;i < 15;i++)
	{
		file_out << RangedRandDemo(0, 7000); // ID number
		file_out << ";"; //For using scf file we use comma for separating collums
		file_out << "day+2";
		file_out << ";";
		flag = RangedRandDemo(1, 5);
		if (flag == 1)
		{
			for (k = 0;k < 16;k++)
			{
				file_out << hex << RangedRandDemo(0, 256) << " ";
			}
		}
		if (flag == 2)
		{
			for (j = 0;j < 16;j++)
			{
				file_out << hex << byte_bel[j] << " ";
			}
		}
		if (flag == 3)
		{
			for (j = 0;j < 16;j++)
			{
				file_out << hex << byte_us[j] << " ";
			}
		}
		if (flag == 4)
		{
			for (j = 0;j < 16;j++)
			{
				file_out << hex << byte_uk[j] << " ";
			}
		}
		if (flag == 5)
		{
			for (j = 0;j < 16;j++)
			{
				file_out << hex << byte_rus[j] << " ";
			}
		}
		file_out << ";";
		for (k = 0;k < 16;k++)
		{
			file_out <<hex << RangedRandDemo(0, 256);
			file_out << " ";
		}
		file_out << ";";
		file_out << dec << RangedRandDemo1(10000, 600000000);
		file_out << endl;
	}
	
	
	file_inp.open("good_result_test.txt");
	if (!file_inp.is_open())
	{
		cout << "File cant be oppened" << endl;
	}
	_getch();
	// Random file sort;
	vector <string> vec;
    string str;
	
    char mass[9000];
	int count = 0;
	while (!file_inp.eof())
	{
		file_inp.getline(mass, 9000, newline);
		str = mass;
		vec.push_back(str);
		count++;
	}
	file_inp.close();
	for (i = 1; i < count-1;i++)
	{
		vec[i].swap(vec[RangedRandDemo(0, count)]);
	}
	file_out.close();
	file_out.open("ended.txt");
	if (!file_out.is_open())
	{
		cout << "File cant be oppened" << endl;
	}
	for (auto& str : vec)
	{
		file_out << endl;
		for (auto& ch : str)
			file_out << ch;
	}
		
	
		
			
	
	
	
	//file.close();
	


	


}
float RangedRandDemo1(int range_min, int range_max)
{
	float u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
	return u;

}

int RangedRandDemo(int range_min, int range_max)
{
	int u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
	return u;
	
}


