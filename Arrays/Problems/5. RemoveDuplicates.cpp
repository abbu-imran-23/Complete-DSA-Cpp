#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
             --- SORTED ARRAY --- 
    1. Use Set - [TC - O(nlog(n)) + O(n)] [SC - O(n)]
    2. Two Pointer - [TC - O(n)] [SC - O(1)]

             --- UNSORTED ARRAY --- 
    1. Use Set - [TC - O(nlog(n)) + O(n)] [SC - O(n)]
    2. Use Map - [TC - O(n)] [SC - O(n)]
*/

int removeDuplicatesFromSortedArray(int numbers[], int size) {
    int i=0;
    for(int j=1;j<size;j++) {
        if(numbers[j] != numbers[i]) {
            i++;
            numbers[i] = numbers[j];
        }
    }
    return i+1;
}

int removeDuplicatesFromUnSortedArray(int numbers[], int size) {
    set<int> st;

    for(int i=0;i<size;i++) {
        st.insert(numbers[i]);
    }

    int uniqueElements = st.size();

    int i=0;
    for(auto it: st) {
        numbers[i++] = it;
    }

    return uniqueElements;

}

void arrayInput(int numbers[], int size) {
    for(int i=0;i<size;i++) {
        cin >> numbers[i];
    }
}

void printArray(int numbers[], int size) {
    for(int i=0;i<size;i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

int main()
{
	int size;
    cin >> size;

    int numbers[100];

    arrayInput(numbers, size);

    int uniqueElementsOfSortedArray = removeDuplicatesFromSortedArray(numbers, size);
    int uniqueElementsOfUnSortedArray = removeDuplicatesFromUnSortedArray(numbers, size);

    printArray(numbers, size);
    cout << uniqueElementsOfSortedArray << endl;

    printArray(numbers, size);
    cout << uniqueElementsOfUnSortedArray << endl;

}