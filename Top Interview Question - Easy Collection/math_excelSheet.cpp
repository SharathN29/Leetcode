#include <iostream>

using namespace std;

int titleToNumber(string s) {
    long int colNum = 0;
    for(int i = 0; i < s.size(); ++i)
        colNum = (colNum * 26) + s[i] - 'A' + 1; 
    return colNum;
}

int main() {
    string s = "ZY";
    int res = titleToNumber(s);
    cout << "Column number in excel sheet " << res << endl;
}