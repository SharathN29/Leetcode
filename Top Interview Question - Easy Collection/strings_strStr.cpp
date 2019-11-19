// Implement strStr()

// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
// Clarification:

// What should we return when needle is an empty string? This is a great question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

#include <iostream>
#include <vector>

using namespace std;

vector<int> kmpProcess(string needle) {
    int n = needle.size();
    vector<int> lps(n, 0);
    for (int i = 1, len = 0; i < n;) {
        if (needle[i] == needle[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

int strStr(string haystack, string needle) {
    int m = haystack.size(), n = needle.size();
    if (!n) {
        return 0;
    }
    vector<int> lps = kmpProcess(needle);
    for (int i = 0, j = 0; i < m;) {
        if (haystack[i] == needle[j]) { 
            i++, j++;
        }
        if (j == n) {
            return i - j;
        }
        if (i < m && haystack[i] != needle[j]) {
            j ? j = lps[j - 1] : i++;
        }
    }
    return -1;
}

int main() {
    string haystack = "hello";
    string needle = "ll";

    cout<<"The first occurence of needle in haystack is at index " << strStr(haystack, needle) << endl;
}