// https://leetcode.com/contest/weekly-contest-172/problems/print-words-vertically/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> printVertically(string s) {
        istringstream in(s);
        string str;
        vector<string> strings;

        while (in >> str)
            strings.push_back(str);

        int rows = 0, cols = strings.size();

        for (string str : strings)
            rows = max(rows, (int) str.size());

        vector<string> answer(rows, string(cols, ' '));

        for (int i = 0; i < (int) strings.size(); i++)
            for (int j = 0; j < (int) strings[i].size(); j++)
                answer[j][i] = strings[i][j];

        for (string &row : answer)
            while (!row.empty() && row.back() == ' ')
                row.pop_back();

        return answer;
    }
};

int main() {
    Solution *sol = new Solution();
    string s = "HOW ARE YOU";
    vector<string> res = sol->printVertically(s);
    for(string s : res) 
        cout << s << " ";
    cout << endl;
}
