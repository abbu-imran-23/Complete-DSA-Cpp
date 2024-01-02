#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Use Set for not allowing duplicates and multiset for duplicates - [TC - O(mlog(m) + nlog(n)) + O(m+n)] [SC - O(m+n)]
   2. Two pointer Approach - [TC - O(x) + O(n-x) + O(n) = O(n)] [SC - O(1)]
*/

// Approach 1
vector<int> unionOfTwoSortedArraysApp1(vector<int> nums1, int m, vector<int> nums2, int n) {
    set<int> st;
    vector<int> unionArray;
    
    for(int i=0;i<m;i++) {
        st.insert(nums1[i]);
    }

    for(int i=0;i<n;i++) {
        st.insert(nums2[i]);
    }

    for(auto it: st) {
        unionArray.push_back(it);
    }

    return unionArray;
}

// Approach 2
vector<int> unionOfTwoSortedArraysApp2(vector<int> nums1, int m, vector<int> nums2, int n) {
    vector<int> unionArray;

    int i = 0;
    int j = 0;

    while(i<m && j<n) {
        if(nums1[i] <= nums2[j]) {
            if(unionArray.size() == 0 || unionArray.back() != nums1[i]) {
                unionArray.push_back(nums1[i]);
            }
            i++;
        }
        else {
            if(unionArray.size() == 0 || unionArray.back() != nums2[j]) {
                unionArray.push_back(nums2[j]);
            }
            j++;
        }
    }

    while(i<m) {
        if(unionArray.size() == 0 || unionArray.back() != nums1[i]) {
                unionArray.push_back(nums1[i]);
            }
        i++;
    }

    while(j<n) {
        if(unionArray.size() == 0 || unionArray.back() != nums2[j]) {
                unionArray.push_back(nums2[j]);
            }
        j++;
    }

    return unionArray;

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

    vector<int> unionArrayApp1 = unionOfTwoSortedArraysApp1(nums1, m, nums2, n);
    printArray(unionArrayApp1, unionArrayApp1.size());

    vector<int> unionArrayApp2 = unionOfTwoSortedArraysApp2(nums1, m, nums2, n);
    printArray(unionArrayApp2, unionArrayApp2.size());

}