// https://leetcode.com/problems/reorder-data-in-log-files/

#include <iostream>
#include <vector>
#include <string> 

using namespace std;

vector<string> reorderLogFiles(vector<string>& logs) {
    vector<string> digitlogs, ans; 
    vector<pair<string, string>> letterlogs;
    for(string &s : logs) {
        int i = 0;
        while(s[i] != ' ') i++;
        if(isalpha(s[i+1])) 
            letterlogs.emplace_back(s.substr(0,i), s.substr(i+1));
        else digitlogs.push_back(s);
    }

    sort(letterlogs.begin(), letterlogs.end(), [&](auto& a, auto& b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });

    for (auto &p : letterlogs) 
        ans.push_back(p.first + " " + p.second);
    for (string &s : digitlogs) 
        ans.push_back(s);

    return ans;
}

int main() {
    vector<string> logs = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    vector<string> res = reorderLogFiles(logs);
    for(string &s : res) 
        cout << s << endl;
}