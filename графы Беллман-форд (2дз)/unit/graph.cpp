#include "graph.h"

void Graph::add_vertex(int vertex) {
   if (!has_vertex(vertex)) {
       vertices[vertex] = std::map<int,int>();
    }
}

void Graph::add_edge(int start_vertex, int end_vertex,int weight) {
	if (weight)
	{
		add_vertex(start_vertex);
		add_vertex(end_vertex);
		vertices[start_vertex][end_vertex] = weight;
	}
}

int Graph::get_weight(int start, int end)
{
	if (start == end || !has_vertex(start) || !has_vertex(end))
		return 0;
	return vertices[start][end];
}

std::vector<int> Graph::get_vertices() const {
    std::vector<int> result;
    for (const auto &p: vertices) {
        result.push_back(p.first);
    }
    return result;
}

std::vector<int> Graph::get_adjacent_vertices(int src_vertex)  {
    if (!has_vertex(src_vertex)) 
	{
        return std::vector<int>();
    }
	vector<int> v;
	for (auto i = vertices[src_vertex].begin(); i != vertices[src_vertex].end(); i++)
		v.push_back(i->first);

    return v;
}

bool Graph::has_vertex(int vertex) const {
    return (vertices.find(vertex) != vertices.end());
}


bool Graph::has_arc(int start_vertex, int end_vertex) const {
    if (!has_vertex(start_vertex) || !has_vertex(end_vertex)) {
        return false;
    }
    const auto it = vertices.find(start_vertex);
    return (it->second.find(end_vertex) != it->second.end());
}
//алгоритм беллмана-форда
map <int,int> Graph::Bell_Ford(int start)
{
	if (!has_vertex(start) || get_adjacent_vertices(start) == vector<int>())
	{
		return map <int, int>();
	}
	map <int,int > v;
	for (auto a : vertices)
		v[a.first] = inf; // присваиваем каждой вершине значение условной бесконечности
	v[start] = 0; // заданной вершине присваиваем значение 0
	for (auto i : vertices) // пока не обойдем весь vertices
	{
		for (auto j : vertices[i.first]) // проходим по каждой смежной вершине
		{
			if (v[i.first] < inf)
			if (v[i.first] + vertices[i.first][j.first] < v[j.first]) // если путь короче то присваиваем его значение
				v[j.first] = v[i.first] + vertices[i.first][j.first];
		}
	}
	map <int, int> m;
	for (auto it : v)
		if (it.second < inf)
			m[it.first] = it.second;
	return m;
}


//возвращает вектор с путем до заданной вершины
map <int, int> Graph::Bell_Ford(int start,int end,vector <int> &a)
{
	if (start == end)
	{
		a.push_back(start);
		a.push_back(end);
	}
	if (!has_vertex(start) || !has_vertex(end) || get_adjacent_vertices(start) == vector<int>() || !path_exists(start,end))
	{
		return map <int, int>();
	}
	vector <int> p(vertices.rbegin()->first, -1); // массив для восстановления путей
	map <int, int > v;
	for (auto a : vertices)
		v[a.first] = inf; // присваиваем каждой вершине значение условной бесконечности
	v[start] = 0; // заданной вершине присваиваем значение 0
	for (auto i : vertices) // пока не обойдем весь vertices
	{
		for (auto j : vertices[i.first]) // проходим по каждой смежной вершине
		{
			if(v[i.first]<inf)
			if (v[i.first] + vertices[i.first][j.first] < v[j.first]) // если путь короче то присваиваем его значение
			{
				v[j.first] = v[i.first] + vertices[i.first][j.first];
				p[j.first] = i.first; // массив для путей
			}
		}
	}
	if (v[end] != inf) // восстановление путей
	{
		for (int cur = end; cur != -1; cur = p[cur])
			a.push_back(cur);
		reverse(a.begin(), a.end());
	}
	map <int, int> m;
	for (auto it : v)
		if (it.second < inf)
			m[it.first] = it.second;
	return m;
}
/*
vector<int> Graph::Bell_Ford(int start)
{
	if (!has_vertex(start) || get_adjacent_vertices(start) == vector<int>())
	{
		return vector<int>();
	}
	vector <int > v(max_element(vertices.begin(), vertices.end())->first,inf);
	v[start] = 0;
	for (auto i:vertices)
	{
		for (auto j:vertices[i.first])
		{
			if (v[i.first] + vertices[i.first][j.first] < v[j.first])
				v[j.first] = v[i.first] + vertices[i.first][j.first];
		}
	}
	return v;
}
*/

bool Graph::path_exists(int start, int end)
{
	if (vertices.size() == 0|| !has_vertex(start) || !has_vertex(end)) // åñëè ãðàô ïóñò
		return false;
	else if (start == end)
		return true;
	else if (!get_adjacent_vertices(start).size()) // åñëè èç çàäàííîé âåðøèíû íå ñóùåñòâóåò äóã
		return false;
	else
	{
		DFS(start);
		for (int i = 0; i < used.size(); i++)
			if (used[i] == end)
			{
				used.resize(0);
				return true;
			}
		used.resize(0);
		return false;

	}
}

bool Graph::DFS(int start)
{
	for (int j = 0; j < used.size(); j++)
	{
		if (used[j] == start)
			return 0;
	}
	used.push_back(start);
	for (int i = 0; i < get_adjacent_vertices(start).size(); i++)// ïîêà ìåíüøå ñòåïåíè âåðøèíû
		DFS(get_adjacent_vertices(start)[i]); // ôóíêöèÿ âûçûâàåò ñàìà
}

