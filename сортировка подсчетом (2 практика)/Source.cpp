#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <time.h>
using namespace std;
//сортировка подсчетом
void podschet(vector <int> &v,int max,int min) // сортируемый массив макс мин числа из него
{
	vector <int> temp(max+1-min,0); // вспомогательный вектор в нем хранится счетчик одинаковых элементов, заполняем 0 изначально
	int k=0;
	for (int i = 0; i < v.size(); i++)
		temp[v[i]-min]++; // считаем сколько раз встречался один и тот же элемент
	for (int i = 0; i <= max-min; i++)
	{
		for (int j = 0; j < temp[i]; j++) // колличество одинаковых элементов
		{
			v[k++] = i+min; // заполняем массив по порядку если встречаем элемент который встречается хотя бы 1 раз
		}
	}
}




int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");
	vector <int> v,v1;
	int size;
	cin >> size;
	for (int i = 0; i < size; i++)
		v.push_back(-rand()%1000);
	v1 = v;
	/*for (auto i : v)
		cout << i << "\t";*/
	int min = *min_element(v.begin(), v.end());
	int max = *max_element(v.begin(), v.end());
	auto t1 = chrono::high_resolution_clock::now();
	podschet(v,max,min);                               // сортировка подсчетом
	auto t2 = chrono::high_resolution_clock::now();
	double time = chrono::duration<double>(t2 - t1).count();
	cout << "время затраченное на сортировку подсчетом :\t" << time << endl;
	cout << endl << endl;
/*	for (auto i : v)
		cout << i << "\t";*/
	cout << endl;
	 t1 = chrono::high_resolution_clock::now();
	sort(v1.begin(), v1.end());                       // быстрая сортировка
	 t2 = chrono::high_resolution_clock::now();
	double time2 = chrono::duration<double>(t2 - t1).count();
	cout << "быстрая сортировка :\t" << time2 << endl;
	cout << endl << "разница между подсчетом и быстрой :\t" << time - time2 << endl;
	system("pause");
}