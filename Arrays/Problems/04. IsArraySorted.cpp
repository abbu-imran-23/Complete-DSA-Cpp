#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Linear Traverse with condition - [TC - O(n)] [SC - O(1)]
*/

bool isArraySorted(int numbers[], int size) {
    for(int i=1;i<size;i++) {
        if(!(numbers[i-1] < numbers[i]) || (numbers[i-1] == numbers[i])){
            return false;
        }
    }
    return true;
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

    bool isSorted = isArraySorted(numbers, size);

    cout << isSorted;

}