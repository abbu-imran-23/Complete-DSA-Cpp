#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Use Two For Loops - [TC - O(n^2)] [SC - O(1)]
   2. Using Sum - [TC - O(n)] [SC - O(1)]
   2. Using XOR - [TC - O(n)] [SC - O(1)]
*/

// Approach 1
int findMissingNumberApp1(vector<int> nums, int size) {
    for(int i=1;i<=size;i++) {
        bool isExist = false;
        for(int j=0;j<size-1;j++) {
            if(nums[j] == i) {
                isExist = true;
                break;
            }
        }
        if(!isExist) {
            return i;
        }
    }
    return -1;
}

// Approach 2
int findMissingNumberApp2(vector<int> nums, int size) {
    int totalSum = size * (size + 1)/2;
    for(int i=0;i<size-1;i++) {
        totalSum -= nums[i];
    }
    return totalSum;
}

// Approach 3
int findMissingNumberApp3(vector<int> nums, int size) {
    int xor1 = 0;
    int xor2 = 0;
    for(int i=0;i<size-1;i++) {
        xor1 = xor1 ^ nums[i];
        xor2 = xor1 ^ (i+1);
    }
    xor2 = xor2 ^ size;
    return xor2;
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

    int missingNumberApp1 = findMissingNumberApp1(nums, size);
    cout << missingNumberApp1 << endl;

    int missingNumberApp2 = findMissingNumberApp2(nums, size);
    cout << missingNumberApp2 << endl;

    int missingNumberApp3 = findMissingNumberApp3(nums, size);
    cout << missingNumberApp3 << endl;

}