#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool isAnagram(string s, string t) {
	if(s.size() != t.size()) return false;
	unordered_map<char, int> map;
	for(int i = 0; i < s.size(); i++){
		map[s[i]]++;
		map[t[i]]--;
	}
    for(auto m : map)
        if(m.second) return false; 
    return true;
}

bool isAnagram2(string s, string t) {
	if (s.length() != t.length()) return false;
	int n = s.length();
	int counts[26] = {0};
	for (int i = 0; i < n; i++) { 
		counts[s[i] - 'a']++;
		counts[t[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++)
		if (counts[i]) return false;
	return true;
}

int main() {
	string s = "anagram", t = "naaagrm";
	if(isAnagram(s,t))
		cout << "It is a valid anagram" << endl;
	else cout << "Not, it's not a valid anagram" << endl;
}