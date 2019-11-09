#pragma once
// ���������� �� �����
void siftDown_only_NAME(vector <peoples> &numbers, int root, int bottom)
{
	int maxChild; // ������ ������������� �������
	int done = 0; // ���� ����, ��� ���� ������������
	// ���� �� ����� �� ���������� ����
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)    // ���� �� � ��������� ����,
			maxChild = root * 2;    // ���������� ����� �������
		  // ����� ���������� ������� ������� �� ����
		else if (numbers[root * 2].name > numbers[root * 2 + 1].name)
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// ���� ������� ������� ������ ������������� �������
		if (numbers[root].name < numbers[maxChild].name)
		{
			string temp = numbers[root].name; // ������ �� �������
			numbers[root].name = numbers[maxChild].name;
			numbers[maxChild].name = temp;
			root = maxChild;
		}
		else // �����
			done = 1; // �������� ������������
	}
}
void heapSort_only_NAME(vector <peoples> &numbers, int array_size)
{
	// ��������� ������ ��� ��������
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		siftDown_only_NAME(numbers, i, array_size - 1);
	// ���������� ����� �������� ��������� ��������
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

