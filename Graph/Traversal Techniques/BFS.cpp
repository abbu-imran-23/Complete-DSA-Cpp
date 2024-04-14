#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int> adjList[], int nodes) {
    int visited[nodes+1] = {0};
    vector<int> bfs;
    queue<int> q;

    visited[1] = 1;
    q.push(1);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        // traverse for all its neighbours
        for(auto it: adjList[node]) {
            if(!visited[it]) {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    
    return bfs;
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

    vector<int> bfsResult = bfs(adjList, nodes);

    for(auto it: bfsResult) {
        cout << it << " ";
    }

    return 0;
}