#include<bits/stdc++.h>
using namespace std;

int main()
{
	int num;
	cin >> num;

    int factorsCount = 0;

	// TC - O(n)
	for(int i=1; i<=num; i++) {
		if(num % i == 0) {
			factorsCount++;
		}
	}

    if(factorsCount == 2) {
        cout << "true";
    }
    else {
        cout << "false";
    }

	cout << endl;

	// TC - O(sqrt(n))
    int count = 0;
	for(int i=1; i<=sqrt(num); i++) {
		if(num % i == 0) {
			count++;
			if((num / i) != i) {
				count++;
			}
		}
	}

    if(count == 2) {
        cout << "true";
    }
    else {
        cout << "false";
    }

	return 0;

}