#include <iostream>

using namespace std; 

bool isIsomorphic(string s, string t) {
    int m1[256] = {}, m2[256] = {}, n= s.size();
    for(int i = 0; i < n; i++) {
        if(m1[s[i]] != m2[t[i]]) return false; 
        m1[s[i]] = i+1;
        m2[t[i]] = i+1;
    }
    return true;
}

int main() {
    string s = "edd";
    string t = "tee";
    if(isIsomorphic(s,t))
        cout << "Isomorphic String" << endl;
    else cout << "Non-isomorphic string" << endl;
}