#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string customSortString(string S, string T) {
    unordered_map<char, int> smap;
    for(int i = 0; i < S.length(); i++) 
        smap[S[i]] = i+1;
    sort(T.begin(), T.end(), [&](char a, char b){return smap[a] < smap[b];});
    return T;
}

int main() {
    string S = "cba";
    string T = "abcd";
    cout << T << " after custom sorting " << customSortString(S, T) << endl;
}