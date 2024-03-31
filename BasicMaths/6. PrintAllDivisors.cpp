#include<bits/stdc++.h>
using namespace std;

int main()
{
	int num;
	cin >> num;

	// TC - O(n)
	for(int i=1; i<=num; i++) {
		if(num % i == 0) {
			cout << i << " ";
		}
	}

	cout << endl;

	// TC - O(sqrt(n))
	for(int i=1; i<=sqrt(num); i++) {
		if(num % i == 0) {
			cout << i << " ";
			if((num / i) != i) {
				cout << num/i << " ";
			}
		}
	}

	return 0;

}