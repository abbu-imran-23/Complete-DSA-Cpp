#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Using two loops - [TC - O(n^2)]
   2. Using XOR - [TC - o(n)]
*/


void arrayInput(int numbers[], int size) {
    for(int i=0;i<size;i++) {
        cin >> numbers[i];
    }
}

int numberThatAppearsOnlyOnce(int numbers[], int size) {
    int xorAns = 0;
    for(int i=0;i<size;i++) {
        xorAns = xorAns ^ numbers[i];
    }
    return xorAns;
}

int main()
{
	int size;
    cin >> size;

    int numbers[100];

    arrayInput(numbers, size);

    int result = numberThatAppearsOnlyOnce(numbers, size);

    cout << result;

}