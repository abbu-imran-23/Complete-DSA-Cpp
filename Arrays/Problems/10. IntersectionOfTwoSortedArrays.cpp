#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Use Map - [TC - O(m) + O(n) = O(m+n)] [SC - O(m)]
   2. Two pointer Approach - [TC - O(m) +  O(n) = O(m+n)] [SC - O(1)]
*/

// Approach 1
vector<int> intersectionOfTwoSortedArraysApp1(vector<int> nums1, int m, vector<int> nums2, int n) {
    unordered_map<int,int> mp;
    vector<int> intersectionArray;

    for(int i=0;i<m;i++) {
        mp[nums1[i]]++;
    }

    for(int i=0;i<n;i++) {
        if(mp.find(nums2[i]) != mp.end()) {
            intersectionArray.push_back(nums2[i]);
        }
    }

    return intersectionArray;

}

// Approach 2
vector<int> intersectionOfTwoSortedArraysApp2(vector<int> nums1, int m, vector<int> nums2, int n) {
    vector<int> intersectionArray;

    int i=0;
    int j=0;

    while(i<m && j<n) {
        if(nums1[i] < nums2[j]) {
            i++;
        }
        else if(nums1[i] > nums2[j]) {
            j++;
        }
        else {
            intersectionArray.push_back(nums1[i]);
            i++;
            j++;
        }
    }

    return intersectionArray;

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
	int m, n;
    cin >> m >> n;

    vector<int> nums1(100);
    arrayInput(nums1, m);
    vector<int> nums2(100);
    arrayInput(nums2, n);

    vector<int> intersectionArrayApp1 = intersectionOfTwoSortedArraysApp1(nums1, m, nums2, n);
    printArray(intersectionArrayApp1, intersectionArrayApp1.size());

    vector<int> intersectionArrayApp2 = intersectionOfTwoSortedArraysApp2(nums1, m, nums2, n);
    printArray(intersectionArrayApp2, intersectionArrayApp2.size());

}