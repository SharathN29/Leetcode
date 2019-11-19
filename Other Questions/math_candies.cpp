#include <iostream>
#include <vector>

using namespace std;

vector<int> distributeCandies(int candies, int n) {
    vector<int> res(n);
    for(int i = 0; candies > 0; i++) {
        res[i % n] += min(candies, i+1);
        candies -= i+1;
    }
    return res;
}

int main() {
    int candies = 10;
    int num_people = 3;
    vector<int> res = distributeCandies(candies, num_people);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}