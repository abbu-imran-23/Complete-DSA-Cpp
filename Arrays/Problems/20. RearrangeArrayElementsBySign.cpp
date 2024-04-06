#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. By storing +ve and -ves - [TC - O(n) + O(n/2)] [SC - O(n)]
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

// Approach 1 - If no of +ve elements == no of -ve elements
vector<int> rearrangeArrayElementsBySignApp1(vector<int> &nums, int size) {
    vector<int> positives;
    vector<int> negatives;

    for(int i=0;i<size;i++) {
        if(nums[i] > 0) positives.push_back(nums[i]);
        else negatives.push_back(nums[i]);
    }

    for(int i=0;i<positives.size();i++) {
        nums[2 * i] = positives[i];
        nums[2 * i + 1] = negatives[i];
    }

    return nums;

}

// Approach 2 - If no of +ve elements == no of -ve elements
vector<int> rearrangeArrayElementsBySignApp2(vector<int> nums, int size) {
    int positiveIndex = 0;
    int negativeIndex = 1;
    vector<int> ans(size);
    for(int i=0;i<size;i++) {
        if(nums[i] > 0) {
            ans[positiveIndex] = nums[i];
            positiveIndex += 2;
        }
        else {
            ans[negativeIndex] = nums[i];
            negativeIndex += 2;
        }
    }
    return ans;
}

// Approach 1 - If no of +ve elements != no of -ve elements
vector<int> rearrangeArrayElementsBySignApp3(vector<int> &nums, int size) {
    vector<int> positives;
    vector<int> negatives;

    for(int i=0;i<size;i++) {
        if(nums[i] > 0) positives.push_back(nums[i]);
        else negatives.push_back(nums[i]);
    }

    if(positives.size() > negatives.size()) {
        for(int i=0;i<negatives.size();i++) {
            nums[2 * i] = positives[i];
            nums[2 * i + 1] = negatives[i];
        }
        // Remaining Positives
        int index = negatives.size() * 2;
        for(int i=negatives.size();i<positives.size();i++) {
            nums[index] = positives[i];
            index++;
        }
    }
    else {
        for(int i=0;i<positives.size();i++) {
            nums[2 * i] = positives[i];
            nums[2 * i + 1] = negatives[i];
        }
        // Remaining Positives
        int index = positives.size() * 2;
        for(int i=positives.size();i<negatives.size();i++) {
            nums[index] = negatives[i];
            index++;
        }
    }
    return nums;
}

int main()
{
	int size;
    cin >> size;

    vector<int> numbers(100);
    arrayInput(numbers, size);

    // If no of +ve elements == no of -ve elements
    vector<int> result1 = rearrangeArrayElementsBySignApp1(numbers, size);
    printArray(result1, size);

    vector<int> result2 = rearrangeArrayElementsBySignApp2(numbers, size);
    printArray(result2, size);

    // If no of +ve elements != no of -ve elements
    vector<int> result3 = rearrangeArrayElementsBySignApp3(numbers, size);
    printArray(result3, size);

}