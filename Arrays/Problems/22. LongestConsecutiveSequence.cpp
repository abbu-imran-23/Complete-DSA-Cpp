#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Using Two Loops - [TC - O(n^2)] [SC - O(n)]
   2. Using Single Loop - [TC - O(n)] [SC - O(n)]
*/

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

// Approach 1
int longestConsecutiveSequenceApp1(vector<int>& nums) {

    if(nums.size() == 0) return 0;

    sort(nums.begin(), nums.end());
    int longest = 1;
    int count = 0;
    int lastSmaller = INT_MIN;

    for(int i=0;i<nums.size();i++) {
        if(nums[i] - 1 == lastSmaller) {
            count += 1;
            lastSmaller = nums[i];
        }
        else if(nums[i] != lastSmaller) {
            count = 1;
            lastSmaller = nums[i];
        }
        longest = max(longest, count);
    }
    return longest;

}

int main()
{
	int size;
    cin >> size;

    vector<int> numbers(size);
    arrayInput(numbers, size);

    int result1 = longestConsecutiveSequenceApp1(numbers);
    cout << result1 << endl;

    // vector<int> result2 = leadersInAnArrayApp2(numbers, size);
    // printArray(result2, result2.size());

}