#define CATCH_CONFIG_MAIN
#include "graph_algs_2.h"
#include "catch.hpp"

namespace {
    template <class T>
    std::set<std::set<int>> to_set(const T &array) {
        std::set<std::set<int>> result;
        for (const auto &a: array) {
            result.insert(std::set<int>(std::begin(a), std::end(a)));
        }
        return result;
    }

    template <class T>
    bool sets_are_equal(const T &a1, const T &a2) {
        return (to_set(a1) == to_set(a2));
    }

    template <class T>
    bool equal(const T &a, const T &b) {
        return (a == b);
    }

    template <class T>
    bool one_from(const T &in, const typename std::vector<T> &variants) {
        for (const auto &v: variants) {
            if (in == v) return true;
        }
        return false;
    }
}


TEST_CASE( "[SP] Path in null graph doesn't exist", "[shortest_path]" ) {
    Graph g;    
    CHECK( shortest_path(g, 0, 1).empty() );
}

TEST_CASE( "[SP] Path in singleton graph exists", "[shortest_path]" ) {
    Graph g;    
    g.add_vertex(0);
    CHECK( equal(shortest_path(g, 0, 0), {0, 0}) );
}

TEST_CASE( "[SP] Path for two vertices without edge", "[shortest_path]" ) {
    Graph g;    
    g.add_vertex(0);
    g.add_vertex(1);
    CHECK( shortest_path(g, 0, 1).empty() );
}

TEST_CASE( "[SP] Path for two vertices with edge", "[shortest_path]" ) {
    Graph g;    
    g.add_edge(0, 1,40);
    CHECK( equal(shortest_path(g, 0, 1), {0, 1}) );
}

TEST_CASE( "[SP] Path for several vertices", "[shortest_path]" ) {
    Graph g;    
    g.add_edge(0, 1,20);
    g.add_edge(1, 2,30);
    g.add_edge(2, 3,40);
    g.add_edge(0, 3,15);
    CHECK( equal(shortest_path(g, 0, 3), {0, 3}) );
    CHECK( one_from(shortest_path(g, 1, 3), {{1, 2, 3}, {1, 0, 3}}) );
}

TEST_CASE( "[SP] Path in disconnected graph", "[shortest_path]" ) {
    Graph g;    
    g.add_edge(0, 1,20);
    g.add_edge(1, 2,30);
    g.add_edge(2, 3,40);
    g.add_edge(0, 3,10);
    g.add_edge(4, 5,50);
    g.add_edge(5, 6,60);
    g.add_vertex(7);
    CHECK( equal(shortest_path(g, 0, 3), {0, 3}) );
    CHECK( one_from(shortest_path(g, 1, 3), {{1, 2, 3}, {1, 0, 3}}) );
    CHECK( shortest_path(g, 0, 5).empty() );
    CHECK( shortest_path(g, 1, 7).empty() );
    CHECK( shortest_path(g, 5, 7).empty() );
}


TEST_CASE( "[SP] Path with non-existing vertices", "[shortest_path]" ) {
    Graph g;    
    g.add_edge(0, 1,20);
    g.add_edge(1, 2,20);
    g.add_edge(2, 3,20);
    g.add_edge(2, 4,20);
    g.add_edge(3, 5,30);
    CHECK( shortest_path(g, 0, 7).empty() );
    CHECK( shortest_path(g, 6, 2).empty() );
    CHECK( shortest_path(g, 6, 8).empty() );
}

