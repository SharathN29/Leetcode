// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int res = 0;
    for(int i = 1; i < prices.size(); i++){
        if(prices[i] > prices[i-1])
            res += prices[i] - prices[i-1];
    }
    return res;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    int mp = maxProfit(prices);
    cout << "Max Profit : " << mp << endl;
}