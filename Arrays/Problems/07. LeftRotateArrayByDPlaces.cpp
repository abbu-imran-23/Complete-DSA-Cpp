#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Left Rotate Array By 1 Place Approach - [TC - O(d) + O(n-d) + O(d) = O(n+d)] [SC - O(d)]
   2. Reverse the Array Approach - [TC - O(d) + O(n-d) + O(n) = O(2n)] [SC - O(1)]
*/

// Approach 1
void leftRotateArrayByDPlacesApp1(int numbers[], int size, int d) {
    vector<int> temp;
    d = d % size;

    for(int i=0;i<d;i++) {
        temp.push_back(numbers[i]);
    }

    for(int i=d;i<size;i++) {
        numbers[i-d] = numbers[i];
    }

    int j=0;
    for(int i=size-d;i<size;i++) {
        numbers[i] = temp[j];
        j++;
    }
}

void reverse(int numbers[], int start, int end) {
    while(start < end) {
        int temp = numbers[start];
        numbers[start] = numbers[end];
        numbers[end] = temp;
        start++;
        end--;
    }
}

// Approach 2
void leftRotateArrayByDPlacesApp2(int numbers[], int n, int d) {
    d = d % n;
    reverse(numbers,0,d-1);
    reverse(numbers,d,n-1);
    reverse(numbers,0,n-1);
}

// Approach 2 
void rightRotateArrayByDPlacesApp2(int numbers[], int n, int d) {
    d = d % n;
    reverse(numbers,0,n-1);
    reverse(numbers,0,d-1);
    reverse(numbers,d,n-1);
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

    int places;
    cin >> places;

    // leftRotateArrayByDPlacesApp1(numbers, size, places);
    // leftRotateArrayByDPlacesApp2(numbers, size, places);

    rightRotateArrayByDPlacesApp2(numbers, size, places);

    printArray(numbers, size);

}