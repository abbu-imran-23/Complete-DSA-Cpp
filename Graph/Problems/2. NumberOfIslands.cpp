#include<bits/stdc++.h>
using namespace std;

void bfs(int r, int c, vector<vector<int>> &adjMatrix, vector<vector<int>> &visited) {
    queue<pair<int,int>> q;
    int n = adjMatrix.size();
    int m = adjMatrix[0].size();

    visited[r][c] = 1;
    q.push({r, c});

    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

        while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && adjMatrix[nr][nc] && !visited[nr][nc]) {
                visited[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }
}

int numberOfIslands(vector<vector<int>> &adjMatrix) {
    int n = adjMatrix.size();
    int m = adjMatrix[0].size();
    vector<vector<int>> visited(n, vector<int>(m,0));
    int islands = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(adjMatrix[i][j] && !visited[i][j]) {
                bfs(i, j, adjMatrix, visited);
                islands++;
            }
        }
    }

    return islands;
}

int main() {
    int rows, columns;
	cin >> rows >> columns;

    // for 1 based index
	vector<vector<int>> adjMatrix(rows, vector<int>(columns, 0));

    // Storing in adjList for undirected graph
    for(int i=0;i<rows;i++) {
        for(int j=0;j<columns;j++) {
            cin >> adjMatrix[i][j];
        }
    }

    int totalIslands = numberOfIslands(adjMatrix);
    cout << totalIslands;

    return 0;
}