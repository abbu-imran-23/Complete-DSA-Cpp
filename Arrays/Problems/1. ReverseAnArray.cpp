#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Copy array elements from last index to another array - [TC - O(n)] [SC - O(n)]
   2. Two Pointer Method (Start & End) - [TC - O(n)]
*/

void reverseAnArray(int numbers[], int size) {
    int start = 0;
    int end = size - 1;
    while(start < end) {
        int temp = numbers[start];
        numbers[start] = numbers[end];
        numbers[end] = temp;
        start++;
        end--;
    }
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

int main() {

    int size;
    cin >> size;

    int numbers[100];

    arrayInput(numbers, size);

    reverseAnArray(numbers, size);

    printArray(numbers, size);

}