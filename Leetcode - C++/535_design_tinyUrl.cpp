// https://leetcode.com/problems/encode-and-decode-tinyurl/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:

    uint64_t id;
    unordered_map<string, string> table;
    
    Solution() : id(1), table() {}
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        static string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-";
        string shortUrl;
        uint64_t newId = id++;
        
        while(newId)
        {
            shortUrl += charset[newId%64];
            newId >>= 6;
        }
        
        reverse(shortUrl.begin(), shortUrl.end());
        table[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
        return table[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));