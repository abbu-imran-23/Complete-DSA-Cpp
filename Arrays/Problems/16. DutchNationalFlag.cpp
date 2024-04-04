#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Linear Traverse with condition - [TC - O(2n)]
   2. Dutch National Flag Algorithm - [TC - O(n)]
*/


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

// Approach 1
void sort012App1(vector<int> &numbers, int size) {
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    for(int i=0;i<size;i++) {
        if(numbers[i] == 0) zeroCount++;
        else if(numbers[i] == 1) oneCount++;
        else twoCount++;
    }

    for(int i=0;i<zeroCount;i++) {
        numbers[i] = 0;
    }
    for(int i=zeroCount;i<zeroCount+oneCount;i++) {
        numbers[i] = 1;
    }
    for(int i=zeroCount+oneCount;i<size;i++) {
        numbers[i] = 2;
    }

}

// Approach 2
void sort012App2(vector<int> &numbers, int size) {
    int left = 0;
    int mid = 0;
    int right = 0;

    while(mid <= right) {
        if(numbers[mid] == 0) {
            swap(numbers[mid++], numbers[left++]);
        }
        else if(numbers[mid] == 1) {
            mid++;
        }
        else {
            swap(numbers[mid], numbers[right--]);
        }
    }

}

int main()
{
	int size;
    cin >> size;

    vector<int> numbers(100);

    arrayInput(numbers, size);

    // sort012App1(numbers, size);
    sort012App1(numbers, size);

    printArray(numbers, size);

}