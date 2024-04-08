#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Print right -> bottom -> left -> top [TC - O(nxm)] [SC - O(nxm)]
*/

void arrayInput2D(vector<vector<int>> &numbers, int n, int m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> numbers[i][j]; 
        }
    }
}

// Approach 1
vector<int> spiralMatrix(vector<vector<int>> matrix, int n, int m) {

    int top = 0, bottom = n-1;
    int left = 0, right = m-1;

    vector<int> ans;

    while(top <= bottom && left <= right) {
        // Right
        for(int i=left;i<=right;i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // Bottom
        for(int i=top;i<=bottom;i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // Left
        if(top <= bottom) {
            for(int i=right;i>=left;i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Top
        if(left <= right) {
            for(int i=bottom;i>=top;i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main()
{
	int n, m;
    cin >> n >> m;

    vector<vector<int>> numbers(n, vector<int>(m));
    arrayInput2D(numbers, n , m);

    vector<int> result = spiralMatrix(numbers, n, m);

    for(auto it: result) {
        cout << it << " ";
    }

}