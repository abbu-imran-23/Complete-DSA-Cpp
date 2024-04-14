#include<bits/stdc++.h>
using namespace std;

void dfs(int r, int c, vector<vector<int>>& image, vector<vector<int>> &visited, int initialColor, int newColor) {
    int n = image.size();
    int m = image[0].size();

    visited[r][c] = 1;
    image[r][c] = newColor;

    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    for(int i=0;i<4;i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc] == initialColor && !visited[nr][nc]) {
            dfs(nr, nc, image, visited, initialColor, newColor);
        }
    }
}

vector<vector<int>> floodFillAlgorithm(vector<vector<int>>& image, int sr, int sc, int color) {
    vector<vector<int>> imageCopy = image;
    int n = image.size();
    int m = image[0].size();
    int initialColor = image[sr][sc];
    vector<vector<int>> visited(n, vector<int>(m, 0));

    dfs(sr, sc, imageCopy, visited, initialColor, color);

    return imageCopy;
}

void printArray2D(vector<vector<int>> numbers, int n, int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << numbers[i][j] << " "; 
        }
        cout << endl;
    }
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

    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> ans = floodFillAlgorithm(adjMatrix, sr, sc, color);
    
    printArray2D(ans, ans.size(), ans[0].size());

    return 0;
}