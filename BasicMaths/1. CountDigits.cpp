#include<bits/stdc++.h>
using namespace std;

int main()
{
	int num;
	cin >> num;

    int copyNum = num;
    int digitsCount = 0;

	while(num > 0)
    {
        int lastDigit = num % 10;
        digitsCount++;
        cout << lastDigit << " ";
        num /= 10;
    }
    
    cout << endl << digitsCount;

    // using log10
    int count = (int)(log10(copyNum) + 1); // TC - O(log(10)(num))

    cout << endl << count;
    
	return 0;
}