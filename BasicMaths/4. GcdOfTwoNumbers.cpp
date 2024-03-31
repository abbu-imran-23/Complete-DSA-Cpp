#include<bits/stdc++.h>
using namespace std;

int main()
{
	int num1;
	cin >> num1;

    int num2;
    cin >> num2;

	int n = min(num1, num2);

    // TC - O(min(num1, num2))
    for(int i=n; i>=1; i--) {
        if(num1 % i == 0 && num2 % i == 0) {
            cout << i;
            break;
        }
    } 

    // Eucledian Algorithm
    // gcd(a,b) = gcd(a-b,b) where a > b
    // TC - O(logphi(min(num1, num2)))
    while(num1 > 0 && num2 > 0) {
        if(num1 > num2) num1 = num1 % num2;
        else num2 = num2 % num1;
    }
    if(num1 == 0) {
        cout << endl << num2;
    }
    else {
        cout << endl << num1;
    }

	return 0;
}