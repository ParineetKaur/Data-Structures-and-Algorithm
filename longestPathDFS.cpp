// Question: What is the longest path in a given weighted graph?
// The code performs Depth-First Search (DFS) Traversal by recursively looking at the paths, backtracking if needed, and continually tracking the maximum path length. 
#include <iostream>
using namespace std;

void graph::dfs(vector<pair<int,int> graph, int s, int previousLength, int* MAXIMUM, vector<bool> visited){
  visited[s] = true;
  int presentLength = 0;
  pair adj;
  for(int j = 0; j < graph[s].size; j++){
    adj = graph[s].get(j);
    if(!(visited[adj.first]){
      presentLength = previousLength + adj.second;
      DFS(graph,adj.first,presentLength,visited);
    }
    if(MAXIMUM < presentLength){
      MAXIMUM = presentLength;
    }
    presentLength = 0;
  }
}

int findLongest(vector<r<pair<int, int>> graph, int nodeCount){
  int maxLength = minLength;
  for(int j = 0; j <= nodeCount; j++){
    vector<bool> visited;
    DFS(graph,j, &maxLength,visited);
  }
  return macLength;
}
