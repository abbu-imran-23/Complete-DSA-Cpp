#include<bits/stdc++.h>
using namespace std;

int main()
{
	int num;
	cin >> num;

    int copyNum = num;
    int reverseNumber = 0;

	while(num > 0)
    {
        int lastDigit = num % 10;
        reverseNumber = (reverseNumber * 10) + lastDigit;
        num /= 10;
    }
    
    cout << reverseNumber;

    if(copyNum == reverseNumber) {
        cout << endl << "true";
    }
    else {
        cout << endl << "false";
    }
    
	return 0;
}