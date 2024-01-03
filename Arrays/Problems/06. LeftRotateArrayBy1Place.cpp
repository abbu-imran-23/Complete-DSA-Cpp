#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Linear Traverse with condition - [TC - O(n)] [SC - O(1)]
*/

void leftRotateArrayByOnePlace(int numbers[], int size) {
    int temp = numbers[0];
    for(int i=0;i<size-1;i++) {
        numbers[i] = numbers[i+1];
    }
    numbers[size-1] = temp;
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

    leftRotateArrayByOnePlace(numbers, size);

    printArray(numbers, size);

}