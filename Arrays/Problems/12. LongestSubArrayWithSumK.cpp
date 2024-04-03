#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Use Two For Loops - [TC - O(n^2)] [SC - O(1)]
   2. Using Hashmap for prefix sum - [TC - O(n)] [SC - O(n)]
   2. Two Pointer Approach - [TC - O(2n)] [SC - O(1)]
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

// Approach 2 - Optimal Approach if array have both +ve and -ve values
int longestSubArrayWithSumKApp2(vector<int> nums, int size, int k) {
    unordered_map<int, int> prefixMap;
    int sum = 0;
    int maxLength = 0;

    for(int i=0;i<size;i++) {
        sum += nums[i];
        if(sum == k) {
            maxLength = max(maxLength, i+1);
        }
        int remainingSum = sum - k;
        if(prefixMap.find(remainingSum) != prefixMap.end()) {
            maxLength = max(maxLength, i - prefixMap[remainingSum]);
        }
        // prefixMap[sum] = i - If nums[i] has only +ve elements
        if(prefixMap.find(sum) == prefixMap.end()) { // If nums[i] have both +ve and -ve elements
            prefixMap[sum] = i;
        } 
    }

    return maxLength;

}

// Approach 3 - Optimal Approach if array has 0 and +ve values
int longestSubArrayWithSumKApp3(vector<int> nums, int size, int k) {
    int maxLength = 0;
    int sum = nums[0];
    int left = 0;
    int right = 0;
    while(right < size) {
        // Sum > K
        while(sum > k && left <= right) {
            sum -= nums[left];
            left++;
        }

        if(sum == k) {
            maxLength = max(maxLength, right - left + 1);
        }

        // Sum < K
        right++;
        if(right < size) {
            sum += nums[right];
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

    int maxLengthApp1 = longestSubArrayWithSumKApp1(nums, size, k);
    cout << maxLengthApp1 << endl;

    int maxLengthApp2 = longestSubArrayWithSumKApp2(nums, size, k);
    cout << maxLengthApp2 << endl;

    int maxLengthApp3 = longestSubArrayWithSumKApp3(nums, size, k);
    cout << maxLengthApp3 << endl;

}