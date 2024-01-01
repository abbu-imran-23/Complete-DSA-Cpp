#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Sort and return the last element - [TC - O(nlog(n))] [SC - O(1)]
   2. Linear Traverse with condition - [TC - O(n)]
*/

int findLargestElement(int numbers[], int size) {
    int largestElement = INT_MIN;

    for(int i=0;i<size;i++) {
        if(numbers[i] > largestElement) {
            largestElement = numbers[i];
        }
    }

    if(largestElement != INT_MIN) {
        return largestElement;
    }
    return -1;
}

int findSmallestElement(int numbers[], int size) {
    int smallestElement = INT_MAX;

    for(int i=0;i<size;i++) {
        if(numbers[i] < smallestElement) {
            smallestElement = numbers[i];
        }
    }
    
    if(smallestElement != INT_MAX) {
        return smallestElement;
    }
    return -1;
}

void arrayInput(int numbers[], int size) {
    for(int i=0;i<size;i++) {
        cin >> numbers[i];
    }
}

int main()
{
	int size;
    cin >> size;

    int numbers[100];

    arrayInput(numbers, size);

    int largestElement = findLargestElement(numbers, size);
    int smallestElement = findSmallestElement(numbers, size);

    cout << largestElement << endl;
    cout << smallestElement;

}