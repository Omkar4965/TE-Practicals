/*
Implement depth first search algorithm and Breadth First Search algorithm, use an undirected
graph and develop a recursive algorithm for searching all the vertices of a graph or tree data
structure.
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node){
    visited[node] = true;
    cout<<node<<" ";

    for(auto n : graph[node]){
        if(!visited[n]) dfs(graph, visited, n);
    }
}

void bfs(vector<vector<int>>& graph){
    queue<int>q;
    vector<bool> visited(5, false);
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int n = q.front(); q.pop();

        cout<<n<<" ";

        for(auto node : graph[n]){
            if(!visited[node]){
                visited[node] = true;
                q.push(node);
            }
        }
    }
}


int main(){
    // Create a graph using adjacency list representation
    int V = 5; // Number of vertices in the graph
    vector<vector<int>> graph(V);
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0};
    graph[3] = {1};
    graph[4] = {1};

    // Perform DFS using recursion
    cout << "Depth First Search (DFS):" << endl;
    vector<bool> visited(5, false);
    dfs(graph, visited, 0);

    cout << endl;
    // Perform BFS using queue
    cout << "Breadth First Search (BFS):" << endl;
    bfs(graph);

    return 0;
}