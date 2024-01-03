#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Store non zero elements in temp and assign it back - [TC - O(n) + O(x) + O(n-x) = O(2n)] [SC - O(x)]
   2. Two pointer Approach - [TC - O(x) + O(n-x) + O(n) = O(n)] [SC - O(1)]
*/

// Approach 1
void moveZeroesToEndOfAnArrayApp1(vector<int> &nums, int size) {
    vector<int> temp;

    for(int i=0;i<size;i++) {
        if(nums[i] != 0) {
            temp.push_back(nums[i]);
        }
    }

    for(int i=0;i<temp.size();i++) {
        nums[i] = temp[i];
    }

    for(int i=temp.size();i<size;i++) {
        nums[i] = 0;
    }
}

// Approach 2
void moveZeroesToEndOfAnArrayApp2(vector<int> &nums, int size) {
    int j = -1;
    for(int i=0;i<size;i++) {
        if(nums[i] == 0) {
            j = i;
            break;
        }
    }
    for(int i=j+1;i<size;i++) {
        if(nums[i] != 0) {
            swap(nums[i],nums[j]);
            j++;
        }
    }
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

    vector<int> numbers(100);

    arrayInput(numbers, size);

    //moveZeroesToEndOfAnArrayApp1(numbers, size);
    moveZeroesToEndOfAnArrayApp2(numbers, size);

    printArray(numbers, size);

}