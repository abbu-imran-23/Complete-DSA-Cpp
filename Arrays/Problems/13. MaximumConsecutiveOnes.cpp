#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Linear Traverse with condition - [TC - O(n)]
*/


void arrayInput(int numbers[], int size) {
    for(int i=0;i<size;i++) {
        cin >> numbers[i];
    }
}

int maximumConsecutiveOnes(int numbers[], int size) {
    int count = 0;
    int maxCount = 0;

    for(int i=0;i<size;i++) {
        if(numbers[i]) {
            count++;
        }
        else {
            maxCount = max(maxCount, count);
            count = 0;
        }
    }

    return max(maxCount, count);
}

int main()
{
	int size;
    cin >> size;

    int numbers[100];

    arrayInput(numbers, size);

    int result = maximumConsecutiveOnes(numbers, size);

    cout << result;

}