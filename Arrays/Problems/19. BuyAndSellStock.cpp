#include<bits/stdc++.h>
using namespace std;

/* ------------- APPROACHES ------------- 
   1. Using Two loops - [TC - O(n^2)]
   2. Using Single Loop - [TC - O(n)]
*/

void arrayInput(vector<int> &numbers, int size) {
    for(int i=0;i<size;i++) {
        cin >> numbers[i];
    }
}

// Approach 1
int buyAndSellStockTxn1App1(vector<int> nums, int size) {
    int maxProfit = INT_MIN;
    for(int i=0;i<size;i++) {
        int profit = 0;
        for(int j=i+1;j<size;j++) {
            if(nums[j] > nums[i]) {
                profit = nums[j] - nums[i];
                maxProfit = max(maxProfit, profit);
            }
        }
    }
    return maxProfit;
}

// Approach 2
int buyAndSellStockTxn1App2(vector<int> nums, int size) {
    int minimumPrice = nums[0];
    int maximumProfit = 0;
    for(int i=1;i<size;i++) {
        int profit = nums[i] - minimumPrice;
        maximumProfit = max(maximumProfit, profit);
        minimumPrice = min(minimumPrice, nums[i]);
    }
    return maximumProfit;
}

int main()
{
	int size;
    cin >> size;

    vector<int> numbers(100);
    arrayInput(numbers, size);

    int result1 = buyAndSellStockTxn1App1(numbers, size);
    cout << result1 << endl;

    int result2 = buyAndSellStockTxn1App2(numbers, size);
    cout << result2 << endl;

}