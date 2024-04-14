#include<bits/stdc++.h>
using namespace std;

bool bfs(int node, vector<int> adjList[], vector<int> &visited) {
    queue<pair<int,int>> q;
    visited[node] = 1;
    q.push({node, -1});

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it: adjList[node]) {
            if(!visited[it]) {
                visited[it] = 1;
                q.push({it, node});
            }
            else if(parent != it) {
                return true;
            }
        }
    }
    return false;
}

bool detectCycleInAnUndirectedGraph(vector<int> adjList[], int nodes) {
    vector<int> visited(nodes, 0);

    for(int i=0;i<nodes;i++) {
        if(!visited[i]) {
            if(bfs(i, adjList, visited)) {
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