/*
Implement Greedy search algorithm for any one of the following application:
I Selection Sort
II Minimum Spanning Tree
III Single-Source Shortest Path Problem
IV Job Scheduling Problem
V Prim's Minimal Spanning Tree Algorithm
VI Kruskal's Minimal Spanning Tree Algorithm
VII Dijkstra's Minimal Spanning Tree Algorithm
*/

#include <bits/stdc++.h>
using namespace std;


class disjointSet{
    public:
    vector<int> size;
    vector<int> parent;
    disjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int getParent(int n){
        if(parent[n] == n) return n;
        return parent[n] = getParent(parent[n]);
    }

    void merge(int a, int b){
        int pa = getParent(a);
        int pb = getParent(b);

        if(pa == pb) return;

        if(size[pa] < size[pb]){
            parent[pa] = pb;
            size[pb] += size[pa];
        }else{
            parent[pb] = pa;
            size[pa] += size[pb];
        }
    }
};

void dijkestra(int n, vector<pair<int, int>> adj[] ){
    // Single src shortest path problem
    // dijkstra
    
    int src;
    cin >> src; 
    vector<int> dist(n+1, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
    q.push({0, src});

    while(!q.empty()){
        pair<int,int>p = q.top(); q.pop();
        int wt = p.first;
        int curr = p.second;

        if (wt > dist[curr]) continue;

        for(auto node : adj[curr]){
            if(node.second + wt < dist[node.first]){
                dist[node.first] = node.second + wt;
                q.push({dist[node.first], node.first});
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<i<<" --> "<<dist[i]<<endl;
    }
}

void primsMST(){

}

void kruskal(int n, vector<pair<int, int>> adj[]){
    disjointSet ds(n);
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;

    for(int i=0; i<n; i++){
        for(auto it : adj[i]){
            if (i < it.first) pq.push({it.second,{i, it.first}});
        }
    }

    int res = 0;
    int edgecount = 0;

    while(!pq.empty()){
        pair<int,pair<int,int>> p = pq.top(); pq.pop();
        int wt = p.first;
        int n1 = p.second.first;
        int n2 = p.second.second;

        int pn1 = ds.getParent(n1);
        int pn2 = ds.getParent(n2);

        if(pn1 == pn2) continue;
        ds.merge(n1,n2);
        res+=wt;
        edgecount++;
    }
    cout<<"edgecount: "<<edgecount<<endl;
    cout<<"mst: "<<res;

}

void prims(int n, vector<pair<int, int>>adj[]){
    vector<bool>vis(n, false);

    vis[0] = true;
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    for(auto it : adj[0]){
        pq.push({it.second, it.first});
    }

    int res = 0;
    while(!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        int n = p.second;
        if(vis[n]) continue;
        vis[n] = true;
        res+=p.first;
        for(auto it : adj[n]){
            if(vis[it.first]) continue;
            pq.push({it.second, it.first});
        }
    }

    cout<<"MST: "<<res;

}
int main(){
    int n, m;
    cin >> n >> m;  
    vector<pair<int, int>> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // kruskal(n,adj);
    prims(n,adj);



    return 0;
}