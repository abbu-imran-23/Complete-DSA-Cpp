#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adjList[], int visited[]) {
    visited[node] = 1;
    for(auto it: adjList[node]) {
        if(!visited[it]) {
            dfs(it, adjList, visited);
        }
    }
}

int numberOfProvinces(vector<int> adjList[], int nodes) {
    int visited[nodes+1] = {0};
    int totalProvinces = 0;
    for(int i=1;i<=nodes;i++) {
        if(!visited[i]) {
            dfs(i, adjList, visited);
            totalProvinces++;
        }
    }
    return totalProvinces;
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

    int totalProvinces = numberOfProvinces(adjList, nodes);
    cout << totalProvinces;

    return 0;
}