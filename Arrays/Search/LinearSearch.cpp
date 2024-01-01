#include<bits/stdc++.h>
using namespace std;

bool linearSearch(int numbers[], int size, int searchElement) {
    for(int i=0; i<size; i++) {
        if(numbers[i] == searchElement) {
            return true;
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

    bool isPresent = linearSearch(numbers, size, searchElement);

    cout << isPresent;

}