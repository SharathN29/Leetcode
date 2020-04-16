// https://leetcode.com/problems/implement-trie-prefix-tree/
// Time - O(N), where N is the length of the string 
// Space - O(M*N*K), where M : num of words, N : length of each word, K : num of characters (for map)

#include <iostream>

using namespace std;

struct TrieNode {
    bool flag;
    map<char, TrieNode*> next;
};

class Trie {
private:
    TrieNode* root; 

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root; 
        for(int i = 0; i < word.length(); i++) {
            if((p->next).count(word[i]) <= 0) {
                (p->next).insert(make_pair(word[i], new TrieNode()));
            }
            p = (p->next)[word[i]];
        }
        p->flag = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.length(); i++) {
            if((p->next).count(word[i]) <= 0) 
                return false; 
            p = (p->next)[word[i]];
        }
        return p->flag; 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(int i = 0; i < prefix.length(); i++) {
            if((p->next).count(prefix[i]) <= 0) 
                return false; 
            p = (p->next)[prefix[i]];
        }
        return true;
    }
};