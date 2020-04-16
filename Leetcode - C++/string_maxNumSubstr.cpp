#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

struct compare {
    bool operator() (const pair<int,string>& a, const pair<int,string>& b) const {
        if(a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    }
};

int countUniqueChars(string s) {
    unordered_set<char> unique;
    for(char c : s) {
        unique.insert(c);
    }
    return unique.size();
}

int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    vector<string> subStrings; 
    vector<string> temp;
    unordered_map<string, int> map;
    int count = 0;

    for(int i = 0; i < s.length()-minSize+1; i++) {
        subStrings.push_back(s.substr(i,minSize));
    }

    if(minSize != maxSize) {
        for(int i = 0; i < s.length()-maxSize+1; i++) {
            subStrings.push_back(s.substr(i,maxSize));
        }
    }

    for(int i = 0; i < subStrings.size(); i++) {
        int c = countUniqueChars(subStrings[i]);
        if(c <= maxLetters) {
            temp.push_back(subStrings[i]);
        } else continue;
    }

    for(string s : temp)
        map[s]++;

    priority_queue<pair<int, string>, vector<pair<int,string>>, compare> pq;
    for(auto it : map) 
        pq.emplace(it.second, it.first);
    
    return pq.top().first;
}

int main() {
    string s = "aaaa";
    int maxLetters = 1, minSize = 3, maxSize = 3;

    int res = maxFreq(s, maxLetters, minSize, maxSize);
    cout << res << endl;
}