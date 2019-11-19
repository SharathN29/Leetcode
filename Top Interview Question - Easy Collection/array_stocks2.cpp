#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int res = 0;

    if(prices.size() == 0) return 0;
    
    for(int i = 0; i < prices.size()-1; i++){
        if(prices[i+1] > prices[i]){
            res += prices[i+1] - prices[i];
        }
    }
    return res;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    int res = maxProfit(prices);
    cout<< "Max profit " << res << endl; 
}