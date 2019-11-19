// First Unique Character in a String

// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

// Examples:

// s = "leetcode"
// return 0.

// s = "loveleetcode",
// return 2.
// Note: You may assume the string contain only lowercase letters.

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s){
    unordered_map<char, int> umap;
    int size = s.size();

    for(int i = 0; i < size; i++)
        umap[s[i]]++;
    
    for(int j = 0; j < size; j++)
        if(umap[s[j]] == 1)
            return j;
    return -1;
}

int main(){
    string  s = "loveleetcode";
    int res = firstUniqChar(s);

    cout<<"Index of first unique character " << res << endl;
}