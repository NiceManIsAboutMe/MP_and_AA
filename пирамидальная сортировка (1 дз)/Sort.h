#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <algorithm>
using namespace std;

struct peoples {
	string name, surname;
	int DOB;
};


// ������� "�����������" ����� ���� - ������������ ���� ��� DOT
vector <peoples> siftDown_DOT(vector <peoples> numbers, int root, int bottom)
{
	int maxChild; // ������ ������������� �������
	int done = 0; // ���� ����, ��� ���� ������������
	// ���� �� ����� �� ���������� ����
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)    // ���� �� � ��������� ����,
			maxChild = root * 2;    // ���������� ����� �������
		  // ����� ���������� ������� ������� �� ����
		else if (numbers[root * 2].DOB > numbers[root * 2 + 1].DOB)
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// ���� ������� ������� ������ ������������� �������
		if (numbers[root].DOB < numbers[maxChild].DOB)
		{
			peoples a = numbers[root]; // ������ �� �������
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = a;
		}
		else // �����
			done = 1; // �������� ������������
	}
	return numbers;
}
// ������� ���������� �� ���� ��� DOB
vector <peoples> heapSort_DOT(vector <peoples> numbers, int array_size)
{
	// ��������� ������ ��� ��������
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		numbers=siftDown_DOT(numbers, i, array_size - 1);
	// ���������� ����� �������� ��������� ��������
	for (int i = array_size - 1; i >= 1; i--)
	{
		peoples a = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = a;
		numbers=siftDown_DOT(numbers, 0, i - 1);
	}
	return numbers;
}


//c��������� �������
void siftDown_SURNAME(peoples* numbers, int root, int bottom)
{
	int maxChild; // ������ ������������� �������
	int done = 0; // ���� ����, ��� ���� ������������
	// ���� �� ����� �� ���������� ����
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)    // ���� �� � ��������� ����,
			maxChild = root * 2;    // ���������� ����� �������
		  // ����� ���������� ������� ������� �� ����
		else if (numbers[root * 2].surname > numbers[root * 2 + 1].surname)
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// ���� ������� ������� ������ ������������� �������
		if (numbers[root].surname < numbers[maxChild].surname)
		{
			int a = numbers[root].DOB; // ������ �� �������
			numbers[root].DOB = numbers[maxChild].DOB;
			numbers[maxChild].DOB = a;
			string b = numbers[root].name;
			numbers[root].name = numbers[maxChild].name;
			numbers[maxChild].name = b;
			string temp = numbers[root].surname;
			numbers[root].surname = numbers[maxChild].surname;
			numbers[maxChild].surname = temp;
			root = maxChild;
		}
		else // �����
			done = 1; // �������� ������������
	}
}
void heapSort_SURNAME(peoples* numbers, int array_size)
{
	// ��������� ������ ��� ��������
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		siftDown_SURNAME(numbers, i, array_size - 1);
	// ���������� ����� �������� ��������� ��������
	for (int i = array_size - 1; i >= 1; i--)
	{
		int a = numbers[0].DOB;
		numbers[0].DOB = numbers[i].DOB;
		numbers[i].DOB = a;
		string b = numbers[0].name;
		numbers[0].name = numbers[i].name;
		numbers[i].name = b;
		string temp = numbers[0].surname;
		numbers[0].surname = numbers[i].surname;
		numbers[i].surname = temp;
		siftDown_SURNAME(numbers, 0, i - 1);
	}
}


// ���������� �� �����
void siftDown_NAME(peoples* numbers, int root, int bottom)
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
			string b = numbers[root].surname;
			numbers[root].surname = numbers[maxChild].surname;
			numbers[maxChild].surname = b;
			int a = numbers[root].DOB; // ������ �� �������
			numbers[root].DOB = numbers[maxChild].DOB;
			numbers[maxChild].DOB = a;
			string temp = numbers[root].name; // ������ �� �������
			numbers[root].name = numbers[maxChild].name;
			numbers[maxChild].name = temp;
			root = maxChild;
		}
		else // �����
			done = 1; // �������� ������������
	}
}
void heapSort_NAME(peoples* numbers, int array_size)
{
	// ��������� ������ ��� ��������
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		siftDown_NAME(numbers, i, array_size - 1);
	// ���������� ����� �������� ��������� ��������
	for (int i = array_size - 1; i >= 1; i--)
	{
		int a = numbers[0].DOB;
		numbers[0].DOB = numbers[i].DOB;
		numbers[i].DOB = a;
		string b = numbers[0].surname;
		numbers[0].surname = numbers[i].surname;
		numbers[i].surname = b;
		string temp = numbers[0].name;
		numbers[0].name = numbers[i].name;
		numbers[i].name = temp;
		siftDown_NAME(numbers, 0, i - 1);
	}
}

int get_length(string s)
{
	int length = 0;
	string str;
	ifstream fin;
	fin.open(s);
	while (!fin.eof())
	{
		getline(fin, str);
		length++;
	}
	fin.close();
	return length;
};
//������ �� �������
vector <peoples> fread(vector <peoples> arr)
{
	int i = 0, m;
	string str;
	ifstream fin;
	fin.open("Text.txt");
	while (!fin.eof())
	{
		fin >> str;
		arr[i].name = str;
		fin >> str;
		arr[i].surname = str;
		fin >> m;
		arr[i].DOB = m;
		//cout << arr[i].name << endl << arr[i].surname << endl << arr[i].DOB << endl;
		i++;
	}
	fin.close();
	return arr;
}

// ������ ���������������� � ����� ��������� ����
void frecord(vector <peoples> arr, int length, string s)
{
	ofstream fout;
	fout.open(s);
	for (int i = 0; i < length; i++)
	{
		fout << arr[i].name << " " << arr[i].surname << " " << arr[i].DOB << endl;
	}
	fout.close();
}

