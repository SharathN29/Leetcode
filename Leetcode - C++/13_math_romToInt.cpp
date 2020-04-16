// https://leetcode.com/problems/roman-to-integer/
// Time : O(N), SPace : O(N)

#include <iostream>
#include <unordered_map>

using namespace std; 

int romanToInt(string s) {
    unordered_map<char, int> map;
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;

    int res = map[s.at(s.length()-1)];
    for(int i = s.length()-2; i >= 0; i--){
        if(map[s.at(i)] < map[s.at(i+1)])
            res -= map[s.at(i)];
        else res += map[s.at(i)];
    }
    return res;
}

int main() {
    string s = "MCMXCIV";
    int res = romanToInt(s);
    cout << "Result : " << res << endl;
}