#include<bits/stdc++.h>
using namespace std;

// Adjacency Matrix
// int main()
// {
// 	int nodes, edges;
// 	cin >> nodes >> edges;

//  for 1 based index
// 	int adjMatrix[nodes+1][nodes+1];

// Storing in adjMarix for undirected graph
//     for(int i=0;i<edges;i++) {
//         int u, v;
//         cin >> u >> v;
//         adjMatrix[u][v] = 1;
//         adjMatrix[v][u] = 1;
//     }

//     for(int i=0;i<nodes+1;i++) {
//         for(int j=0;j<nodes+1;j++) {
//             if(adjMatrix[i][j] == 1) {
//                 cout << i << " " << j << " ";
//                 cout << endl;
//             }
//         }
//     }

// 	return 0;
// }

// 
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

    for(int u=0;u<=nodes;u++) {
        for(auto v : adjList[u]) {
            cout << u << " " << v << " ";
            cout << endl;
        }
    }

    return 0;
}