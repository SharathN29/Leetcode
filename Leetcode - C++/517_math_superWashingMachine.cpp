// https://leetcode.com/problems/super-washing-machines/
// time - O(N), Space - O(1)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int total = 0, n = machines.size();
        for(int m : machines) 
            total += m;
        if(total % n) return -1; 
        int target = total / n, res = 0, toRight = 0;

        for(int m : machines) {
            toRight = m + toRight - target;
            res = max(res, max(abs(toRight), m-target));
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int>& machines = {1,0,5};
    int minMoves = solution->findMinMoves(machines);
    cout << "Min Movoes : " << minMoves << endl;
}