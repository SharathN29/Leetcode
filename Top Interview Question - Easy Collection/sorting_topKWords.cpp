#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

struct Comp {
    bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs) const {
        if(lhs.first != rhs.first)
            return lhs.first< rhs.first;
        else return lhs.second > rhs.second;
    }
};

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> frequency;
    vector<string> res;
    priority_queue<pair<int, string>, vector<pair<int, string>>, Comp> pq; 

    for(auto word : words)
        frequency[word]++;

    for(auto elem : frequency)
        pq.emplace(elem.second, elem.first);

    while(k-- && !pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}

int main() {
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    vector<string> res = topKFrequent(words, k);
    cout << "The top " << k << " frequent words in the list are "; 
    for(auto word : res)
        cout << word << " ";
    cout << endl;
}
