// https://leetcode.com/problems/find-the-celebrity/
// Time - O(N)

#include <iostream>

using namespace std;

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if(n <= 1) 
            return n;

        int candidate = 0;
        for(int i = 1; i < n; i++) 
            if(!knows(candidate, i)) 
                candidate = i;
        for(int j = 0; j < n; j++) {
            if(j == candidate) continue;
            if(knows(candidate, j) || !knows(j, candidate)) 
                return -1;
        }
        return candidate;
    }
};

