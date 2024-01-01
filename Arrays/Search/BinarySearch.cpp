#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int numbers[], int size, int searchElement) {
    int start = 0;
    int end = size - 1;

    while(start <= end) {
    int mid = start + (end - start)/2;

        if(numbers[mid] == searchElement) {
            return true;
        }

        else if(numbers[mid] < searchElement) {
            start = mid + 1;
        }

        else {
            end = mid - 1;
        }
    }

    return false;

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

    int searchElement;
    cin >> searchElement;

    bool isPresent = binarySearch(numbers, size, searchElement);

    cout << isPresent;

}