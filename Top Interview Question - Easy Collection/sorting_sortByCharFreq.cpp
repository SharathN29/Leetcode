#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std; 

string frequencySort(string s) {
    unordered_map<char, int> frequency; 
    priority_queue<pair<int, char>> pq;
    string res; 

    for(auto c : s) 
        frequency[c]++;

    for(auto elem : frequency)
        pq.push(make_pair(elem.second, elem.first));

    while(!pq.empty()) {
        int topCount = pq.top().first;
        while(topCount--)
            res += pq.top().second;
        pq.pop();
    }
    return res;
}

int main() {
    string s = "cccaaa";
    cout << "Original string after sorting based on frequency " << frequencySort(s) << endl;
}