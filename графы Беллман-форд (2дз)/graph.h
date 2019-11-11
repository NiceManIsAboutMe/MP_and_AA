#pragma once

#include <map>
#include <set>
#include <vector>
#include <algorithm>
#define inf 2147483600
using namespace std;
/**
 * Oriented graph.
**/
class Graph {
public:
    /// Adds single vertex to the graph.
    void add_vertex(int vertex);
	
    /// Adds vertices (if necessary) and an arc between them to the graph.
    void add_arc(int start_vertex, int end_vertex,int weight);
	
	int get_weight(int start, int end);
	
    /// Returns all vertices of the graph.
    std::vector<int> get_vertices() const;
	
    /// Returns all vertices, adjacent by arcs to the specified vertex.
    std::vector<int> get_adjacent_vertices(int src_vertex);
	
    /// Returns true if the vertex exists in the graph, false otherwise.
    bool has_vertex(int vertex) const;
	
    /// Returns true if vertices exist and have an arc between them, false otherwise.
    bool has_arc(int start_vertex, int end_vertex) const;


	map <int, int> Bell_Ford(int start);
	//vector <int> Bell_Ford(int start);
	map <int, int> Bell_Ford(int start, int end, vector <int>& a);
	bool path_exists(int start, int end);

private:
	bool DFS(int start);
	vector <int> used;
    std::map<int, map<int,int>> vertices; //внутри map хранится пара дуг и весов
	//map<int, set<int> > vertices;
};
