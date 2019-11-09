#pragma once
// сортировка по имени
void siftDown_only_NAME(vector <peoples> &numbers, int root, int bottom)
{
	int maxChild; // индекс максимального потомка
	int done = 0; // флаг того, что куча сформирована
	// Пока не дошли до последнего ряда
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)    // если мы в последнем ряду,
			maxChild = root * 2;    // запоминаем левый потомок
		  // иначе запоминаем больший потомок из двух
		else if (numbers[root * 2].name > numbers[root * 2 + 1].name)
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// если элемент вершины меньше максимального потомка
		if (numbers[root].name < numbers[maxChild].name)
		{
			string temp = numbers[root].name; // меняем их местами
			numbers[root].name = numbers[maxChild].name;
			numbers[maxChild].name = temp;
			root = maxChild;
		}
		else // иначе
			done = 1; // пирамида сформирована
	}
}
void heapSort_only_NAME(vector <peoples> &numbers, int array_size)
{
	// Формируем нижний ряд пирамиды
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		siftDown_only_NAME(numbers, i, array_size - 1);
	// Просеиваем через пирамиду остальные элементы
	for (int i = array_size - 1; i >= 1; i--)
	{
		string temp = numbers[0].name;
		numbers[0].name = numbers[i].name;
		numbers[i].name = temp;
		siftDown_only_NAME(numbers, 0, i - 1);
	}
}


void fread_name(vector <peoples> &arr,string s)
{
	int i = 0, m;
	string str;
	ifstream fin;
	fin.open(s);
	while (!fin.eof())
	{
		fin >> str;
		arr[i].name = str;
		i++;
	}
	fin.close();
}
void frecord_names(vector <peoples> arr, int length, string s)
{
	ofstream fout;
	fout.open(s);
	for (int i = 0; i < length; i++)
	{
		fout << arr[i].name << endl;
	}
	fout.close();
}

