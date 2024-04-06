#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Using Two loops - [TC - O(n^2)]
   2. Kadane's Algorithm - [TC - O(n)]
*/

void arrayInput(vector<int> &numbers, int size) {
    for(int i=0;i<size;i++) {
        cin >> numbers[i];
    }
}

// Approach 1
int maximumSubArraySumApp1(vector<int> nums, int size) {
    int maximumSum = INT_MIN;
    for(int i=0;i<size;i++) {
        int sum = 0;
        for(int j=i;j<size;j++) {
            sum += nums[j];
            maximumSum = max(maximumSum, sum);
        }
    }
    return maximumSum;
}

// Approach 2 - Kadane's Algorithm
int maximumSubArraySumApp2(vector<int> nums, int size) {
    int maximumSum = INT_MIN;
    int sum = 0;
    // Print the subarray which is giving maximum sum
    // int start = 0, ansStartIdx = -1, ansEndIdx = -1;
    for(int i=0;i<size;i++) {
        // if(sum == 0) start = i;
        sum += nums[i];
        maximumSum = max(maximumSum, sum);
        // if(sum > maximumSum) {
        //     maximumSum = sum;
        //     ansStartIdx = start;
        //     ansEndIdx = i;
        // }
        if(sum < 0) {
            sum = 0;
        }
    }

    // for(int i=ansStartIdx;i<=ansEndIdx;i++) {
    //     cout << nums[i] << " ";
    // }

    // cout << endl;

    return maximumSum;
}

int main()
{
	int size;
    cin >> size;

    vector<int> numbers(100);
    arrayInput(numbers, size);

    int result1 = maximumSubArraySumApp1(numbers, size);
    cout << result1 << endl;

    int result2 = maximumSubArraySumApp2(numbers, size);
    cout << result2 << endl;

}