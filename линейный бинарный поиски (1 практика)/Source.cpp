#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>
#include <algorithm>
using namespace std;

int Search_Binary(vector <int> v, int key)
{
	int midd,left=0,right=v.size();
	while (1)
	{
		midd = (left + right) / 2;
		if (midd >= v.size())
			return -1;
		if (key < v[midd])       // если искомое меньше значения в ячейке
			right = midd - 1;      // смещаем правую границу поиска
		else if (key > v[midd])  // если искомое больше значения в ячейке
			left = midd + 1;    // смещаем левую границу поиска
		else                       // иначе (значения равны)
			return midd;           // функция возвращает индекс ячейки

		if (left > right)          // если границы сомкнулись 
			return -1;
	}
}

int linSearch(vector <int> v, int requiredKey)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == requiredKey)
			return i;
	}
	return -1;
}


int main()
{
	setlocale(LC_ALL, "ru");
	//srand(time(0));
	vector <int> v;
	int size,nomer,key,check;
	cin >> size;
	cin >> key;
	for (int i=size; i !=0; i--)
		v.push_back(-i);

	/*for (auto i : v)
		cout << i << "\t";*/
	cout << endl;
	cout << "работает линейный поиск:\n";
	auto t1 = chrono::high_resolution_clock::now();
	check = linSearch(v, key);
	auto t2 = chrono::high_resolution_clock::now();
	double time1 = chrono::duration<double>(t2 - t1).count();
	if (check != -1)
		cout << "номер найденного элемента :\t" << check << endl;
	else
		cout << "числа : " << key << " нету в массиве\n";
	cout << endl << "время затраченное на линейный поиск :\t" << time1 << endl;
	cout << "=========================================================================================\n";
	cout << "работает бинарный поиск:\n";
	sort(v.begin(), v.end());
	t1 = chrono::high_resolution_clock::now();
	check = Search_Binary(v, key);
	t2 = chrono::high_resolution_clock::now();
	double time2 = chrono::duration<double>(t2 - t1).count();
	if(check!=-1)
		cout << endl<<"номер найденного элемента:\t" << check<<endl;
	else 
		cout << "числа : " << key << " нету в массиве\n";
	cout << "время затраченное на бинарный поиск :\t" << time2 << endl;
	system("pause");
}