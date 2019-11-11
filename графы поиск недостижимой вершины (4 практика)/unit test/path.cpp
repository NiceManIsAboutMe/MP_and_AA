#include "path.h"

bool path_exists(Graph &graph, int start_vertex, int end_vertex) {
			 /// If start and end vertices are the same, path exists.
    return graph.path_exists(start_vertex, end_vertex);
}
