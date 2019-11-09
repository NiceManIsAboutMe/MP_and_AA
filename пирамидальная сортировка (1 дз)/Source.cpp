#include "Sort.h" // ���������� � ��������� ����������
#include "Sort_only_names.h" // ������ ��� ����
#include <chrono>


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	int length = get_length("Text.txt");
	vector <peoples> v(length);
	v=fread(v);
	v = heapSort_DOT(v, length);
	frecord(v,length, "Sort_DOT.txt");

	/////////////////////////////////////////////////////////////////
	length = get_length("Names.txt");
	vector <peoples> v2(length);
	vector <string> v3(length);
	fread_name(v2, "Names.txt");

	auto t1 = chrono::high_resolution_clock::now();
	heapSort_only_NAME(v2, length);
	auto t2 = chrono::high_resolution_clock::now();
	double time = chrono::duration<double>(t2 - t1).count();

	for (int i = 0; i < length; i++)
	{
		v3[i] = v2[i].name;
	}

	auto t3 = chrono::high_resolution_clock::now();
	sort(v3.begin(), v3.end());
	auto t4 = chrono::high_resolution_clock::now();
	double time2 = chrono::duration<double>(t4 - t3).count();
	cout << "����� ���������� ���������� ������� �������� :" << length << " = " << time<<endl;
	cout << "����� ������� sort (STL) ���������� ���� �� ������� = " << time2 << endl;
	frecord_names(v2, length,"Sort_only_names.txt");
	system("pause");
}





/*
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	int length=get_length("Names.txt");
	peoples* arr = new peoples[length];
	fread_name(arr,"Names.txt");

	/*heapSort_DOT(arr, length ); // ����� ������� ���������� �� ����
	string s = "Sort_DOT.txt";
	frecord(arr, length, s);// �������� Sort_DOT.txt
	heapSort_NAME(arr, length);
	s = "Sort_Name.txt";
	frecord(arr, length,s);
	heapSort_SURNAME(arr, length);
	s = "Sort_Surname.txt";
	int t1 = clock();
	frecord(arr,length,s);
	int t2 = clock();
	cout <<"���������� �� �������: "<< float(t2 - t1) / CLOCKS_PER_SEC << endl;
	int length=get_length("Names.txt");
	peoples* arr = new peoples[length];
	fread_name(arr,"Names.txt");
	// ������ �����
	int t1=clock();
	heapSort_only_NAME(arr, length);
	int t2 = clock();
	frecord_names(arr,length, "Sort_only_names.txt");
	
	vector <string> v(length);
	for (int i = 0; i < length; i++)
	{
		v[i] = arr[i].name;
	}
	int t3 = clock();
	sort(v.begin(), v.end());
	int t4 = clock();
	cout << "����������� ��������� :" << length << endl;
	cout << "���������� �����: " << float(t2 - t1) / CLOCKS_PER_SEC << endl;
	cout <<"����������� STL ���������� : "<< float(t4 - t3) / CLOCKS_PER_SEC << endl;
	cout << "������� �� ������� ����� ������������: " << abs(float(t2 - t1) / CLOCKS_PER_SEC - float(t4 - t3) / CLOCKS_PER_SEC) << endl;
	cout << "��������� ������������� ���������� � ����������� STL :" << (float(t2 - t1) / CLOCKS_PER_SEC) / (float(t4 - t3) / CLOCKS_PER_SEC) << endl;
	system("pause");
	delete [] arr;
	return 0;
}
*/