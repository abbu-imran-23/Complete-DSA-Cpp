#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Use Two For Loops - [TC - O(n^2)] [SC - O(1)]
   2. Using Set - [TC - O(n)] [SC - O(n)]
   2. Using Floyd's Algorithm - [TC - O(n)] [SC - O(1)]
*/

// Approach 1
int findDuplicateNumberApp1(vector<int> nums, int size) {
    for(int i=0;i<size;i++) {
        for(int j=i+1;j<size;j++) {
            if(nums[j] == nums[i]) {
                return nums[j];
            }
        }
    }
    return -1;
}

// Approach 2
int findDuplicateNumberApp2(vector<int> nums, int size) {
    unordered_set<int> st;

    for(auto it: nums) {
        if(st.find(it) != st.end()) {
            return it;
        }
        else {
            st.insert(it);
        }
    }

    return -1;
}

// Approach 3
int findDuplicateNumberApp3(vector<int> nums, int size) {
    int slow = nums[0];
    int fast = nums[0];

    // Find the intersection point of the two pointers
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Find the entrance of the cycle
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;    
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

    int duplicateNumberApp1 = findDuplicateNumberApp1(nums, size);
    cout << duplicateNumberApp1 << endl;

    int duplicateNumberApp2 = findDuplicateNumberApp2(nums, size);
    cout << duplicateNumberApp2 << endl;

    int duplicateNumberApp3 = findDuplicateNumberApp3(nums, size);
    cout << duplicateNumberApp3 << endl;

}