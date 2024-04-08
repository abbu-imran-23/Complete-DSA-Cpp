#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Mark in the extra matrix as -1 and later mark as 0 - [TC - O(nxm) x O(n+m) + O(nxm)] [SC - O(nxm)]
   2. Mark and Update - [TC - O(2(n x m))] [SC - O(n) + O(m)]
*/

void arrayInput2D(vector<vector<int>> &numbers, int n, int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> numbers[i][j]; 
        }
    }
}

void printArray2D(vector<vector<int>> numbers, int n, int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << numbers[i][j] << " "; 
        }
        cout << endl;
    }
}

// Approach 1
void setMatrixZeroes(vector<vector<int>> &numbers, int n, int m) {
    int row[n] = {0};
    int col[m] = {0};

    // Mark the row and col which must be set to 0 later
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(numbers[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Set the marked row and col to 0
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(row[i] || col[j]) {
                numbers[i][j] = 0;
            }
        }
    }

}

int main()
{
	int n, m;
    cin >> n >> m;

    vector<vector<int>> numbers(n, vector<int>(m));
    arrayInput2D(numbers, n , m);

    setMatrixZeroes(numbers, n, m);

    printArray2D(numbers, n, m);

}