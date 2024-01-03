#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Use Two For Loops - [TC - O(n^2)] [SC - O(1)]
   2. Using Sum - [TC - O(n)] [SC - O(1)]
*/

// Approach 1
int longestSubArrayWithSumKApp1(vector<int> nums, int size, int k) {
    int maxLength = 0;
    for(int i=0;i<size;i++) {
        int sum = 0;
        for(int j=i;j<size;j++) {
            sum += nums[j];
            if(sum == k) {
                maxLength = max(maxLength, j-i+1);
            }
        }
    }
    return maxLength;
}

int longestSubArrayWithSumKApp2(vector<int> nums, int size, int k) {
    int maxLength = 0;
    int sum = nums[0];
    int i = 0;
    int j = 0;
    while(j < size) {
        while(sum > k && i<=j) {
            sum -= nums[i];
            i++;
        }
        if(sum == k) {
            maxLength = max(maxLength, j-i+1);
        }
        j++;
        if(j < size) {
            sum += nums[j];
        }
    }
    return maxLength;
}

void arrayInput(vector<int> &numbers, int size) {
    for(int i=0;i<size;i++) {
        cin >> numbers[i];
    }
}

void printArray(vector<int> numbers, int size) {
    for(int i=0;i<size;i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

int main()
{
	int size;
    cin >> size;

    vector<int> nums(100);
    arrayInput(nums, size);

    int k;
    cin >> k;

    // int maxLengthApp1 = longestSubArrayWithSumKApp1(nums, size, k);
    // cout << maxLengthApp1 << endl;

    int maxLengthApp2 = longestSubArrayWithSumKApp2(nums, size, k);
    cout << maxLengthApp2;

}