#include"Hash.h"
#include<time.h>
using namespace std;




//�� ������ �������, ��� ��������, ���-������� � ������� � ����������;
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(static_cast<unsigned int>(time(NULL)));
	int mas[100];
	HashTable<int,my_hash<int>> HT; //2000 ���������

	// ���������� ������� 100  ���������
	for (int i = 0; i <100 ; i++)
	{
		mas[i] = rand() - RAND_MAX/2 ;
	}

	//������� 1000 ��������� ���������
	for (int i = 0; i <1000;i++)
	{
		HT.add(rand()- RAND_MAX/2);
	}
	
	time_t start = clock();
	// ������� 100 �������� 50 ����� � 100 ��������
	for (int j = 0; j <10000;j++)
	{
		//�������
		for (int i = 0;i < 100;i++)
		{
			HT.add(mas[i]);

		}
		//����� 50 ���������
		for (int i = 0; i < 50;i++)
		{
			HT.find(mas[rand() % 100]);
		}
		//�������� 100 ���������
		for (int i = 0;i < 100;i++)
		{
			HT.erase(mas[i]);
		}
	}
	cout << "My Hash Table Time " << double(clock() - start) / CLOCKS_PER_SEC << endl;



	unordered_set<int,my_hash<int>> US(2000);
	//������� ��������� 1000
	for (int i = 0; i < 1000;i++)
	{
		US.insert(rand()- RAND_MAX/2);
	}

	start = clock();
	// ������� 100 �������� 50 ����� � 100 ��������
	for (int j = 0; j < 10000;j++)
	{
		//������� 100 ���������
		for (int i = 0;i < 100;i++)
		{
			US.insert(mas[i]);
		}

		//����� 50 ���������
		for (int i = 0; i < 150;i++)
		{
			US.find(mas[rand() % 100]);
		}

		//�������� 100 ���������
		for (int i = 0;i < 100;i++)
		{
			US.erase(mas[i]);
		}
	}
	cout << "Unordered Set  time: " << double(clock() - start) / CLOCKS_PER_SEC << endl;
#ifdef _WIN32
    system("pause");
#endif
}

//My Hash Table Time 0.421
//Unordered Set  time : 0.422
//��� ����������� ������� ����� ������� . . .