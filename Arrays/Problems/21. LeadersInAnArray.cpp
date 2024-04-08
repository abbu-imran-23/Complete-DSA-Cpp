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
vector<int> leadersInAnArrayApp1(vector<int> nums, int size) {
    vector<int> ans;
    for(int i=0;i<size;i++) {
        bool leader = true;
        for(int j=i+1;j<size;j++) {
            if(nums[j] >= nums[i]) {
                leader = false;
                break;
            }
        }
        if(leader) {
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

// Approach 2 - It will return a sorted array
vector<int> leadersInAnArrayApp2(vector<int> nums, int size) {
    int maximumToRight = INT_MIN;
    vector<int> ans;
    for(int i=size-1;i>=0;i--) {
        if(nums[i] > maximumToRight) {
            ans.push_back(nums[i]);
            maximumToRight = nums[i];
        }
    }
    return ans;
}

int main()
{
	int size;
    cin >> size;

    vector<int> numbers(100);
    arrayInput(numbers, size);

    vector<int> result1 = leadersInAnArrayApp1(numbers, size);
    printArray(result1, result1.size());

    vector<int> result2 = leadersInAnArrayApp2(numbers, size);
    printArray(result2, result2.size());

}