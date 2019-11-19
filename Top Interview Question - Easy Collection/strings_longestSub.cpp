#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    if(s.size() < 2) return s.size();

    int d = 1, maxLen = 1;
    unordered_map<char, int> subs;
    subs[s[0]] = 0;

    for(int i = 0; i < s.size(); i++) {
        if(subs.count(s[i])==0 || subs[s[i]]<i-d)
            d++;
        else 
            d = i - subs[s[i]];

        subs[s[i]] = i;
        if(d > maxLen)
            maxLen = d;
    }
    return maxLen;
}

int main() {
    string s = "abcabcbb";
    int length = lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating character is " << length << endl;
}