// https://leetcode.com/problems/shortest-word-distance/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// This doesn't work if you have repeated elelemnts in the given vector
// int shortestDistance(vector<string>& words, string word1, string word2) {
//     unordered_map<string, int> map;
//     int i = 0;
//     for(string s : words)
//         map[s] = i++;
//     return abs(map.find(word1)->second - map.find(word2)->second);
// }

int shortestDistance(vector<string>& words, string word1, string word2) {
    int pos1 = -1, pos2 = -1, res = words.size();
    for(int i = 0; i < words.size(); i++){
        if(words[i] == word1) pos1 = i;
        else if(words[i] == word2) pos2 = i;
        
        if(pos1 != -1 && pos2 != -1)
            res = min(res, abs(pos1-pos2));
    }
    return res;
}

int main() {
    vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
    string word1 = "practice";
    string word2 = "makes";
    int distance = shortestDistance(words, word1, word2);
    cout << " Distance : " << distance << endl;
}
