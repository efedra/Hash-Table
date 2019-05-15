#include"Hash.h"
#include<time.h>
using namespace std;




//На основе цепочек, без повторов, хеш-функция – вариант с умножением;
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(static_cast<unsigned int>(time(NULL)));
	int mas[100];
	HashTable<int,my_hash<int>> HT; //2000 элементов

	// заполнение матрицы 100  элементов
	for (int i = 0; i <100 ; i++)
	{
		mas[i] = rand() - RAND_MAX/2 ;
	}

	//вставка 1000 случайных элементов
	for (int i = 0; i <1000;i++)
	{
		HT.add(rand()- RAND_MAX/2);
	}
	
	time_t start = clock();
	// вставка 100 элемнтов 50 поиск и 100 удаление
	for (int j = 0; j <10000;j++)
	{
		//вставка
		for (int i = 0;i < 100;i++)
		{
			HT.add(mas[i]);

		}
		//поиск 50 элементов
		for (int i = 0; i < 50;i++)
		{
			HT.find(mas[rand() % 100]);
		}
		//удаление 100 элементов
		for (int i = 0;i < 100;i++)
		{
			HT.erase(mas[i]);
		}
	}
	cout << "My Hash Table Time " << double(clock() - start) / CLOCKS_PER_SEC << endl;



	unordered_set<int,my_hash<int>> US(2000);
	//вставка элементов 1000
	for (int i = 0; i < 1000;i++)
	{
		US.insert(rand()- RAND_MAX/2);
	}

	start = clock();
	// вставка 100 элемнтов 50 поиск и 100 удаление
	for (int j = 0; j < 10000;j++)
	{
		//вставка 100 элементов
		for (int i = 0;i < 100;i++)
		{
			US.insert(mas[i]);
		}

		//поиск 50 элементов
		for (int i = 0; i < 150;i++)
		{
			US.find(mas[rand() % 100]);
		}

		//удаление 100 элементов
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
//Для продолжения нажмите любую клавишу . . .