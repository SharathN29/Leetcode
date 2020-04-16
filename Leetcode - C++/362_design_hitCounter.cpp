// https://leetcode.com/problems/design-hit-counter/

#include <iostream>
#include <queue>

class HitCounter {
private:
    queue<pair<int, int>> hits;
    int count;
    
public:
    /** Initialize your data structure here. */
    HitCounter() {
        count = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        while(!hits.empty() && timestamp-hits.front().first >= 300) {
            count -= hits.front().second;
            hits.pop();
        }
        ++count; 
        if(!hits.empty() && timestamp == hits.back().first)
            ++(hits.back().second);
        else hits.push(make_pair(timestamp, 1));
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!hits.empty() && timestamp - hits.front().first >= 300) {
            count -= hits.front().second;
            hits.pop();
        }
        return count; 
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */