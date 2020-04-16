// https://leetcode.com/problems/frog-jump/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

bool canCross(vector<int>& stones) {
    for(int i = 3; i < stones.size(); i++) {
        if(stones[i] > stones[i-1] * 2) {
            return false; 
        }
    }
    
    unordered_set<int> stonePositions; 
    for(int s : stones) 
        stonePositions.insert(s);
    
    int lastStone = stones[stones.size()-1];
    stack<int> positions;
    stack<int> jumps;
    positions.push(0);
    jumps.push(0);
    
    while(!positions.empty()) {
        int position = positions.top();
        positions.pop();
        int jumpDistance = jumps.top();
        jumps.pop();
        
        for(int i = jumpDistance-1; i <= jumpDistance+1; i++) {
            if(i <= 0) continue;
            int nextPosition = i+position;
            if(nextPosition == lastStone) return true;
            else if(stonePositions.find(nextPosition) != stonePositions.end()){
                positions.push(nextPosition);
                jumps.push(i);
            }
        }
    }
    return false; 
}

int main() {
    vector<int> stones = {0,1,3,5,6,8,12,17};
    if(canCross(stones))
        cout << "Can Jump" << endl;
    else cout << "Cannot jump" << endl;
}