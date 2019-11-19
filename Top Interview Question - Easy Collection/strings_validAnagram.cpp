// Valid Anagram

// Given two strings s and t , write a function to determine if t is an anagram of s.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
// Note:
// You may assume the string contains only lowercase alphabets.

// Follow up:
// What if the inputs contain unicode characters? How would you adapt your solution to such case?

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false; 
    unordered_map<char, int> umap;
    for(int i = 0; i < s.length(); i++){
        umap[s[i]]++;
        umap[t[i]]--;
    }

    for(auto m: umap){
        if(m.second) return false;
    }
    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";

    if(isAnagram(s,t))
        cout<<"The two words are anagram" << endl;
    else
        cout<<"Not an anagram" << endl;
}