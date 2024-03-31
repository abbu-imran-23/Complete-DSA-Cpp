#include<bits/stdc++.h>
using namespace std;

int main()
{
	int num;
	cin >> num;

    int reverseNumber = 0;

	while(num > 0)
    {
        int lastDigit = num % 10;
        reverseNumber = (reverseNumber * 10) + lastDigit;
        num /= 10;
    }
    
    cout << reverseNumber;
    
	return 0;
}