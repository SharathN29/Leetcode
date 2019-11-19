#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std; 

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> res; 
    for(auto s : strs) {
        string t = s; 
        sort(t.begin(), t.end());
        res[t].push_back(s);
    }

    vector<vector<string>> anagrams;
    for(auto p : res) {
        anagrams.push_back(p.second);
    }
    return anagrams;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(strs);

    cout<<"{"<<endl;
    for(int i = 0; i < res.size(); i++){
        cout<<"{";
        for(int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j] << " ";
        }
        cout<<"}" << endl;
    }
    cout<<"}" << endl;
}