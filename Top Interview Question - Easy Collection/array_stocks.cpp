#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int min = INT_MAX;
    int max = 0;
    for(int i = 0; i < prices.size(); i++) {
        if(prices[i] < min)
            min = prices[i];
        else 
            max = prices[i] - min > max ? prices[i] - min : max;
    }
    return max;
}

int main() {
    vector<int> prices = {7,6,4,3,1};
    int maxP = maxProfit(prices);
    cout <<"Maximum profit " << maxP << endl;
}