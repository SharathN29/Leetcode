// https://leetcode.com/problems/jewels-and-stones/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int numJewelsInStones(string J, string S) {
    unordered_map<char, int> map;
    int count = 0;
    
    for(char& c : S) 
        map[c]++;
    
    for(char& c : J) 
        if(map.find(c) != map.end()) 
            count += map[c];
    
    return count;
}

int main() {
    string J = "aA";
    string S = "aAAbbbb";
    cout << "Common Count : " << numJewelsInStones(J, S) << endl;
}