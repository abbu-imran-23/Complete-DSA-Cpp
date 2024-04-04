#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Using Two loops - [TC - O(n^2)]
   2. Using Hashmap - [TC - O(n) + O(n) = O(2n)] [SC - O(n)]
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

}