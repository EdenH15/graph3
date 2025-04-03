//
// Created by eden on 4/1/25.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Algorithms.h"
#include "Graph.h"
#include "structures.h"
#include <stdexcept>

using namespace graph;
using namespace std;

TEST_CASE("Test Bfs") {
    Graph g1(4);
    Graph emptyGraph(0);
    Graph g2(4);

    g1.addEdge(0,1,4);
    g1.addEdge(0,2,3);
    g1.addEdge(1,3,2);
    g1.addEdge(1,2,7);

    // Test BFS on a non-empty graph
    Graph bfsRes1 = Algorithms::bfs(g1, 0);

    // Assert that vertex 0 has neighbors 1 and 2
    CHECK(bfsRes1.getNeighbors(0) != nullptr);
    CHECK(bfsRes1.getNeighbors(0)->vertex == 1);
    CHECK(bfsRes1.getNeighbors(0)->next->vertex == 2);

    // Assert that vertex 1 has neighbors 3
    CHECK(bfsRes1.getNeighbors(1) != nullptr);
    CHECK(bfsRes1.getNeighbors(1)->vertex == 3);

    // Assert that vertex 2 has no neighbors
    CHECK(bfsRes1.getNeighbors(2) == nullptr);

    // Test BFS on an empty graph (should throw exception)
    CHECK_THROWS_AS(Algorithms::bfs(emptyGraph, 0), std::invalid_argument);

    // Test BFS with an invalid source vertex index
    CHECK_THROWS_AS(Algorithms::bfs(g1, -1), std::out_of_range);
    CHECK_THROWS_AS(Algorithms::bfs(g1, 100), std::out_of_range);
}

TEST_CASE("Test Dfs") {
    Graph g1(4);
    Graph emptyGraph(0);
    Graph g2(4);

    g1.addEdge(0,1,4);
    g1.addEdge(1,2,3);
    g1.addEdge(2,3,2);
    g1.addEdge(3,0,7);

    Graph dfsRes1 = Algorithms::dfs(g1, 0);
    // Vertex 0 should be connected to vertex 1
    CHECK(dfsRes1.getNeighbors(0) != nullptr);
    CHECK(dfsRes1.getNeighbors(0)->vertex == 3);

    // Vertex 1 should be connected to vertex 2
    CHECK(dfsRes1.getNeighbors(3) != nullptr);
    CHECK(dfsRes1.getNeighbors(3)->vertex == 2);

    // Vertex 2 should be connected to vertex 3
    CHECK(dfsRes1.getNeighbors(2) != nullptr);
    CHECK(dfsRes1.getNeighbors(2)->vertex == 1);

    // Vertex 3 should have no direct connection to vertex 0 in the DFS tree
    CHECK(dfsRes1.getNeighbors(1) == nullptr);

    CHECK_THROWS_AS(Algorithms::dfs(emptyGraph, 0), std::invalid_argument);
    CHECK_THROWS_AS(Algorithms::bfs(g1, -1), std::out_of_range);
    CHECK_THROWS_AS(Algorithms::bfs(g1, 100), std::out_of_range);

}
