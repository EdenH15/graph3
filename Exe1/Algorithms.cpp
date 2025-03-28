//
// Created by edenh15 on 3/24/25.
//
#include "Algorithms.h"
#include "Graph.h"
#include <iostream>
#include "structures.h"
#include <climits>

namespace graph {
  Graph Algorithms::bfs(const Graph& g, int srcVertex) {
    const int numVertices = g.get_numV();
    Graph bfsTree(numVertices);
    bool* visited = new bool[numVertices]();
    Queue q;
    q.enqueue(srcVertex);
    visited[srcVertex] = true;

    while (!q.isEmpty()) {
      int u = q.dequeue();
      Neighbor* neighbors = g.getNeighbors(u);
      while (neighbors) {
        int vertex = neighbors->vertex;
        if (!visited[vertex]) {
          q.enqueue(vertex);
          visited[vertex] = true;
          bfsTree.addNeighbor(u, vertex, neighbors->weight);
        }
        neighbors = neighbors->next;
      }
    }

    delete[] visited;
    return bfsTree;
  }


  void Algorithms::recDfs(Graph& g,int srcVertex,Graph& dfsTree,bool* visited){
    visited[srcVertex] = true;
    Neighbor* neighbors = g.getNeighbors(srcVertex);
    while(neighbors){
      int vertex = neighbors->vertex;
      if(!visited[vertex]){
        dfsTree.addNeighbor(srcVertex,vertex,neighbors->weight);
        recDfs(g,vertex,dfsTree,visited);
      }
      neighbors = neighbors->next;
    }
  }

  Graph Algorithms::dfs(Graph& g,int srcVertex){
    const int numVertices = g.get_numV();
    Graph dfsTree(numVertices);
    bool* visited = new bool[numVertices]();
    recDfs(g,srcVertex,dfsTree,visited);
    for(int i=0;i<numVertices;i++){
      if(!visited[i]){
        recDfs(g,i,dfsTree,visited);
      }
    }
    delete[] visited;
    return dfsTree;
  }
  Graph Algorithms::dijkstra(const Graph& g,int srcVertex) {
    const int INF = INT_MAX;
    const int numV = g.get_numV();
    int d[numV];
    bool processed[numV];
    int parent[numV];
    for (int i = 0; i < numV; i++) {
      d[i] = INF;
      processed[i] = false;
      parent[i] = -1;
    }
    d[srcVertex] = 0;
    minHeap minHeap;
    minHeap.insert(srcVertex,srcVertex,0);

    while (!minHeap.isEmpty()) {
      edge e = minHeap.extractMin();
      int u = e.dstV;
      if (processed[u]) {
        continue;
      }
      processed[u] = true;
      Neighbor* neighbors = g.getNeighbors(u);
      while (neighbors) {
        int vertex = neighbors->vertex;
        int weight = neighbors->weight;
        if (d[u] + weight < d[vertex]) {
          d[vertex] = d[u] + weight;
          minHeap.insert(u,vertex,weight);
          parent[vertex] = u;
        }
        neighbors = neighbors->next;
      }

    }
    Graph dijkstraTree(numV);
    for(int i=0;i<numV;i++) {
      if (parent[i] != -1) {
        dijkstraTree.addNeighbor(parent[i], i, d[i] - d[parent[i]]);
      }
    }
    return dijkstraTree;

  }
  Graph Algorithms::prim(const Graph& g) {
    const int numV = g.get_numV();
    bool* inTree = new bool[numV];

    for (int i = 0; i < numV; i++) {
      inTree[i] = false;
    }

    Graph mst(numV);
    minHeap minHeap;
    int srcV=0;

    Neighbor* n = g.getNeighbors(srcV);
    while(n) {
      minHeap.insert(srcV,n->vertex,n->weight);
      n = n->next;
    }

    inTree[srcV] = true;
    while(!minHeap.isEmpty()) {
      edge e = minHeap.extractMin();

      if (!inTree[e.dstV]) {
        inTree[e.dstV] = true;
        mst.addNeighbor(e.srcV,e.dstV,e.weight);
      }
        Neighbor* neighbors = g.getNeighbors(e.dstV);
        while (neighbors) {
          if (!inTree[neighbors->vertex]) {
            minHeap.insert(e.dstV,neighbors->vertex,neighbors->weight);
          }
          neighbors = neighbors->next;
        }
      }
    delete[] inTree;
    return mst;
    }

  }



