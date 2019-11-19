#include <iostream>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> romInt = {{'I', 1},
                                       {'V', 5},
                                       {'X', 10},
                                       {'L', 50},
                                       {'C', 100},
                                       {'D', 500},
                                       {'M', 1000}
                                      };

    int result = romInt[s.back()];

    for(int i = s.size()-2; i >= 0; i--){
        if(romInt[s[i]] < romInt[s[i+1]])
            result -= romInt[s[i]];
        else result += romInt[s[i]];
    }
    return result;
}

int main() {
    string s = "MCMXCIV";
    int res = romanToInt(s);
    cout<<"Integer equivalent of the roman number is " << res << endl;
}