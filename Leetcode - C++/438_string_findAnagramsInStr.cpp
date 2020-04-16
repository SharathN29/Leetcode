// https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length() == 0 || s == "") 
			return vector<int>();
		vector<int> res; 
		vector<int> charCount(26,0);
		
		for(char c : p) 
			charCount[c-'a']++;
		
		int left = 0, right = 0, count = p.length();
		while(right < s.length()) {
			if(charCount[s[right++]-'a']-- >= 1) count--;
			if(count == 0) res.push_back(left);
			if(left-right == p.length() && charCount[s[left++]-'a'] >=0) count++;
		}
		return res;
    }
};

int main() {
	Solution *sol = new Solution();
	string s = "cbaebabacd", p = "abc";
	vector<int> res = sol->findAnagrams(s, p);
	for(int n : res) 
		cout << n << " ";
	cout << endl;
}