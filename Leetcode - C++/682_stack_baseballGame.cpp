// https://leetcode.com/problems/baseball-game/
// Time - O(N), Space - O(N)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0, score = 0;
        vector<int> rounds;
        for (string op : ops) {
            if (op == "C") {
                sum -= rounds.back();
                rounds.pop_back();
                continue;
            }
            if (op == "D") {
                sum += score = rounds.back() * 2;
            }
            else if (op == "+") {
                sum += score = rounds[rounds.size() - 1] + rounds[rounds.size() - 2];
            }
            else {
                sum += score = stoi(op);
            }
            rounds.push_back(score);
        }
        return sum;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<string> ops = {"5","-2","4","C","D","9","+","+"};
    int points = solution->calPoints(ops);
}