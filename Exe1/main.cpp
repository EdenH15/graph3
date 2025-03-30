
#include <iostream>
#include "Graph.h"
#include "Algorithms.h"
#include "structures.h"
using namespace graph;

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    Graph g(6);
    g.addEdge(0,1,4);
    g.addEdge(0,2,3);
    g.addEdge(1,3,2);
    g.addEdge(1,4,7);
    g.addEdge(2,4,1);
    g.addEdge(3,5,5);
    g.addEdge(4,5,2);
    printf("original graph:\n");
    // g.addEdge(0, 1, 5);
    // g.addEdge(1, 2, 20);
    // g.addEdge(2, 0, 1);
    // Graph g2(5);
    // g2.addEdge(0, 3, 2);
    // g2.addEdge(1, 4, 1);
    // g2.addEdge(4, 2, 3);
    // g2.addEdge(3, 2, 4);
    // g2.addEdge(0, 1, 5);
    // g2.addEdge(4, 3, 1);
    g.print_graph();
    printf("after bfs\n");
    Graph bfsTree= Algorithms::bfs(g,0);
    bfsTree.print_graph();
    printf("after dfs:\n");
    Graph dfsTree= Algorithms::dfs(g,0);
    dfsTree.print_graph();
    printf("after dijkstra:\n");
    Graph dTree=Algorithms::dijkstra(g,0);
    dTree.print_graph();
    printf("after prim:\n");
    Graph prim=Algorithms::prim(g);
    prim.print_graph();
    printf("after kruskal:\n");
    Graph kruskalTree=Algorithms::kruskal(g);
    kruskalTree.print_graph();
    // g.releaseMemory();
    // g2.releaseMemory();
    // bfsTree.releaseMemory();
    // dfsTree.releaseMemory();
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.