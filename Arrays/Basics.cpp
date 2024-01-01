#include<bits/stdc++.h>
using namespace std;

int main() {

    // Declaration
    int numbers[100];

    // Initialization
    int nums[5] = {1, 2, 3, 4, 5};

    int size;
    cin >> size;

    // int values[size]; - Bad Practice
    int values[100]; // Good Practice

    // Store Elements
    for(int i=0;i<size;i++) {
        cin >> values[i];
    }

    // Display Elements
    for(int i=0;i<size;i++) {
        cout << values[i] << " ";
    }

    /*
    Note: Max size of an array - 10^6
    */

}