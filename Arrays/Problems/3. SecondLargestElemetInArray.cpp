#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Sort and return the 2nd last element (if no duplicates) - [TC - O(nlog(n))] [SC - O(1)]
   2. Sort and check with loop wheather 2nd last element is different from largest element (if duplicates) - [TC - O(nlog(n)) + O(n)] [SC - O(1)]
   3. Loop and find first largest then loop once again to find second largest - [TC - O(2n)]
   4. Linear Traverse with condition - [TC - O(n)]
*/

int findSecondLargestElement(int numbers[], int size) {
    int firstLargest = INT_MIN;
    int secondLargest = INT_MIN;

    for(int i=0;i<size;i++) {
        if(numbers[i] > firstLargest) {
            secondLargest = firstLargest;
            firstLargest = numbers[i];
        }
        else if(numbers[i] > secondLargest && numbers[i] < firstLargest) {
            secondLargest = numbers[i];
        }
    }

    return secondLargest;
}

int findSecondSmallestElement(int numbers[], int size) {
    int firstSmallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for(int i=0;i<size;i++) {
        if(numbers[i] < firstSmallest) {
            secondSmallest = firstSmallest;
            firstSmallest = numbers[i];
        }
        else if(numbers[i] > firstSmallest && numbers[i] < secondSmallest) {
            secondSmallest = numbers[i];
        }
    } 

    return secondSmallest;
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

    int secondLargestElement = findSecondLargestElement(numbers, size);

    int secondSmallestElement = findSecondSmallestElement(numbers, size);

    cout << secondLargestElement << endl;
    cout << secondSmallestElement << endl;

}