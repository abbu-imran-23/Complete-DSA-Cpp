#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m,0));
    queue<pair<pair<int,int>, int>> q;
    int maxTime = 0;
    int freshOrangesCount = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == 2) {
                q.push({{i, j}, 0});
                visited[i][j] = 1;
            }
            else if(grid[i][j] == 1) {
                freshOrangesCount++;
            }
        }
    }

    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int time = q.front().second;
        maxTime = max(maxTime, time);
        q.pop();

        for(int i=0;i<4;i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1 && !visited[nr][nc]) {
                visited[nr][nc] = 1;
                q.push({{nr, nc}, time+1});
                freshOrangesCount--;
            }
        }
    }

    if(freshOrangesCount) return -1;

    return maxTime;
}

int main() {
    int rows, columns;
	cin >> rows >> columns;

	vector<vector<int>> adjMatrix(rows, vector<int>(columns, 0));

    // Storing in adjList for undirected graph
    for(int i=0;i<rows;i++) {
        for(int j=0;j<columns;j++) {
            cin >> adjMatrix[i][j];
        }
    }

    int ans = orangesRotting(adjMatrix);
    
    cout << ans;

    return 0;
}