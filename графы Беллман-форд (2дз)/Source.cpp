#include <iostream>
#include "graph.h"

int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	Graph g;
	g.add_arc(1,2,1);
	g.add_arc(2,3, 10);
	g.add_arc(1, 3, 2);
	g.add_arc(3, 4, 5);
	g.add_arc(1, 4, 3);
	g.add_arc(2, 4, 1);

	g.add_vertex(10);
	/*cout << g.get_weight(1,2) << endl;
	cout << g.get_weight(2,1) << endl;
	cout << g.get_weight(1, 5) << endl;
	vector<int> v;
	v=g.get_adjacent_vertices(1);
	for (auto it : v)
		cout << it << endl;
	cout << endl;*/
	cout << "введите вершину из которой будем искать кратчайший путь\n";
	cin >> n;
	map <int,int> m=g.Bell_Ford(n);
	if (m != map<int, int>())
	{
		cout << "кратчайший путь из " << n << endl;
		for (auto it : m)
			cout << "в вершину " << it.first << " = " << it.second << "\n";
		cout << endl;
	}
	else
	{
		cout << "\nиз заданной вершины не существует пути до других или заданной вершины не существует\n";
	}
	system("pause");

}