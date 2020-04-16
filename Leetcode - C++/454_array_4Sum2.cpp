// https://leetcode.com/problems/4sum-ii/
// Time : O(N^2)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> map;
        for(int a : A) {
            for(int b : B) {
                map[a+b]++;
            }
        }
        int count = 0;
        for(int c : C) {
            for(int d : D) {
                auto it = map.find(0-c-d);
                if(it != map.end()){
                    count += it->second;
                }
            }
        }
        return count;
    }
};

int main() {
    SOlution *sol = new Solution();
    vector<int> A = {1,2}, B = {-2,-1}, C = {-1,2}, D = {0,2};
    int count = sol->fourSumCount(A,B,C,D);
    cout << "Count : " << count << endl;
}