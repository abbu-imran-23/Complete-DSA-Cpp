#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<int> &visited) {
    visited[node] = 1;

    for(auto it: adj[node]) {
        if(!visited[it]) {
            if(dfs(it, node, adj, visited)) return true;
        }
        else if(parent != it) return true;
    }

    return false;
}

bool detectCycleInAnUndirectedGraph(vector<int> adjList[], int nodes) {
    vector<int> visited(nodes, 0);

    for(int i=0;i<nodes;i++) {
        if(!visited[i]) {
            if(dfs(i, -1, adjList, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int nodes, edges;
	cin >> nodes >> edges;

    // for 1 based index
	vector<int> adjList[nodes + 1];

    // Storing in adjList for undirected graph
    for(int i=0;i<edges;i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool isCyclePresent = detectCycleInAnUndirectedGraph(adjList, nodes);
    cout << isCyclePresent;

    return 0;
}