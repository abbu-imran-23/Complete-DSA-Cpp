#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adjList[], int node, int visited[], vector<int> &dfsResult) {

    visited[node] = 1;
    dfsResult.push_back(node);

    for(auto it: adjList[node]) {
        if(!visited[it]) {
            dfs(adjList, it, visited, dfsResult);      
        }
    }

}

int main() {
    int nodes, edges;
	cin >> nodes >> edges;

    // for 1 based index
	vector<int> adjList[nodes + 1];
    int visited[nodes+1] = {0};
    vector<int> dfsResult;

    // Storing in adjList for undirected graph
    for(int i=0;i<edges;i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int start = 1;
    dfs(adjList, start, visited, dfsResult);

    for(auto it: dfsResult) {
        cout << it << " ";
    }

    return 0;
}