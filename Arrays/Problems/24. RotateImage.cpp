#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Identify the index and place it - [TC - O(nxm)] [SC - O(nxm)]
   2. Transpose and Reverse the rows - [TC - O(n x m) + O(n X m/2)] 
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
vector<vector<int>> rotateArrayBy90DegreeApp1(vector<vector<int>> nums, int n, int m) {
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            ans[j][n-1-i] = nums[i][j];
        }
    }
    return ans;
}

// Approach 2
void rotateArrayBy90DegreeApp2(vector<vector<int>> &nums, int n, int m) {
    // Transpose the Matrix
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            swap(nums[i][j], nums[j][i]);
        }
    }
    // Reverse the Rows
    for(int i=0;i<n;i++) {
        reverse(nums[i].begin(), nums[i].end());
    }
}

int main()
{
	int n, m;
    cin >> n >> m;

    vector<vector<int>> numbers(n, vector<int>(m));
    arrayInput2D(numbers, n , m);

    vector<vector<int>> result = rotateArrayBy90DegreeApp1(numbers, n, m);
    printArray2D(result, n, m);

    cout << endl;

    rotateArrayBy90DegreeApp2(numbers, n, m);
    printArray2D(numbers, n, m);

}