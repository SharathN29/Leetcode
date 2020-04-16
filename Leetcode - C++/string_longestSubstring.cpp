#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int start = -1, maxlen = 0;
    unordered_map<char, int> map;
    for(int i = 0; i < s.size(); i++){
        if(map.count[s[i]] != 0)
            start = max(start, map[s[i]]);
        map[s[i]] = i;
        maxlen = max(maxlen, i-start);
    }
    return maxlen;
}

int main(){
    string s = "abcabcabcd";
    int len = lengthOfLongestSubstring(s);
    cout << "Length of longest substring " << len << endl;  
}