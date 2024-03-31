#include<bits/stdc++.h>
using namespace std;

int main()
{
	int num;
	cin >> num;

    int copyNum = num;
    int sum = 0;

	while(num > 0)
    {
        int lastDigit = num % 10;
        sum += (lastDigit * lastDigit * lastDigit);
        num /= 10;
    }

    cout << sum;

    if(copyNum == sum) {
        cout << endl << "true";
    }
    else {
        cout << endl << "false";
    }
    
	return 0;
}