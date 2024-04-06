#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Using Two loops - [TC - O(n^2)]
   2. Using Hashmap - [TC - O(n) + O(n) = O(2n)] [SC - O(n)]
   3. Apply Moore's Voting Algo - [TC - O(n)] if maj ele always exist, else [TC - O(n) + O(n) = O(2n)] 
*/

void arrayInput(vector<int> &numbers, int size) {
    for(int i=0;i<size;i++) {
        cin >> numbers[i];
    }
}

// Approach 1
int majorityElementApp1(vector<int> nums, int size) {
    for(int i=0;i<size;i++) {
        int count = 0;
        for(int j=0;j<size;j++) {
            if(nums[i] == nums[j]) count++;
        }
        if(count > (size / 2)) {
            return nums[i];
        }
    }
    return -1;
}

// Approach 2
int majorityElementApp2(vector<int>& nums, int size) {
    unordered_map<int,int> mp;

    for(int i=0;i<size;i++) {
        mp[nums[i]]++;
    }

    for(auto it: mp) {
        if(it.second > (size/2)) {
            return it.first;
        }
    }
    return -1;
}

// Approach 3
int majorityElementApp3(vector<int>& nums, int size) {
    int count = 0;
    int element = -1;
    for(int i=0;i<size;i++) {
        if(count == 0) {
            element = nums[i];
            count++;
        }
        else if(nums[i] == element) {
            count++;
        }
        else {
            count --;
        }
    }
    // If the majority element may or may not exist
    // int countElement = 0;
    // for(int i=0;i<size;i++) {
    //     if(nums[i] == element) countElement++;
    // }
    // if(countElement > (size/2)) {
    //     return element;
    // }
    // return -1;

    return element;
}

int main()
{
	int size;
    cin >> size;

    vector<int> numbers(100);
    arrayInput(numbers, size);

    int result1 = majorityElementApp1(numbers, size);
    cout << result1 << endl;

    int result2 = majorityElementApp2(numbers, size);
    cout << result2 << endl;

    int result3 = majorityElementApp3(numbers, size);
    cout << result3 << endl;

}