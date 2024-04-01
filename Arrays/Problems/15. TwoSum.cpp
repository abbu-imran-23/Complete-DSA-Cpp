#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Using two loops - [TC - O(n^2)]
   2. Using map - [TC - O(n)] [SC - O(n)]
   3. Using Two Pointer should be sorted - [TC - O(n) + O(nlog(n))]
*/


void arrayInput(int numbers[], int size) {
    for(int i=0;i<size;i++) {
        cin >> numbers[i];
    }
}

// Approach 1
string twoSumApproach1(int numbers[], int size, int target) {
    for(int i=0;i<size;i++) {
        for(int j=i+1;j<size;j++) {
            if(numbers[i] + numbers[j] == target) {
                return "YES";
            }
        }
    }
    return "NO";
}

// Approach 2
string twoSumApproach2(int numbers[], int size, int target) {
    unordered_map<int,int> mp;

    for(int i=0;i<size;i++) {
        if(mp.find(target - numbers[i]) != mp.end()) {
            return "YES";
        }
        mp[numbers[i]] = i;
    }

    return "NO";
}

// Approach 3
string twoSumApproach3(int numbers[], int size, int target) {
    sort(numbers, numbers + size);
    int left = 0;
    int right = size - 1;
    while(left < right) {
        int sum = numbers[left] + numbers[right];
        if(sum == target) {
            return "YES";
        }
        else if(sum < target) left++;
        else right--;
    }
    return "NO";
}

int main()
{
	int size;
    cin >> size;

    int numbers[100];

    arrayInput(numbers, size);

    int target;
    cin >> target;

    string result1 = twoSumApproach1(numbers, size, target);
    string result2 = twoSumApproach2(numbers, size, target);
    string result3 = twoSumApproach3(numbers, size, target);

    cout << result1 << endl;
    cout << result2 << endl;
    cout << result3 << endl;

}