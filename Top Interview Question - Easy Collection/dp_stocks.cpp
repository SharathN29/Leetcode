#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices){
    int maxP = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        maxP = max(maxP, prices[i] - minPrice);
    }
    return maxP;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int maxP = maxProfit(prices);
    cout<<"The maximum profile that you could make from these days is " << maxP << endl;
}