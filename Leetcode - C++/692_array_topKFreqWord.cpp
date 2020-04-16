// https://leetcode.com/problems/top-k-frequent-words/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct compare {
    bool operator() (const pair<int,string>& a, const pair<int,string>& b) const {
        if(a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    }
};

vector<string> topKFrequent(vector<string>& words, int k) {
    vector<string> res;
    unordered_map<string, int> map;

    for(string s : words) {
        map[s]++;
    }

    priority_queue<pair<int, string>, vector<pair<int,string>>, compare> pq;
    for(auto it : map) 
        pq.emplace(it.second, it.first);

    while(k-- > 0 && !pq.empty) {
        res.push_back(pq.top().second);
        pq.pop();
    }
}

int main() {
    vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    int k = 4;
    vector<string> res = topKFrequent(words, k);
    for(string s : res)
        cout << s << " ";
    cout << endl;
}