#include "graph_algs_2.h"


std::vector<int> shortest_path( Graph &graph, int start_vertex, int end_vertex) {
    /// Should return shortest path from start to end vertex as array of vertices, 
    /// with start vertex as the first element and end vertex as the last element.
    /// Should return empty array if there is no path.
	vector<int> result;
	graph.Bell_Ford(start_vertex, end_vertex, result);
    return result;
}
