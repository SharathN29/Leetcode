// https://leetcode.com/problems/group-anagrams/
// Time : O(NK), Space : O(NK)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private: 
    string strSort(string s) {
        int character[26] = {0};
        for(char& c: s) {
            character[c-'a']++;
        }
        string t;
        for(int c = 0; c < 26; c++) {
                t += string(character[c], c + 'a');
        }
        return t;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(string s : strs) {
            map[strSort(s)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for(auto& it : map) 
            anagrams.push_back(it.second);
        return anagrams;
    }
};

// vector<vector<string>> groupAnagrams(vector<string>& strs) {
//     vector<vector<string>> res;
//     unordered_map<string, vector<string>> map;

//     for(string s : strs) {
//     	string t = s;
//     	sort(t.begin(), t.end());
//     	map[t].push_back(s);
//     }

//     for(auto it : map) {
//     	res.push_back(it.second);
//     }
//     return res;
// }

int main() {
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
}